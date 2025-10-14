/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:11:53 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/14 18:59:58 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "libft.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief create a matrix of dimension m*n
 * @brief init all values to 0
 * @return 0 if successful or another number if error
 */
int	matrix_create_empty(t_matrix *mx, size_t m, size_t n)
{
	size_t	i;

	mx->m = m;
	mx->n = n;
	mx->val = ft_calloc(sizeof(float *), m);
	if (!mx->val)
		return (ERR_ALLOC);
	i = 0;
	while (i < m)
	{
		mx->val[i] = ft_calloc(sizeof(float), n);
		if (!mx->val[i])
		{
			free_arr((void *)mx->val, i);
			return (ERR_ALLOC);
		}
		++i;
	}
	return (SUCCESS);
}

/**
 * @brief create a matrix of dimension m*n
 * @brief the values must be allocated
 */
void	matrix_create(t_matrix *mx, size_t m, size_t n, float **values)
{
	mx->m = m;
	mx->n = n;
	mx->val = values;
}

void	matrix_destroy(t_matrix *mx)
{
	size_t	i;

	i = 0;
	while (i < mx->m)
	{
		free(mx->val[i]);
		++i;
	}
	free(mx->val);
}
