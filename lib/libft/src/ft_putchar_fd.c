/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:35:18 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/28 12:43:17 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
	c: char to output
	fd: file descriptor
 */

int	ft_putchar_fd(char c, int fd)
{
	int	len;

	if (!c)
		return (-1);
	len = (int) write(fd, &c, 1);
	return (len);
}
