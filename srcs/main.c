/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:42:42 by cviel             #+#    #+#             */
/*   Updated: 2025/10/27 11:24:26 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "ret_val.h"
#include "parsing.h"
#include "window.h"
#include "scene.h"

void	free_scene(t_scene *scene)
{
	(void) scene;
}

int main(int ac, char **av)
{
	int		err;
	t_mlx	mlx;
	t_scene	scene;

	err = parsing(ac, av, &scene);
	if (err)
	{
		free_scene(&scene);
		return (err);
	}
	init_window(&mlx, av[1]);
	mlx_hook(mlx.win, ON_KEYDOWN, 1L << 0, key_event, &mlx);
	mlx_hook(mlx.win, ON_DESTROY, 1L << 17, cross_button_handler, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
