/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:20:46 by cviel             #+#    #+#             */
/*   Updated: 2025/10/25 09:01:35 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "ret_val.h"
#include "scene.h"
#include "objects.h"
#include "parsing.h"

int	check_extension(int ac, char **av);
int	get_scene(int fd, t_scene *ptr_scene);

int	parsing(int ac, char **av, t_scene *ptr_scene)
{
    int	ret;
	int	fd;

	ret = check_extension(ac, av);
	if (ret != SUCCESS)
		return (ret);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");	
		perror("open :");
		return (ERROR_SYSCALL);
	}
	ret = get_scene(fd, ptr_scene);
	if (ret != SUCCESS);
		return (ret);
	return (check_elements(*ptr_scene));
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

void	init_scene(t_scene *ptr_scene)
{
	ptr_scene->amb.lightning = -1;
	ptr_scene->cam.fov = -1;
	ptr_scene->light.brightness = -1;
	ptr_scene->root = NULL;
}

int	fill_scene_info(char *line, t_scene *ptr_scene)
{
	int		ret;
	char	**line_split;
	int		i;

	i = 0;
	ret = split_line(line, WHITE_SPACES, &line_split);
	if (ret != SUCCESS)
	{
		free_split(line_split);
		return (ret);
	}
	
	return (INVALID_FILE);
}

int	get_scene(int fd, t_scene *ptr_scene)
{
	int		ret;
	char	*line;

	init_scene(ptr_scene);
	line = NULL;
	ret = get_line(fd, &line);
	while (ret == SUCCESS && line != NULL)
	{
		ret = fill_scene_info(line, ptr_scene);
		free(line);
		if (ret != SUCCESS)
			return (ret);
		ret = get_line(fd, &line);
	}
	if (ret != SUCCESS)
		return (ret);
	return (ret);
}

