/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:34:01 by cviel             #+#    #+#             */
/*   Updated: 2025/10/24 18:31:21 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ret_val.h"
#include "scene.h"

int	fill_ambient_info(char *line, t_scene *ptr_scene)
{
	int	ret;
	int	i;
	
	if (ptr_scene->amb.lightning != -1)
		return (INVALID_FILE);
	i = 0;
	while (ft_strchr(WHITE_SPACES, line[i]) != NULL)
		i++;
	ret = get_float(line, &i, &ptr_scene->amb.lightning);
	if (ret != SUCCESS)
		return (ret);
	if (ptr_scene->amb.lightning < 0 || ptr_scene->amb.lightning > 1)
		return (INVALID_FILE);
	while (ft_strchr(WHITE_SPACES, line[i]) != NULL)
		i++;
	ret = get_color(line, &i, &ptr_scene->amb.color);
	if (ret != SUCCESS)
		return (ret);
	while (ft_strchr(WHITE_SPACES, line[i]) != NULL)
		i++;
	if (line[i] != '\0')
		return (INVALID_FILE);
	return (SUCCESS);
}

int	fill_camera_info(char *line, t_scene *ptr_scene)
{
	int	ret;
	int	i;
	
	if (ptr_scene->cam.fov != -1)
		return (INVALID_FILE);
	i = 0;
	while (ft_strchr(WHITE_SPACES, line[i]) != NULL)
		i++;
	ret = get_coordinates(line, &i, &ptr_scene->cam.pos);
	if (ret != SUCCESS)
		return (ret);
	while (ft_strchr(WHITE_SPACES, line[i]) != NULL)
		i++;
	ret = get_norm_vect(line, &i, &ptr_scene->cam.dir);
	if (ret != SUCCESS);
	while (ft_strchr(WHITE_SPACES, line[i]) != NULL)
		i++;
	ret = get_integer(line, &i, &ptr_scene->cam.fov);
	if (ret != SUCCESS)
		return (ret);
	if (ptr_scene->cam.fov < 0 || ptr_scene->cam.fov > 180)
		return (INVALID_FILE);
	while (ft_strchr(WHITE_SPACES, line[i]) != NULL)
		i++;
	if (line[i] != '\0')
		return (INVALID_FILE);
	return (SUCCESS);
}

int	fill_light_info(char *line, t_scene *ptr_scene)
{
	int	ret;
	int	i;

	if (ptr_scene->light.brightness != -1)
		return (INVALID_FILE);
	i = 0;
	while (ft_strchr(WHITE_SPACES, line[i]) != NULL)
		i++;
	ret = get_coordinates(line, &i, ptr_scene->light.pos);
	if (ret != SUCCESS)
		return (ret);
	ret = get_float(line, &i, &ptr_scene->light.brightness);
	if (ret != SUCCESS)
		return (ret);
	if (ptr_scene->light.brightness < 0 || ptr_scene->light.brightness > 1)
		return (INVALID_FILE);
	ret = get_color(line, &i, &ptr_scene->light.color);
	if (ret != SUCCESS)
		return (ret);
	while (ft_strchr(WHITE_SPACES, line[i]) != NULL)
		i++;
	if (line[i] != '\0')
		return (INVALID_FILE);
	return (SUCCESS);
}
