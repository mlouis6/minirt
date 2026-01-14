/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:16:56 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/14 16:13:17 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
long	ft_strtol(const char *nptr)
{
	long long	nb;
	long long	cmp;
	long		is_neg;

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
		nb *= 10;
		nb += *nptr - '0';
		nptr++;
	}
	if (is_neg)
		nb = -nb;
	return (nb);
}
