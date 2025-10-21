/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:05:42 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/21 15:25:37 by mlouis           ###   ########.fr       */
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
