/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:08:11 by cviel             #+#    #+#             */
/*   Updated: 2026/01/08 18:16:05 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "parsing.h"
#include "scene.h"
#include "objects.h"
#include "ret_val.h"

static const t_parser	g_amb_parser[] = {
{&get_intensity, offsetof(t_ambient, lightning)},
{&get_color, offsetof(t_ambient, color)}};

static const t_parser	g_cam_parser[] = {
{&get_coordinates, offsetof(t_camera, pos)},
{&get_norm_vect3, offsetof(t_camera, dir)},
{&get_fov, offsetof(t_camera, fov)}};

static const t_parser	g_light_parser[] = {
{&get_coordinates, offsetof(t_light, pos)},
{&get_intensity, offsetof(t_light, brightness)},
{&get_color, offsetof(t_light, color)}};

static const t_parser	g_sph_parser[] = {
{&get_coordinates, offsetof(t_obj, shape) + offsetof(t_shape, sphere)
	+ offsetof(t_sph, center)},
{&get_radius, offsetof(t_obj, shape) + offsetof(t_shape, sphere)
	+ offsetof(t_sph, radius)},
{&get_color, offsetof(t_obj, color)}};

static const t_parser	g_pl_parser[] = {
{&get_coordinates, offsetof(t_obj, shape) + offsetof(t_shape, plane)
	+ offsetof(t_plane, origin)},
{&get_norm_vect3, offsetof(t_obj, shape) + offsetof(t_shape, plane)
	+ offsetof(t_plane, normal)},
{&get_color, offsetof(t_obj, color)}};

static const t_parser	g_cyl_parser[] = {
{&get_coordinates, offsetof(t_obj, shape) + offsetof(t_shape, cyl)
	+ offsetof(t_cyl, origin)},
{&get_norm_vect3, offsetof(t_obj, shape) + offsetof(t_shape, cyl)
	+ offsetof(t_cyl, normal)},
{&get_radius, offsetof(t_obj, shape) + offsetof(t_shape, cyl)
	+ offsetof(t_cyl, radius)},
{&get_dist, offsetof(t_obj, shape) + offsetof(t_shape, cyl)
	+ offsetof(t_cyl, height)},
{&get_color, offsetof(t_obj, color)}};

int	fill_scene_info(char **line_split, t_scene *ptr_scene);
int	fill_object_info(char **line_split, t_scene *ptr_scene);
int	fill_item(char **line_split, void *ptr_item,
		const t_parser parser[], size_t parser_size);

int	parse_line(char *line, t_scene *ptr_scene)
{
	int		ret;
	char	**line_split;

	line_split = split_line(line, WHITE_SPACES);
	if (line_split == NULL)
		return (ERROR_MALLOC);
	ret = fill_scene_info(line_split, ptr_scene);
	if (ret == -1)
	{
		ret = fill_object_info(line_split, ptr_scene);
	}
	free_split(line_split);
	return (ret);
}

int	fill_scene_info(char **line_split, t_scene *ptr_scene)
{
	int		ret;

	ret = -1;
	if (!line_split[0])
		return (ret);
	if (ft_strcmp(line_split[0], "A") == 0)
		ret = fill_item(line_split + 1,
				&ptr_scene->amb, g_amb_parser, NB_INFO_AMB);
	else if (ft_strcmp(line_split[0], "C") == 0)
		ret = fill_item(line_split + 1,
				&ptr_scene->cam, g_cam_parser, NB_INFO_CAM);
	else if (ft_strcmp(line_split[0], "L") == 0)
		ret = fill_item(line_split + 1,
				&ptr_scene->light, g_light_parser, NB_INFO_LIGHT);
	return (ret);
}

int	choose_object(char **line_split, t_obj *ptr_obj)
{
	int	ret;

	ret = INVALID_FILE;
	if (ft_strcmp(line_split[0], "sp") == 0)
	{
		ptr_obj->type = SPHERE;
		ret = fill_item(line_split + 1, ptr_obj, g_sph_parser, NB_INFO_SPH);
	}
	else if (ft_strcmp(line_split[0], "cy") == 0)
	{
		ptr_obj->type = CYLINDER;
		ret = fill_item(line_split + 1, ptr_obj, g_cyl_parser, NB_INFO_CYL);
	}
	else if (ft_strcmp(line_split[0], "pl") == 0)
	{
		ptr_obj->type = PLANE;
		ret = fill_item(line_split + 1, ptr_obj, g_pl_parser, NB_INFO_PL);
	}
	return (ret);
}

int	fill_object_info(char **line_split, t_scene *ptr_scene)
{
	int		ret;
	t_obj	obj;

	ret = SUCCESS;
	if (!line_split[0])
		return (ret);
	ret = choose_object(line_split, &obj);
	if (ret != SUCCESS)
		return (INVALID_FILE);
	ret = ft_vector_add_single(&ptr_scene->obj[obj.type], &obj);
	if (ret != SUCCESS)
		return (ERROR_MALLOC);
	return (ret);
}

int	fill_item(char **line_split, void *ptr_item,
	const t_parser parser[], size_t parser_size)
{
	int		ret;
	size_t	i;
	void	*curr_field;

	i = 0;
	while (i < parser_size)
	{
		if (line_split[i] == NULL)
			return (INVALID_FILE);
		curr_field = (unsigned char *)ptr_item + parser[i].offset;
		ret = parser[i].getter(line_split[i], curr_field);
		if (ret != SUCCESS)
			return (ret);
		++i;
	}
	if (line_split[i] != NULL)
		return (INVALID_FILE);
	return (SUCCESS);
}
