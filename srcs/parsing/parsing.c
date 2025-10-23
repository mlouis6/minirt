/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:20:46 by cviel             #+#    #+#             */
/*   Updated: 2025/10/23 18:06:00 by cviel            ###   ########.fr       */
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
	return (SUCCESS);	
}

int	parsing(char *pathname)
{
	int		ret;
	int		fd;
	char	*line;
	t_scene	scene;

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
	line = NULL;
	ret = get_line(fd, &line);
	while (ret == SUCCESS && line != NULL)
	{
		ret = fill_data(line, scene);
		free(line);
		ret = get_lline(fd, &line);
	}
	return (ret);
}

