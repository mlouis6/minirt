/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:41:11 by cviel             #+#    #+#             */
/*   Updated: 2025/10/23 17:36:23 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ret_val.h"

#define BUFF_SIZE 10

int		handle_buffer(char **ptr_line, char *buff, int *ptr_full_check);
char	*cut_endl(char *s, int len_endl);

int	get_line(int fd, char **ptr_line)
{
	int			ret;
	int			b_read;
	static char	buff[BUFF_SIZE + 1];
	int			full_check;

	b_read = 1;
	while (b_read != 0)
	{
		if (buff[0])
		{
			ret = handle_buffer(ptr_line, buff, &full_check);
			if (ret != SUCCESS || full_check == 1)
				return (ret);
		}
		b_read = read(fd, buff, BUFF_SIZE);
		if (b_read == -1)
		{
			free(*ptr_line);
			return (ERROR_SYSCALL);
		}
		ft_bzero(buff + b_read, BUFF_SIZE - b_read);
	}
	return (SUCCESS);
}

int	handle_buffer(char **ptr_line, char *buff, int *ptr_full_check)
{
	char	*endl;
	char	*big_line;
	int		len_endl;

	len_endl = ft_strchr(buff, '\n');
	if (len_endl >= 0)
	{
		endl = cut_endl(buff, len_endl);
		if (endl == NULL)
		{
			free(*ptr_line);
			return (ERROR_MALLOC);
		}
		*ptr_line = ft_strjoin(*ptr_line, endl);
		free(endl);
		if (*ptr_line == NULL)
			return (ERROR_MALLOC);
		*ptr_full_check = 1;
		return (SUCCESS);
	}
	*ptr_line = ft_strjoin(*ptr_line, buff);
	if (*ptr_line == NULL)
		return (ERROR_MALLOC);
	return (SUCCESS);
}

char	*cut_endl(char *s, int len_endl)
{
	char	*end_line;
	int		i;

	end_line = malloc(sizeof(char) * (len_endl + 2));
	if (end_line == NULL)
		return (NULL);
	i = 0;
	while (i <= len_endl)
	{
		end_line[i] = s[i];
		++i;
	}
	end_line[len_endl + 1] = '\0';
	while (s[i])
	{
		s[i - len_endl - 1] = s[i];
		++i;
	}
	ft_bzero(s + i - len_endl - 1, len_endl + 1);
	return (end_line);
}
