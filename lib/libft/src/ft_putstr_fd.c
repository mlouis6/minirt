/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:40:37 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/22 10:22:32 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (!s)
		return (-1);
	len = (int) write(fd, s, ft_strlen(s));
	return (len);
}
