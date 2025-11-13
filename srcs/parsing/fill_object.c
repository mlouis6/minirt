/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:54:12 by cviel             #+#    #+#             */
/*   Updated: 2025/11/13 15:58:58 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "ret_val.h"
#include "objects.h"
#include "bvh.h"
#include "scene.h"
#include "parsing.h"

int	fill_object_info(char **line_split, t_scene *ptr_scene)
{
	int		ret;
	t_bvh	*node;

	ret = -1;
	if (!line_split[0])
		return (ret);
	node = malloc(sizeof(t_bvh));
	if (node == NULL)
		return (ERROR_MALLOC);
	if (ft_strncmp(line_split[0], "sp", ft_strlen(line_split[0])) == 0)
		ret = fill_sphere_info(line_split + 1, &node->obj);
	else if (ft_strncmp(line_split[0], "cy", ft_strlen(line_split[0])) == 0)
		ret = fill_cylinder_info(line_split + 1, &node->obj);
	else if (ft_strncmp(line_split[0], "pl", ft_strlen(line_split[0])) == 0)
		ret = fill_plane_info(line_split + 1, &node->obj);
	if (ret != SUCCESS)
	{
		free(node);
		return (ret);
	}
	if (node->obj.type <= NB_FINITE)
		ret = bvh_add(&ptr_scene->root, node);
	else
	{
		ret = ft_vector_add_single(
			&ptr_scene->inf_obj[node->obj.type - (NB_FINITE +1)], &node->obj);
	}
	if (ret != SUCCESS)
		free(node);
	return (ret);
}

int	fill_plane_info(char **line_split, t_obj *ptr_obj)
{
	int	ret;
	int	i;

	ptr_obj->type = PLANE;
	i = 0;
	ret = get_coordinates(line_split[i], &ptr_obj->shape.plane.origin);
	if (ret != SUCCESS)
		return (ret);
	++i;
	ret = get_norm_vect3(line_split[i], &ptr_obj->shape.plane.normal);
	if (ret != SUCCESS)
		return (ret);
	++i;
	ret = get_color(line_split[i], &ptr_obj->color);
	if (ret != SUCCESS)
		return (ret);
	++i;
	if (line_split[i] != NULL)
		return (INVALID_FILE);
	return (SUCCESS);
}

int	fill_sphere_info(char **line_split, t_obj *ptr_obj)
{
	int		ret;
	int		i;
	char	*endl;

	endl = NULL;
	ptr_obj->type = SPHERE;
	i = 0;
	ret = get_coordinates(line_split[i], &ptr_obj->shape.sphere.center);
	if (ret != SUCCESS)
		return (ret);
	++i;
	ptr_obj->shape.sphere.radius = ft_strtod(line_split[i], &endl);
	if (*endl || ptr_obj->shape.sphere.radius < 0)
		return (INVALID_FILE);
	ptr_obj->shape.sphere.radius /= 2;
	++i;
	ret = get_color(line_split[i], &ptr_obj->color);
	if (ret != SUCCESS)
		return (ret);
	++i;
	if (line_split[i] != NULL)
		return (INVALID_FILE);
	return (SUCCESS);
}

int	fill_cylinder_info(char **line_split, t_obj *ptr_obj)
{
	int	ret;
	int	i;
	char	*endl;

	endl = NULL;
	ptr_obj->type = CYLINDER;
	i = 0;
	ret = get_coordinates(line_split[i], &ptr_obj->shape.cyl.origin);
	if (ret != SUCCESS)
		return (ret);
	++i;
	ret = get_norm_vect3(line_split[i], &ptr_obj->shape.cyl.normal);
	if (ret != SUCCESS)
		return (ret);
	++i;
	ptr_obj->shape.cyl.radius = ft_strtod(line_split[i], &endl);
	if (*endl || ptr_obj->shape.sphere.radius < 0)
		return (INVALID_FILE);
	ptr_obj->shape.cyl.radius /= 2;
	++i;
	ptr_obj->shape.cyl.height = ft_strtod(line_split[i], &endl);
	if (*endl || ptr_obj->shape.cyl.height < 0)
		return (INVALID_FILE);
	++i;
	ret = get_color(line_split[i], &ptr_obj->color);
	if (ret != SUCCESS)
		return (ret);
	++i;
	if (line_split[i] != NULL)
		return (INVALID_FILE);
	return (SUCCESS);
}
