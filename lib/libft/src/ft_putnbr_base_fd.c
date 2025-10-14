/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:09:36 by mlouis            #+#    #+#             */
/*   Updated: 2025/01/14 15:58:56 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_fd(unsigned long n, char *base, int fd)
{
	char			cnb;
	unsigned long	dec;
	size_t			size;
	int				len;

	size = ft_strlen(base);
	dec = n % size;
	cnb = base[dec];
	len = 0;
	if (n >= size)
		len = len + ft_putnbr_base_fd(n / size, base, fd);
	len = len + ft_putchar_fd(cnb, fd);
	return (len);
}
