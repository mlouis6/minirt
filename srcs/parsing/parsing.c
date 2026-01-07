/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:20:46 by cviel             #+#    #+#             */
/*   Updated: 2026/01/07 22:52:10 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"
#include "ret_val.h"
#include "scene.h"
#include "parsing.h"
#include "ft_vector.h"

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

int		check_extension(int ac, char **av);
int		get_scene(int fd, t_scene *ptr_scene);
void	print_scene(t_scene scene);

int	parsing(int ac, char **av, t_scene *ptr_scene)
{
	int	ret;
	int	fd;

	ret = check_extension(ac, av);
	if (ret != 0)
		return (ret);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		perror("open");
		return (ERROR_SYSCALL);
	}
	ret = get_scene(fd, ptr_scene);
	if (close(fd) == -1)
	{
		printf("Error\n");
		perror("close");
		if (ret != SUCCESS)
			return (ret);
		return (ERROR_SYSCALL);
	}
	return (ret);
}

int	check_extension(int ac, char **av)
{
	int	len_file;
	int	len_ext;

	if (ac == 1)
	{
		printf("Error\n");
		printf("You must specify a path to a .rt file\n");
		return (ERROR_ARGUMENT);
	}
	len_file = ft_strlen(av[1]);
	len_ext = ft_strlen(".rt");
	if (len_file <= len_ext)
	{
		printf("Error\n");
		printf("Wrong filename or file extension\n");
		return (ERROR_FILENAME);
	}
	if (ft_strncmp(&av[1][len_file - len_ext], ".rt", 4) != 0)
	{
		printf("Error\n");
		printf("Wrong filename or file extension\n");
		return (ERROR_FILENAME);
	}
	return (SUCCESS);
}

int	init_scene(t_scene *ptr_scene)
{
	int	ret;
	int	i;

	ptr_scene->amb.lightning = -1;
	ptr_scene->cam.fov = -1;
	ptr_scene->light.brightness = -1;
	ft_bzero(ptr_scene->obj, sizeof(t_vector) * NB_OBJ);
	i = 0;
	while (i < NB_OBJ)
	{
		ret = ft_vector_init(&ptr_scene->obj[i], sizeof(t_obj), 5, NULL);
		if (ret != SUCCESS)
		{
			while (i >= 0)
			{
				ft_vector_free(&ptr_scene->obj[i]);
				--i;
			}
			return (ERROR_MALLOC);
		}
		++i;
	}
	return (SUCCESS);
}

int	fill_scene_info(char **line_split, t_scene *ptr_scene)
{
	int		ret;

	ret = -1;
	if (!line_split[0])
		return (ret);
	if (ft_strcmp(line_split[0], "A") == 0)
		ret = fill_item(line_split + 1, &ptr_scene->amb, g_amb_parser, NB_INFO_AMB);
	else if (ft_strcmp(line_split[0], "C") == 0)
		ret = fill_item(line_split + 1, &ptr_scene->cam, g_cam_parser, NB_INFO_CAM);
	else if (ft_strcmp(line_split[0], "L") == 0)
		ret = fill_item(line_split + 1, &ptr_scene->light, g_light_parser, NB_INFO_LIGHT);
	return (ret);
}

int	fill_object_info(char **line_split, t_scene *ptr_scene)
{
	int		ret;
	t_obj	obj;

	ret = SUCCESS;
	if (!line_split[0])
		return (ret);
	if (ft_strcmp(line_split[0], "sp") == 0)
	{
		obj.type = SPHERE;
		ret = fill_item(line_split + 1, &obj, g_sph_parser, NB_INFO_SPH);
	}
	else if (ft_strcmp(line_split[0], "cy") == 0)
	{
		obj.type = CYLINDER;
		ret = fill_item(line_split + 1, &obj, g_cyl_parser, NB_INFO_CYL);
	}
	else if (ft_strcmp(line_split[0], "pl") == 0)
	{
		obj.type = PLANE;
		ret = fill_item(line_split + 1, &obj, g_pl_parser, NB_INFO_PL);
	}
	if (ret != SUCCESS)
		return (INVALID_FILE);
	ret = ft_vector_add_single(&ptr_scene->obj[obj.type], &obj);
	if (ret != SUCCESS)
		return (ERROR_MALLOC);
	return (ret);
}

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

int	get_scene(int fd, t_scene *ptr_scene)
{
	int		ret;
	char	*line;

	ret = init_scene(ptr_scene);
	if (ret != SUCCESS)
		return (ret);
	line = NULL;
	ret = get_line(fd, &line);
	while (ret == SUCCESS && line != NULL)
	{
		ret = parse_line(line, ptr_scene);
		free(line);
		if (ret != SUCCESS)
			break ;
		ret = get_line(fd, &line);
	}
	if (ret != SUCCESS)
		free_obj(ptr_scene->obj);
	return (ret);
}
