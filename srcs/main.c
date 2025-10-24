/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:42:42 by cviel             #+#    #+#             */
/*   Updated: 2025/10/24 15:15:11 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "parsing.h"
#include "ret_val.h"
#include "window.h"
#include "ret_val.h"
#include <stdio.h>
#include "scene.h"

static int	check_args(int ac, char **av, t_scene *scene)
{
	int		ret;

	if (ac == 1)
	{
		printf("Error\n");
		printf("You must specify a path to a .rt file\n");
		return (ERROR_ARGUMENT);
	}
	ret = parsing(av[1], &scene);
	return (ret);
}

static void	print_scene(t_scene scene)
{
	printf("A= [%.1f] [%d,%d,%d]\n", scene.ambi_l.lightning,
		scene.ambi_l.color.r, scene.ambi_l.color.g, scene.ambi_l.color.b);
	printf("C= [%.1f,%.1f,%.1f] [%.0f,%.0f,%.0f] [%d]\n", scene.cam.pos.x, scene.cam.pos.y, scene.cam.pos.z,
		scene.cam.dir.x, scene.cam.dir.y, scene.cam.dir.z, scene.cam.fov);
	printf("L= [%.1f,%.1f,%.1f] [%.1f] [%d,%d,%d]\n", scene.light.pos.x, scene.light.pos.y, scene.light.pos.z,
		scene.light.brightness, scene.light.color.r, scene.light.color.g, scene.light.color.b);
}

int	main(int ac, char **av)
{
	int		err;
	t_mlx	mlx;
	t_scene	scene;

	err = check_args(ac, av, &scene);
	if (err)
		return (err);
	print_scene(scene);
	init_window(&mlx, av[1]);
	mlx_hook(mlx.win, ON_KEYDOWN, 1L << 0, key_event, &mlx);
	mlx_hook(mlx.win, ON_DESTROY, 1L << 17, cross_button_handler, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
