/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:01:21 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/14 16:15:55 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	integer_part(char *str, int *i);
static double	fractional_part(char *str, int *i);

double	ft_strtod(char *str, char **endptr)
{
	double	res;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	while (str[i] && ft_isspace(str[i]))
		++i;
	res = 0;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i ]== '+')
		++i;
	res = integer_part(str, &i);
	res += fractional_part(str, &i);
	while (ft_isdigit(str[i]))
		++i;
	*endptr = &str[i];
	return (res * sign);
}

static double	integer_part(char *str, int *i)
{
	double	res;
	double	cmp;

	cmp = 0;
	res = 0;
	while (ft_isdigit(str[*i]))
	{
		res += str[*i] - '0';
		if (res < cmp)
			return (res);
		if (ft_isdigit(str[*i + 1]))
			res = res * 10;
		cmp = res;
		++(*i);
	}
	if (ft_isdigit(str[*i]))
	{
		res += str[*i] - '0';
		++(*i);
	}
	return (res);
}

static double	fractional_part(char *str, int *i)
{
	double	dec;
	double	tmp;
	double	cmp;
	int		div;

	cmp = 0;
	dec = 0;
	div = 10;
	if (str[*i] == '.')
		++(*i);
	tmp = 0;
	while (ft_isdigit(str[*i]))
	{
		tmp = str[*i] - '0';
		tmp /= div;
		dec += tmp;
		if (dec < cmp)
			return (dec);
		cmp = dec;
		++(*i);
		div *= 10;
	}
	return (dec);
}
