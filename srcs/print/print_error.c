/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:49:06 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/12 11:55:21 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ret_val.h"

void	print_error(int err)
{
	if (err == ERROR_ARGUMENT)
		printf("Error\nWrong arg\n");
	else if (err == ERROR_SYSCALL)
		printf("Error\nsyscall issue\n");
	else if (err == ERROR_MALLOC)
		printf("Error\nCouldn't allocate properly\n");
	else if (err == ERROR_FILENAME)
		printf("Error\nExtention of file should be '.rt'\n");
	else if (err == INVALID_FILE)
		printf("Error\nFile formatting issue\n");
}
