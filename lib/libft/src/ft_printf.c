/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:21:08 by mlouis            #+#    #+#             */
/*   Updated: 2025/01/14 15:49:20 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	a_lst;
	int		len;
	int		res;

	if (!format)
		return (-1);
	va_start(a_lst, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			res = converter_handler(*format, a_lst);
			if (res == -1)
				return (-1);
			len += res;
			format++;
			continue ;
		}
		len = len + ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(a_lst);
	return (len);
}
