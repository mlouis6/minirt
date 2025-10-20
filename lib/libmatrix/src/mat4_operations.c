/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:44:52 by cviel             #+#    #+#             */
/*   Updated: 2025/10/20 19:07:18 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "dim4.h"

t_mat4	mat4_add(t_mat4 m1, t_mat4 m2)
{
	t_mat4	res;
	uint8_t	i;
	uint8_t	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res.coeff[i][j] = m1.coeff[i][j] + m2.coeff[i][j];
			++j;
		}
		++i;
	}
}

t_mat4	mat4_mult_nb(t_mat4 m, float lambda)
{
	t_mat4	res;
	uint8_t	i;
	uint8_t	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res.coeff[i][j] = lambda * m.coeff[i][j];
			++j;
		}
		++i;
	}
}

t_mat4	mat4_mult(t_mat4 m1, t_mat4 m2)
{
	t_mat4	res;
	uint8_t	i;
	uint8_t	j;
	uint8_t	k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res.coeff[i][j] = 0;
			k = 0;
			while (k < 4)
			{
				res.coeff[i][j] += m1.coeff[i][k] * m2.coeff[k][j];
				++k;
			}
			++j;
		}
		++i;
	}
	return (res);
}

t_mat4	mat4_trans(t_mat4 m)
{
	t_mat4	res;
	uint8_t	i;
	uint8_t	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res.coeff[i][j] = m.coeff[j][i];
			++j;
		}
		++i;
	}
	return (res);
}
