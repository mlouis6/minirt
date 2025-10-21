/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:58:35 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/20 19:06:06 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim3.h"

t_mat3	mat3_add(t_mat3 mx1, t_mat3 mx2)
{
	t_mat3	res;
	uint8_t	i;
	uint8_t	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			res.coeff[i][j] = mx1.coeff[i][j] + mx2.coeff[i][j];
			++j;
		}
		++i;
	}
	return (res);
}

t_mat3	mat3_mult_nb(t_mat3 mx, float nb)
{
	t_mat3	res;
	uint8_t	i;
	uint8_t	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			res.coeff[i][j] = mx.coeff[i][j] * nb;
			++j;
		}
		++i;
	}
	return (res);
}

static float	scalar3_product(t_mat3 mx1, t_mat3 mx2, uint8_t i, uint8_t j)
{
	float	res;
	uint8_t	k;

	res = 0;
	k = 0;
	while (k < 3)
	{
		res += mx1.coeff[i][k] * mx2.coeff[k][j];
		++k;
	}
	return (res);
}

t_mat3	mat3_mult(t_mat3 mx1, t_mat3 mx2)
{
	t_mat3	res;
	uint8_t	i;
	uint8_t	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			res.coeff[i][j] = scalar3_product(mx1, mx2, i, j);
			++j;
		}
		++i;
	}
	return (res);
}

t_mat3	mat3_trans(t_mat3 mx)
{
	t_mat3	res;
	uint8_t	i;
	uint8_t	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			res.coeff[j][i] = mx.coeff[i][j];
			++j;
		}
		++i;
	}
	return (res);
}
