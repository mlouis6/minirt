/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:45:40 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/22 10:22:49 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	len;

	if (!s)
		return (-1);
	len = ft_putstr_fd(s, fd);
	len = len + ft_putchar_fd('\n', fd);
	return (len);
}
