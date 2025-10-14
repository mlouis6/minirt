/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:26:05 by mlouis            #+#    #+#             */
/*   Updated: 2025/01/14 15:49:12 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char			*line;
	static char		buffer[BUFFER_SIZE + 1];
	ssize_t			nb_read;

	nb_read = 1;
	line = NULL;
	while (nb_read > 0)
	{
		if (buffer[0])
		{
			line = create_line(buffer, line);
			if (!line || find_endl(line))
				return (line);
		}
		nb_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (nb_read < 0)
	{
		free(line);
		return (NULL);
	}
	if (buffer[0])
		line = ft_strnjoin(line, buffer, (ft_strlen(line) + ft_strlen(buffer)));
	return (line);
}

char	*create_line(char *buffer, char *line)
{
	int	index;

	index = find_endl(buffer);
	if (index == 0)
		line = ft_strnjoin(line, buffer, (ft_strlen(line) + ft_strlen(buffer)));
	else
	{
		line = ft_strnjoin(line, buffer, (ft_strlen(line) + index));
		cut_endl(buffer, index);
		return (line);
	}
	ft_bzero(buffer, BUFFER_SIZE);
	return (line);
}
