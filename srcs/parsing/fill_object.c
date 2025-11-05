/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:54:12 by cviel             #+#    #+#             */
/*   Updated: 2025/11/05 17:39:09 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <stdlib.h>
#include "libft.h"
#include "ret_val.h"
#include "objects.h"
#include "bvh.h"
#include "scene.h"
#include "parsing.h"

void	print_bvh(t_bvh *root, int depth);

int	fill_object_info(char **line_split, t_scene *ptr_scene, uint8_t *ptr_check)
{
	int		ret;
	t_bvh	*node;

	node = malloc(sizeof(t_bvh));
	if (node == NULL)
		return (ERROR_MALLOC);
	if (ft_strncmp(line_split[0], "sp", ft_strlen(line_split[0])) == 0)
	{
		*ptr_check = TRUE;
		ret = fill_sphere_info(line_split + 1, &node->obj);
	}
	else if (ft_strncmp(line_split[0], "cy", ft_strlen(line_split[0])) == 0)
	{
		*ptr_check = TRUE;
		ret = fill_cylinder_info(line_split + 1, &node->obj);
	}
	else if (ft_strncmp(line_split[0], "pl", ft_strlen(line_split[0])) == 0)
	{
		*ptr_check = TRUE;
		ret = fill_plane_info(line_split + 1, &node->obj);
	}
	if (*ptr_check == TRUE)
	{
		if (ret != SUCCESS)
		{
			free(node);
			return (ret);
		}
		ret = bvh_add(&ptr_scene->root, node);
		if (ret != SUCCESS)
		{
			free(node);
			return (ret);
		}
	}
	return (SUCCESS);
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
	int	ret;
	int	i;

	ptr_obj->type = SPHERE;
	i = 0;
	ret = get_coordinates(line_split[i], &ptr_obj->shape.sphere.center);
	if (ret != SUCCESS)
		return (ret);
	++i;
	ret = get_double(line_split[i], &ptr_obj->shape.sphere.radius);
	if (ret != SUCCESS)
		return (ret);
	if (ptr_obj->shape.sphere.radius < 0)
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
	ret = get_double(line_split[i], &ptr_obj->shape.cyl.radius);
	if (ret != SUCCESS)
		return (ret);
	if (ptr_obj->shape.sphere.radius < 0)
		return (INVALID_FILE);
	ptr_obj->shape.cyl.radius /= 2;
	++i;
	ret = get_double(line_split[i], &ptr_obj->shape.cyl.height);
	if (ret != SUCCESS)
		return (ret);
	if (ptr_obj->shape.cyl.height < 0)
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
