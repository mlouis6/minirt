/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:42:42 by cviel             #+#    #+#             */
/*   Updated: 2026/01/12 19:02:17 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"
#include "mlx.h"
#include "ret_val.h"
#include "parsing.h"
#include "scene.h"
#include "libft.h"
#include "print.h"

int	main(int ac, char **av)
{
	int		err;
	t_mlx	mlx;
	t_scene	scene;

	err = parsing(ac, av, &scene);
	if (err != SUCCESS)
	{
		print_error(err);
		return (err);
	}
	ft_bzero(&mlx, sizeof(mlx));
	if (init_window(&mlx, av[1]) == SUCCESS)
	{
		display_scene(&mlx, scene);
		mlx_hook(mlx.win, ON_KEYDOWN, 1L << 0, key_event, &mlx);
		mlx_hook(mlx.win, ON_DESTROY, 1L << 17, cross_button_handler, &mlx);
		mlx_loop(mlx.mlx);
	}
	if (mlx.mlx)
	{
		mlx_destroy_display(mlx.mlx);
		free(mlx.mlx);
	}
	free_obj(scene.obj);
	return (SUCCESS);
}
