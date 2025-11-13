/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:34:01 by cviel             #+#    #+#             */
/*   Updated: 2025/11/13 13:39:55 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ret_val.h"
#include "scene.h"
#include "libft.h"
#include "parsing.h"

int	fill_ambient_info(char **line_split, t_scene *ptr_scene)
{
	int	ret;
	int	i;
	char	*endl;

	endl = NULL;
	if (ptr_scene->amb.lightning != -1)
		return (INVALID_FILE);
	i = 0;
	ptr_scene->amb.lightning = ft_strtod(line_split[i], &endl);
	if (*endl || ptr_scene->amb.lightning < 0 || ptr_scene->amb.lightning > 1)
		return (INVALID_FILE);
	++i;
	ret = get_color(line_split[i], &ptr_scene->amb.color);
	if (ret != SUCCESS)
		return (ret);
	++i;
	if (line_split[i] != NULL)
		return (INVALID_FILE);
	return (SUCCESS);
}

int	fill_camera_info(char **line_split, t_scene *ptr_scene)
{
	int	ret;
	int	i;
	char	*endl;

	endl = NULL;
	if (ptr_scene->cam.fov != -1)
		return (INVALID_FILE);
	i = 0;
	ret = get_coordinates(line_split[i], &ptr_scene->cam.pos);
	if (ret != SUCCESS)
		return (ret);
	++i;
	ret = get_norm_vect3(line_split[i], &ptr_scene->cam.dir);
	if (ret != SUCCESS)
		return (ret);
	++i;
	ptr_scene->cam.fov = ft_strtoi(line_split[i], &endl);
	if (*endl || ptr_scene->cam.fov < 0 || ptr_scene->cam.fov > 180)
		return (INVALID_FILE);
	++i;
	if (line_split[i] != NULL)
		return (INVALID_FILE);
	return (SUCCESS);
}

int	fill_light_info(char **line_split, t_scene *ptr_scene)
{
	int	ret;
	int	i;
	char	*endl;

	endl = NULL;
	if (ptr_scene->light.brightness != -1)
		return (INVALID_FILE);
	i = 0;
	ret = get_coordinates(line_split[i], &ptr_scene->light.pos);
	if (ret != SUCCESS)
		return (ret);
	++i;
	ptr_scene->light.brightness = ft_strtod(line_split[i], &endl);
	if (*endl || ptr_scene->light.brightness < 0 || ptr_scene->light.brightness > 1)
		return (INVALID_FILE);
	++i;
	ret = get_color(line_split[i], &ptr_scene->light.color);
	if (ret != SUCCESS)
		return (ret);
	++i;
	if (line_split[i] != NULL)
		return (INVALID_FILE);
	return (SUCCESS);
}
