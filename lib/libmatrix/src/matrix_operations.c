/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:33:10 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/20 17:43:02 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "error.h"

int	matrix_add(t_matrix *r_mx, t_matrix *mx1, t_matrix *mx2)
{
	size_t	i;
	size_t	j;

	if (mx1->m - mx2->m || mx1->n - mx2->n)
		return (-1);
	if (matrix_create_empty(r_mx, mx1->m, mx1->n))
		return (ERR_ALLOC);
	i = 0;
	while (i < mx1->m)
	{
		j = 0;
		while (j < mx1->n)
		{
			r_mx->val[i][j] = mx1->val[i][j] + mx2->val[i][j];
			++j;
		}
		++i;
	}
	return (SUCCESS);
}

int	matrix_multiply_number(t_matrix *r_mx, t_matrix *mx, float nb)
{
	size_t	i;
	size_t	j;

	if (matrix_create_empty(r_mx, mx->m, mx->n))
		return (ERR_ALLOC);
	i = 0;
	while (i < mx->m)
	{
		j = 0;
		while (j < mx->n)
		{
			r_mx->val[i][j] = mx->val[i][j] * nb;
			++j;
		}
		++i;
	}
	return (SUCCESS);
}

float	vector_multiply(t_matrix *mx1, t_matrix *mx2, size_t i, size_t j)
{
	float	res;
	size_t	k;

	res = 0;
	k = 0;
	if (mx1->m > mx2->m)
	{
		while (k < mx2->n)
		{
			res += mx2->val[i][k] * mx1->val[k][j];
			++k;
		}
	}
	else
	{
		while (k < mx1->n)
		{
			res += mx1->val[i][k] * mx2->val[k][j];
			++k;
		}
	}
	return (res);
}

int	matrix_multiply(t_matrix *r_mx, t_matrix *mx1, t_matrix *mx2)
{
	size_t	i;
	size_t	j;

	if (mx1->n != mx2->m)
		return (-1);
	if (result_matrix_setup(r_mx, mx1, mx2))
		return (ERR_ALLOC);
	i = 0;
	while (i < r_mx->m)
	{
		j = 0;
		while (j < r_mx->n)
		{
			r_mx->val[i][j] = vector_multiply(mx1, mx2, i, j);
			++j;
		}
		++i;
	}
	return (SUCCESS);
}

int	matrix_transpose(t_matrix *r_mx, t_matrix *mx)
{
	size_t	i;
	size_t	j;

	if (matrix_create_empty(r_mx, mx->n, mx->m))
		return (ERR_ALLOC);
	i = 0;
	while (i < mx->m)
	{
		j = 0;
		while (j < mx->n)
		{
			r_mx->val[j][i] = mx->val[i][j];
			++j;
		}
		++i;
	}
	return (SUCCESS);
}
