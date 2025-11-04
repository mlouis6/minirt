/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:42:42 by cviel             #+#    #+#             */
/*   Updated: 2025/10/30 16:31:36 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "ret_val.h"
#include "parsing.h"
#include "window.h"
#include "scene.h"
#include "color.h"

void	free_scene(t_scene *scene)
{
	(void) scene;
}

// static void	print_scene(t_scene scene)
// {
// 	printf("A= [%.1f] [%d,%d,%d]\n", scene.amb.lightning,
// 		scene.amb.color.r, scene.amb.color.g, scene.amb.color.b);
// 	printf("C= [%.1f,%.1f,%.1f] [%.0f,%.0f,%.0f] [%d]\n", scene.cam.pos.x, scene.cam.pos.y, scene.cam.pos.z,
// 		scene.cam.dir.x, scene.cam.dir.y, scene.cam.dir.z, scene.cam.fov);
// 	printf("L= [%.1f,%.1f,%.1f] [%.1f] [%d,%d,%d]\n", scene.light.pos.x, scene.light.pos.y, scene.light.pos.z,
// 		scene.light.brightness, scene.light.color.r, scene.light.color.g, scene.light.color.b);
// }

int	main(int ac, char **av)
{
	(void) ac; (void) av;
	// int		err;
	t_mlx	mlx;
	// t_scene	scene;

	// err = parsing(ac, av, &scene);
	// if (err)
	// {
	// 	free_scene(&scene);
	// 	return (err);
	// }
	// print_scene(scene);
	init_window(&mlx, av[1]);
	// mlx_loop_hook(mlx.mlx, &);
	t_color	c;
	c.r = 36; c.g = 183; c.b = 94;
	display_background(&mlx, c);
	mlx_hook(mlx.win, ON_KEYDOWN, 1L << 0, key_event, &mlx);
	mlx_hook(mlx.win, ON_DESTROY, 1L << 17, cross_button_handler, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
