/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:20:46 by cviel             #+#    #+#             */
/*   Updated: 2025/10/20 16:40:12 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "ret_val.h"
#include "scene.h"

int	check_extension(char *filename)
{
	int	len_file;
	int	len_ext;

	len_file = ft_strlen(filename);
	len_ext = ft_strlen(".rt");
	if (len_file <= len_ext)
	{
		printf("Error\n");
		printf("Wrong filename or file extension\n");
		return (ERROR_FILENAME);
	}
	if (ft_strncmp(&filename[len_file - len_ext], ".rt", 4) != 0)
	{
		printf("Error\n");
		printf("Wrong filename or file extension\n");
		return (ERROR_FILENAME);
	}
	return (0);	
}

int	parsing(char *pathname)
{
	int	ret;
	int	fd;

	ret = check_extension(pathname);
	if (ret != 0)
		return (ret);
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");	
		perror("open :");
		return (ERROR_SYSCALL);
	}
	return (0);
}

/**
 * while gnl
 * 	read first char
 * 	if A -> parse_ambient
 * 	if C -> parse_camera
 * 	if L -> parse_light
 * 	if A (again) -> ERROR
 * 	if another letter -> ERROR
 * 	if missing one -> ERROR
 */
// int	parse_scene(t_scene *scene, int fd)
// {
	
// }
