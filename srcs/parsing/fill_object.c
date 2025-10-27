/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:54:12 by cviel             #+#    #+#             */
/*   Updated: 2025/10/27 22:19:43 by cviel            ###   ########.fr       */
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

int	fill_object_info(char **line_split, t_scene *ptr_scene, uint8_t *ptr_check)
{
	int		ret;
	t_bvh	*node;

	node = malloc(sizeof(t_bvh));
	if (node == NULL)
		return (ERROR_MALLOC);
	ret = call_match(line_split, ptr_scene, g_table_obj, ptr_check);
	if (ret != SUCCESS || *ptr_check == FALSE)
		return (ret);
	bvh_add(&ptr_scene->root, node);
	return (SUCCESS);
}

int fill_plane_info(char **line_split, t_obj *ptr_obj)
{
	int	ret;
	int	i;

	i = 1;
	ret = get_coordinates(line_split, &ptr_obj->shape.plane.origin);
	if (ret != SUCCESS)
		return (ret);
	++i;
	ret = get_norm_vect(line_split, &ptr_obj->shape.plane.normal);
	if (ret != SUCCESS)
		return (ret);
	++i;
	ret = get_color(line_split, &ptr_obj->color);
	if (ret != SUCCESS)
		return (ret);
	++i;
	if (line_split[i] != NULL)
		return (INVALID_FILE);
	return (SUCCESS);
}

int fill_sphere_info(char **line_split, t_obj *ptr_obj)
{
	int	ret;
	int	i;

	i = 1;
	ret = get_coordinates(line_split, &ptr_obj->shape.sphere.center);
	if (ret != SUCCESS)
		return (ret);
	i++;
	ret = get_float(line_split, &ptr_obj->shape.sphere.radius);
	if (ret != SUCCESS)
		return (ret);
	if (ptr_obj->shape.sphere.radius < 0)
		return (INVALID_FILE);
	ptr_obj->shape.sphere.radius /= 2;
	i++;
	ret = get_color(line_split, &ptr_obj->color);
	if (ret != SUCCESS)
		return (ret);
	i++;
	if (line_split[i] != NULL)
		return (INVALID_FILE);
	return (SUCCESS);
}

int fill_cylinder_info(char **line_split, t_obj *ptr_obj)
{
	int	ret;
	int	i;

	i = 1;
	ret = get_coordinates(line_split, &ptr_obj->shape.cyl.origin);
	if (ret != SUCCESS)
		return (ret);
	i++;
	ret = get_norm_vect(line_split, &ptr_obj->shape.cyl.normal);
	if (ret != SUCCESS)
		return (ret);
	i++;
	ret = get_float(line_split, &ptr_obj->shape.cyl.radius);
	if (ret != SUCCESS)
		return (ret);
	if (ptr_obj->shape.sphere.radius < 0)
		return (INVALID_FILE);
	ptr_obj->shape.cyl.radius /= 2;
	ret = get_float(line_split, &ptr_obj->shape.cyl.height);
	if (ret != SUCCESS)
		return (ret);
	if (ptr_obj->shape.cyl.height < 0)
		return (INVALID_FILE);
	++i;
	ret = get_color(line_split, &ptr_obj->color);
	if (ret != SUCCESS)
		return (ret);
	i++;
	if (line_split[i] != NULL)
		return (INVALID_FILE);
	return (SUCCESS);
}
