/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:20:46 by cviel             #+#    #+#             */
/*   Updated: 2025/11/04 20:45:36 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "ret_val.h"
#include "scene.h"
#include "parsing.h"

int	check_extension(int ac, char **av);
int	get_scene(int fd, t_scene *ptr_scene);

// int	parsing(int ac, char **av, t_scene *ptr_scene)
// {
//     int	ret;
// 	int	fd;

// 	ret = check_extension(ac, av);
// 	if (ret != SUCCESS)
// 		return (ret);
// 	fd = open(av[1], O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error\n");	
// 		perror("open :");
// 		return (ERROR_SYSCALL);
// 	}
// 	ret = get_scene(fd, ptr_scene);
// 	if (ret != SUCCESS)
// 		return (ret);
// 	return (check_elements(*ptr_scene));
// }

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
		perror("open :");
		return (ERROR_SYSCALL);
	}
	ret = get_scene(fd, ptr_scene);
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

void	init_scene(t_scene *ptr_scene)
{
	ptr_scene->amb.lightning = -1;
	ptr_scene->cam.fov = -1;
	ptr_scene->light.brightness = -1;
	ptr_scene->root = NULL;
}

int	call_match(char **info_split, t_scene *ptr_scene, const t_func table[NB_ITEM], uint8_t *ptr_check)
{
	int	ret;
	int	i;
	
	*ptr_check = FALSE;
	if (info_split[0] == NULL)
		return (SUCCESS);
	i = 0;
	while (i < NB_ITEM)
	{
		if (ft_strncmp(info_split[0], table[i].name, ft_strlen(table[i].name)) == 0)
		{
			*ptr_check = TRUE;
			ret = table[i].f(info_split, ptr_scene);
			return (ret);
		}
		++i;
	}
	return (SUCCESS);
}

int	fill_scene_info(char *line, t_scene *ptr_scene)
{
	int		ret;
	char	**line_split;
	uint8_t	check;

	line_split = split_line(line, WHITE_SPACES);
	if (line_split == NULL)
		return (ERROR_MALLOC);
	ret = call_match(line_split, ptr_scene, g_table_item, &check);
	if (ret != SUCCESS || check == TRUE)
	{
		free_split(line_split);
		return (ret);
	}
	ret = fill_object_info(line_split, ptr_scene, &check);
	free_split(line_split);
	if (ret != SUCCESS)
		return (ret);
	if (check == FALSE)
		return (INVALID_FILE);
	return (SUCCESS);
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
	return (ret);
}


