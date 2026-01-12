/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:49:06 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/12 13:05:06 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ret_val.h"

void	print_error(int err)
{
	if (err == ERROR_ARGUMENT)
		printf("Error\nYou must specify a path to a .rt file\n");
	else if (err == ERROR_MALLOC)
		printf("Error\nCouldn't allocate properly\n");
	else if (err == ERROR_FILENAME)
		printf("Error\nFile extention should be '.rt'\n");
	else if (err == INVALID_FILE)
		printf("Error\nFile formatting issue\n");
}
