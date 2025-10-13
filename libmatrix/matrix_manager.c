/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:07:40 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/13 16:13:44 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>

void	setup_values(t_matrix *mx, float **values)
{
	size_t	i;
	size_t	j;

	i = 0;
	while(i < mx->m)
	{
		j = 0;
		while (j < mx->n)
		{
			mx->val[i][j] = values[i][j];
			++j;
		}
		++i;
	}
}

void	free_arr(void **arr, size_t i)
{
	if (!arr)
		return ;
	while(i > 0)
	{
		--i;
		free(arr[i]);
	}
	free(arr);
}

/**
 * @brief create a matrix of dimension i*j
 */
int	matrix_create(t_matrix *mx, size_t m, size_t n)
{
	size_t	i;

	mx->m = m;
	mx->n = n;
	mx->val = ft_calloc(sizeof(double *), m);
	if (!mx->val)
		return (ERR_ALLOC);
	i = 0;
	while (i < m)
	{
		mx->val[i] = ft_calloc(sizeof(double), n);
		if (!mx->val[i])
		{
			free_arr((void *)mx->val, i);
			return (ERR_ALLOC);
		}
		++i;
	}
	return (SUCCESS);
}

void	matrix_destroy(t_matrix *mx)
{
	size_t	i;

	i = 0;
	while(i < mx->m)
	{
		free(mx->val[i]);
		++i;
	}
	free(mx->val);
}

void	print_matrix(t_matrix *mx)
{
	size_t	i;
	size_t	j;

	i = 0;
	while(i < mx->m)
	{
		j = 0;
		printf("[ ");
		while (j < mx->n)
		{
			printf("%.2f ", mx->val[i][j]);
			++j;
		}
		printf("]\n");
		++i;
	}
}
