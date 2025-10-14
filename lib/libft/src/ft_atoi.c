/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:54:32 by mlouis            #+#    #+#             */
/*   Updated: 2025/04/21 18:48:16 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflow_handler(long *nb, long cmp, int is_neg);
static long	convert_char(char c, long nb);

int	ft_atoi(const char *nptr)
{
	long	nb;
	long	cmp;
	int		is_neg;

	nb = 0;
	is_neg = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			is_neg++;
		nptr++;
	}
	while (*nptr != '\0' && *nptr >= '0' && *nptr <= '9')
	{
		cmp = nb;
		nb = convert_char(*nptr, nb);
		if (overflow_handler(&nb, cmp, is_neg))
			return (nb);
		nptr++;
	}
	if (is_neg)
		nb = -nb;
	return (nb);
}

static long	convert_char(char c, long nb)
{
	nb *= 10;
	nb += c - '0';
	return (nb);
}

static int	overflow_handler(long *nb, long cmp, int is_neg)
{
	int		check;

	check = 0;
	if (cmp > (*nb))
	{
		check++;
		(*nb) = -1;
		if (is_neg)
			(*nb) = 0;
	}
	return (check);
}
