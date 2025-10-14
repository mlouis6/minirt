/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:05:42 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/14 17:09:31 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "error.h"
#include <stdio.h>

void	print_matrix(t_matrix *mx)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < mx->m)
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

/**
  * @brief set up the end matrix when 2 matrices are multiply
  * @return 0 if successful or another number allocation failed
  */
int	result_matrix_setup(t_matrix *r_mx, t_matrix *mx1, t_matrix *mx2)
{
	if (mx1->m > mx2->m)
	{
		if (matrix_create_empty(r_mx, mx1->n, mx2->m))
			return (ERR_ALLOC);
	}
	else
	{
		if (matrix_create_empty(r_mx, mx2->n, mx1->m))
			return (ERR_ALLOC);
	}
	return (SUCCESS);
}
