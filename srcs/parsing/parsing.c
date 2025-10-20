/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:20:46 by cviel             #+#    #+#             */
/*   Updated: 2025/10/17 18:48:02 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "ret_val.h"

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
	
}

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
	if (ft_strcmp(&filename[len_file - len_ext], ".rt") != 0)
	{
		printf("Error\n");
		printf("Wrong filename or file extension\n");
		return (ERROR_FILENAME);
	}
	return (0);	
}