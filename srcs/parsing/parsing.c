/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:20:46 by cviel             #+#    #+#             */
/*   Updated: 2026/01/12 20:03:57 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "ret_val.h"
#include "scene.h"
#include "parsing.h"
#include "ft_vector.h"

static int	check_extension(int ac, char **av);
static int	get_scene(int fd, t_scene *ptr_scene);

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
		ft_putstr_fd("Error\n", 2);
		perror("open");
		return (ERROR_SYSCALL);
	}
	ret = get_scene(fd, ptr_scene);
	if (close(fd) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		perror("close");
		if (ret != SUCCESS)
			return (ret);
		return (ERROR_SYSCALL);
	}
	return (ret);
}

static int	check_extension(int ac, char **av)
{
	int	len_file;
	int	len_ext;

	if (ac == 1)
		return (ERROR_ARGUMENT);
	len_file = ft_strlen(av[1]);
	len_ext = ft_strlen(".rt");
	if (len_file <= len_ext)
		return (ERROR_FILENAME);
	if (ft_strncmp(&av[1][len_file - len_ext], ".rt", 4) != 0)
		return (ERROR_FILENAME);
	return (SUCCESS);
}

static int	init_scene(t_scene *ptr_scene)
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

static int	get_scene(int fd, t_scene *ptr_scene)
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
	if (ret == SUCCESS
		&& (ptr_scene->cam.fov == -1 || ptr_scene->amb.lightning == -1
			|| ptr_scene->light.brightness == -1))
		ret = INVALID_FILE;
	if (ret != SUCCESS)
		free_obj(ptr_scene->obj);
	return (ret);
}
