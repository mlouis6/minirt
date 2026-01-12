/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:49:06 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/12 20:03:37 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ret_val.h"

void	print_error(int err)
{
	if (err == ERROR_ARGUMENT)
		ft_putstr_fd("Error\nYou must specify a path to a .rt file\n", 2);
	else if (err == ERROR_MALLOC)
		ft_putstr_fd("Error\nCouldn't allocate properly\n", 2);
	else if (err == ERROR_FILENAME)
		ft_putstr_fd("Error\nFile extention should be '.rt'\n", 2);
	else if (err == INVALID_FILE)
		ft_putstr_fd("Error\nFile formatting issue\n", 2);
}
