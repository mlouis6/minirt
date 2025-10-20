/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:42:42 by cviel             #+#    #+#             */
/*   Updated: 2025/10/20 17:22:22 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "parsing.h"
#include "ret_val.h"
#include "window.h"
#include "ret_val.h"
#include <stdio.h>

static int	check_args(int ac, char **av)
{
    int	ret;

	if (ac == 1)
	{
		printf("Error\n");
		printf("You must specify a path to a .rt file\n");
		return (ERROR_ARGUMENT);
	}
	ret = parsing(av[1]);
	return (ret);
}

int main(int ac, char **av)
{
	int		err;
	t_mlx	mlx;

	err = check_args(ac, av);
	if (err)
		return (err);
	init_window(&mlx, av[1]);
	mlx_hook(mlx.win, ON_DESTROY, 1L << 17, cross_button_handler, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
