/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:20:46 by cviel             #+#    #+#             */
/*   Updated: 2025/11/07 20:25:24 by cviel            ###   ########.fr       */
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
#include "ft_vector.h"

int		check_extension(int ac, char **av);
int		get_scene(int fd, t_scene *ptr_scene);
void	print_scene(t_scene scene);

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

int	init_scene(t_scene *ptr_scene)
{
	int	ret;
	int	i;
	
	ptr_scene->amb.lightning = -1;
	ptr_scene->cam.fov = -1;
	ptr_scene->light.brightness = -1;
	ptr_scene->root = NULL;
	i = 0;
	while (i < NB_INF)
	{
		ret = ft_vector_init(&ptr_scene->inf_obj[i], sizeof(t_obj), 5, NULL);
		if (ret != SUCCESS)
		{
			while (i >= 0)
			{
				ft_vector_free(&ptr_scene->inf_obj[i]);
				--i;
			}
			return (ERROR_MALLOC);
		}
		++i;
	}
	return (SUCCESS);
}

int	fill_scene_info(char **line_split, t_scene *ptr_scene, uint8_t *ptr_check)
{
	int		ret;

	if (ft_strncmp(line_split[0], "A", ft_strlen(line_split[0])) == 0)
	{
		*ptr_check = TRUE;
		ret = fill_ambient_info(line_split + 1, ptr_scene);
	}
	else if (ft_strncmp(line_split[0], "C", ft_strlen(line_split[0])) == 0)
	{
		*ptr_check = TRUE;
		ret = fill_camera_info(line_split + 1, ptr_scene);
	}
	else if (ft_strncmp(line_split[0], "L", ft_strlen(line_split[0])) == 0)
	{
		*ptr_check = TRUE;
		ret = fill_light_info(line_split + 1, ptr_scene);
	}
	if (*ptr_check == TRUE)
		return (ret);
	return (SUCCESS);
}

int	get_scene(int fd, t_scene *ptr_scene)
{
	int		ret;
	char	*line;
	char	**line_split;
	uint8_t	check;

	ret = init_scene(ptr_scene);
	if (ret != SUCCESS)
		return (ret);
	line = NULL;
	ret = get_line(fd, &line);
	while (ret == SUCCESS && line != NULL)
	{
		line_split = split_line(line, WHITE_SPACES);
		if (line_split == NULL)
		{
			free(line);
			return (ERROR_MALLOC);
		}
		check = FALSE;
		ret = fill_scene_info(line_split, ptr_scene, &check);
		if (check == FALSE)
			ret = fill_object_info(line_split, ptr_scene, &check);
		free_split(line_split);
		free(line);
		if (ret != SUCCESS || check == FALSE)
		{
			if (ret != SUCCESS)
				return (ret);
			return (INVALID_FILE);
		}
		ret = get_line(fd, &line);
	}
	return (ret);
}
