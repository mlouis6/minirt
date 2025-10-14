/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:51:21 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/29 11:22:42 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	cnb;
	int		is_neg;
	int		len;

	is_neg = 0;
	len = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", 1));
	if (n < 0)
	{
		is_neg++;
		n = -n;
		len = len + ft_putchar_fd('-', fd);
	}
	cnb = n % 10 + '0';
	if (n > 9)
		len = len + ft_putnbr_fd(n / 10, fd);
	return (len + ft_putchar_fd(cnb, fd));
}
