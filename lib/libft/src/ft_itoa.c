/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:08:16 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/18 16:53:13 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_digits(int n);
static int	check_neg(int *n, int is_max_neg);
static char	decimal_handler(int *n);

/**
	convert int n to str
 */

char	*ft_itoa(int n)
{
	char	*cnb;
	int		nb_digits;
	int		is_neg;
	int		is_max_neg;
	int		i;

	is_max_neg = 0;
	if (n == -2147483648)
		is_max_neg++;
	is_neg = check_neg(&n, is_max_neg);
	nb_digits = count_digits(n) + is_neg;
	cnb = ft_calloc(sizeof(char), nb_digits + 1);
	if (!cnb)
		return (NULL);
	i = nb_digits;
	while (i-- > is_neg)
		cnb[i] = decimal_handler(&n);
	if (is_neg)
		cnb[i] = '-';
	if (is_max_neg)
		cnb[nb_digits - 1]++;
	return (cnb);
}

static int	count_digits(int n)
{
	int	count;

	count = 1;
	while (n / 10)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char	decimal_handler(int *n)
{
	char	c;

	c = *n % 10 + '0';
	*n = *n / 10;
	return (c);
}

static int	check_neg(int *n, int is_max_neg)
{
	int	is_neg;

	is_neg = 0;
	if (is_max_neg)
		*n = *n + 1;
	if (*n < 0)
	{
		*n = *n * -1;
		is_neg++;
	}
	return (is_neg);
}
