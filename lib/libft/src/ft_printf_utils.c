/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:10:31 by mlouis            #+#    #+#             */
/*   Updated: 2025/01/14 15:58:37 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	output_char(char c_arg);
static int	output_str(va_list a_lst);
static int	output_hex(const char format, va_list a_lst);
static int	output_ptr(va_list a_lst);

int	converter_handler(const char format, va_list a_lst)
{
	if (format == '\0')
		return (-1);
	if (format == '%')
		return (ft_putchar_fd(format, 1));
	if (format == 'c')
		return (output_char((char) va_arg(a_lst, int)));
	if (format == 's')
		return (output_str(a_lst));
	if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(a_lst, int), 1));
	if (format == 'u')
		return (ft_putnbr_positive_fd(va_arg(a_lst, unsigned int), 1));
	if (format == 'x' || format == 'X')
		return (output_hex(format, a_lst));
	if (format == 'p')
		return (output_ptr(a_lst));
	return (ft_putchar_fd('%', 1) + output_char(format));
}

static int	output_char(char c_arg)
{
	int		len;

	if (c_arg != 0)
		len = ft_putchar_fd(c_arg, 1);
	else
		len = write(1, "\0", 1);
	return (len);
}

static int	output_str(va_list a_lst)
{
	int		len;
	char	*s_arg;

	s_arg = ft_strdup((char *) va_arg(a_lst, char *));
	if (s_arg)
	{
		len = ft_putstr_fd(s_arg, 1);
		free(s_arg);
	}
	else
		len = ft_putstr_fd("(null)", 1);
	return (len);
}

static int	output_hex(const char format, va_list a_lst)
{
	int				len;
	int				n_arg;
	unsigned long	ul_arg;
	char			base[17];

	n_arg = va_arg(a_lst, int);
	if (format == 'x')
		ft_strlcpy(base, HEX_LOWER, 17);
	else
		ft_strlcpy(base, HEX_UPPER, 17);
	if (n_arg >= 0)
		len = ft_putnbr_base_fd(n_arg, base, 1);
	else
	{
		ul_arg = LONG_OVERFLOW + n_arg;
		len = ft_putnbr_base_fd(ul_arg, base, 1);
	}
	return (len);
}

static int	output_ptr(va_list a_lst)
{
	int				len;
	unsigned long	ul_arg;

	ul_arg = va_arg(a_lst, unsigned long);
	if (ul_arg != 0)
	{
		len = ft_putstr_fd("0x", 1);
		len += ft_putnbr_base_fd(ul_arg, HEX_LOWER, 1);
	}
	else
		len = ft_putstr_fd("(nil)", 1);
	return (len);
}
