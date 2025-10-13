/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:07:01 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/13 18:14:16 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdio.h>
#include "error.h"

int	main(void)
{
	t_matrix mx1;
	t_matrix mx2;
	t_matrix r_mx;
	int		err;

	//? not the same
	// err = matrix_create_empty(&mx2, 2, 3);
	// if (err)
	// {
	// 	printf("whoops xm1\n");
	// 	return (err);
	// }
	// mx2.val[0][0] = 1;
	// mx2.val[0][1] = 2;
	// mx2.val[0][2] = 0;
	// mx2.val[1][0] = 4;
	// mx2.val[1][1] = 3;
	// mx2.val[1][2] = -1;

	// err = matrix_create_empty(&mx1, 3, 2);
	// if (err)
	// {
	// 	printf("whoops mx2\n");
	// 	return (err);
	// }
	// mx1.val[0][0] = 5;
	// mx1.val[0][1] = 1;
	// mx1.val[1][0] = 2;
	// mx1.val[1][1] = 3;
	// mx1.val[2][0] = 3;
	// mx1.val[2][1] = 4;

	//? same size but not square
	// err = matrix_create_empty(&mx1, 2, 3);
	// if (err)
	// {
	// 	printf("whoops xm1\n");
	// 	return (err);
	// }
	// mx1.val[0][0] = 1;
	// mx1.val[0][1] = 2;
	// mx1.val[0][2] = 0;
	// mx1.val[1][0] = 4;
	// mx1.val[1][1] = 3;
	// mx1.val[1][2] = -1;
	// err = matrix_create_empty(&mx2, 2, 3);
	// if (err)
	// {
	// 	printf("whoops xm1\n");
	// 	return (err);
	// }
	// mx2.val[0][0] = 5;
	// mx2.val[0][1] = 2;
	// mx2.val[0][2] = 3;
	// mx2.val[1][0] = 1;
	// mx2.val[1][1] = 3;
	// mx2.val[1][2] = 4;

	//? same square
	err = matrix_create_empty(&mx1, 3, 3);
	if (err)
	{
		printf("whoops xm1\n");
		return (err);
	}
	mx1.val[0][0] = 1;
	mx1.val[0][1] = 2;
	mx1.val[0][2] = 0;
	mx1.val[1][0] = 4;
	mx1.val[1][1] = 3;
	mx1.val[1][2] = -1;
	mx1.val[2][0] = 2;
	mx1.val[2][1] = 1;
	mx1.val[2][2] = 4;
	err = matrix_create_empty(&mx2, 3, 3);
	if (err)
	{
		printf("whoops xm1\n");
		return (err);
	}
	mx2.val[0][0] = 5;
	mx2.val[0][1] = 2;
	mx2.val[0][2] = 3;
	mx2.val[1][0] = 1;
	mx2.val[1][1] = 3;
	mx2.val[1][2] = 4;
	mx2.val[2][0] = 6;
	mx2.val[2][1] = -3;
	mx2.val[2][2] = 5;

	printf("=== MX1 ===\n");
	print_matrix(&mx1);
	printf("\n=== MX2 ===\n");
	print_matrix(&mx2);


	err = matrix_add(&r_mx, &mx1, &mx2);
	if (err)
	{
		printf("whoops add\n");
		if (err == ERR_ALLOC)
			return (err);
	}
	else
	{
		printf("\n=== ADD ===\n");
		print_matrix(&r_mx);
	}

	err = matrix_multiply_number(&r_mx, &mx1, 2);
	if (err)
	{
		printf("whoops multiply number\n");
		return (err);
	}
	printf("\n=== MNB ===\n");
	print_matrix(&r_mx);

	err = matrix_multiply(&r_mx, &mx1, &mx2);
	if (err)
	{
		printf("whoops multiply\n");
		return (err);
	}
	printf("\n=== MUL ===\n");
	print_matrix(&r_mx);
}
