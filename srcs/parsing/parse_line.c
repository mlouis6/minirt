/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:08:11 by cviel             #+#    #+#             */
/*   Updated: 2026/01/12 20:05:30 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "scene.h"
#include "objects.h"
#include "ret_val.h"
#include "parser.h"

static int	fill_scene_info(char **line_split, t_scene *ptr_scene);
static int	fill_object_info(char **line_split, t_scene *ptr_scene);
static int	fill_item(char **line_split, void *ptr_item,
				const t_parser parser[], size_t parser_size);

int	parse_line(char *line, t_scene *ptr_scene)
{
	int		ret;
	char	**line_split;

	line_split = split_line(line, WHITE_SPACES);
	if (line_split == NULL)
		return (ERROR_MALLOC);
	ret = SUCCESS;
	if (*line_split != NULL)
	{
		ret = fill_scene_info(line_split, ptr_scene);
		if (ret == -1)
		{
			ret = fill_object_info(line_split, ptr_scene);
		}
	}
	free_split(line_split);
	return (ret);
}

static int	fill_scene_info(char **line_split, t_scene *ptr_scene)
{
	int		ret;

	ret = -1;
	if (!line_split[0])
		return (ret);
	if (ft_strcmp(line_split[0], "A") == 0 && ptr_scene->amb.lightning == -1)
		ret = fill_item(line_split + 1,
				&ptr_scene->amb, g_amb_parser, NB_INFO_AMB);
	else if (ft_strcmp(line_split[0], "C") == 0 && ptr_scene->cam.fov == -1)
		ret = fill_item(line_split + 1,
				&ptr_scene->cam, g_cam_parser, NB_INFO_CAM);
	else if (ft_strcmp(line_split[0], "L") == 0
		&& ptr_scene->light.brightness == -1)
		ret = fill_item(line_split + 1,
				&ptr_scene->light, g_light_parser, NB_INFO_LIGHT);
	return (ret);
}

static int	choose_object(char **line_split, t_obj *ptr_obj)
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

static int	fill_object_info(char **line_split, t_scene *ptr_scene)
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

static int	fill_item(char **line_split, void *ptr_item,
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
