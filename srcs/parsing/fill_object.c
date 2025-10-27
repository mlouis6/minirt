/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:54:12 by cviel             #+#    #+#             */
/*   Updated: 2025/10/24 22:14:31 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ret_val.h"
#include "objects.h"
#include "bvh.h"
#include "scene.h"

int	fill_object_info(char *line, t_scene *ptr_scene, t_type type)
{
	int		ret;
	t_bvh	*node;
	int		i;

	node = malloc(sizeof(t_bvh));
	if (node == NULL)
		return (ERROR_MALLOC);
	node->obj.type = type;
	i = 0;
	while (ft_strchr(WHITE_SPACES, line[i]) != NULL)
		i++;
	if (type == PLANE)
		ret = fill_plane_info(&line[i], &node->obj);
	else if (type == SPHERE)
		ret = fill_sphere_info(&line[i], &node->obj);
	else if (type == CYLINDER)
		ret = fill_cylinder_info(&line[i], &node->obj);
	else
		return (INVALID_FILE);
	if (ret != SUCCESS)
		return (ret);
	bvh_add(&ptr_scene->root, node);
	return (SUCCESS);
}

int fill_plane_info(char *line, t_obj *ptr_obj)
{
	int	ret;
	int	i;

	i = 0;
	while (ft_strchr(WHITE_SPACES, line[i]) == NULL)
		i++;
	ret = get_coordinates(line, &i, &ptr_obj->shape.plane.origin);
	if (ret != SUCCESS)
		return (ret);
	while (ft_strchr(WHITE_SPACES, line[i]) == NULL)
		i++;
	ret = get_norm_vect(line, &i, &ptr_obj->shape.plane.normal);
	if (ret != SUCCESS)
		return (ret);
	while (ft_strchr(WHITE_SPACES, line[i]) == NULL)
		i++;
	ret = get_color(line, &i, &ptr_obj->color);
	if (ret != SUCCESS)
		return (ret);
	while (ft_strchr(WHITE_SPACES, line[i]) == NULL)
		i++;
	if (line[i] != '\0')
		return (INVALID_FILE);
	return (SUCCESS);
}

int fill_sphere_info(char *line, t_obj *ptr_obj)
{
	int	ret;
	int	i;

	i = 0;
	while (ft_strchr(WHITE_SPACES, line[i]) == NULL)
		i++;
	ret = get_coordinates(line, &i, &ptr_obj->shape.sphere.center);
	if (ret != SUCCESS)
		return (ret);
	while (ft_strchr(WHITE_SPACES, line[i]) == NULL)
		i++;
	ret = get_float(line, &i, &ptr_obj->shape.sphere.radius);
	if (ret != SUCCESS)
		return (ret);
	if (ptr_obj->shape.sphere.radius < 0)
		return (INVALID_FILE);
	ptr_obj->shape.sphere.radius /= 2;
	while (ft_strchr(WHITE_SPACES, line[i]) == NULL)
		i++;
	ret = get_color(line, &i, &ptr_obj->color);
	if (ret != SUCCESS)
		return (ret);
	while (ft_strchr(WHITE_SPACES, line[i]) == NULL)
		i++;
	if (line[i] != '\0')
		return (INVALID_FILE);
	return (SUCCESS);
}

int fill_cylinder_info(char *line, t_obj *ptr_obj)
{
	int	ret;
	int	i;

	i = 0;
	while (ft_strchr(WHITE_SPACES, line[i]) == NULL)
		i++;
	ret = get_coordinates(line, &i, &ptr_obj->shape.cyl.origin);
	if (ret != SUCCESS)
		return (ret);
	while (ft_strchr(WHITE_SPACES, line[i]) == NULL)
		i++;
	ret = get_norm_vect(line, &i, &ptr_obj->shape.cyl.normal);
	if (ret != SUCCESS)
		return (ret);
	while (ft_strchr(WHITE_SPACES, line[i]) == NULL)
		i++;
	ret = get_float(line, &i, &ptr_obj->shape.cyl.radius);
	if (ret != SUCCESS)
		return (ret);
	if (ptr_obj->shape.sphere.radius < 0)
		return (INVALID_FILE);
	ptr_obj->shape.cyl.radius /= 2;
	ret = get_float(line, &i, &ptr_obj->shape.cyl.height);
	if (ret != SUCCESS)
		return (ret);
	if (ptr_obj->shape.cyl.height < 0)
		return (INVALID_FILE);
	ret = get_color(line, &i, &ptr_obj->color);
	if (ret != SUCCESS)
		return (ret);
	while (ft_strchr(WHITE_SPACES, line[i]) == NULL)
		i++;
	if (line[i] != '\0')
		return (INVALID_FILE);
	return (SUCCESS);
}
