/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:42:42 by cviel             #+#    #+#             */
/*   Updated: 2025/11/14 17:25:19 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ret_val.h"
//#include "mlx.h"
#include "parsing.h"
#include "window.h"
#include "scene.h"
#include "color.h"

void	free_scene(t_scene *scene)
{
	free_bvh(scene->root);
	free_inf(scene->inf_obj);
}

void	print_infinite(t_vector *inf_obj)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < NB_INF)
	{
		j = 0;
		while (j < inf_obj[i].size)
		{
			printf("obj type = %d, coord [%f,%f,%f], normal vect [%f,%f,%f], color [%d,%d,%d]\n",
				((t_obj *)inf_obj[i].data)[j].type,
				((t_obj *)inf_obj[i].data)[j].shape.plane.origin.x,
				((t_obj *)inf_obj[i].data)[j].shape.plane.origin.y,
				((t_obj *)inf_obj[i].data)[j].shape.plane.origin.z,
				((t_obj *)inf_obj[i].data)[j].shape.plane.normal.x,
				((t_obj *)inf_obj[i].data)[j].shape.plane.normal.y,
				((t_obj *)inf_obj[i].data)[j].shape.plane.normal.z,
				((t_obj *)inf_obj[i].data)[j].color.r,
				((t_obj *)inf_obj[i].data)[j].color.g,
				((t_obj *)inf_obj[i].data)[j].color.b);
			++j;
		}
		++i;
	}
}

void	print_scene(t_scene scene)
{
	printf("A= [%.1f] [%d,%d,%d]\n", scene.amb.lightning,
		scene.amb.color.r, scene.amb.color.g, scene.amb.color.b);
	printf("C= [%.1f,%.1f,%.1f] [%.0f,%.0f,%.0f] [%d]\n", scene.cam.pos.x, scene.cam.pos.y, scene.cam.pos.z,
		scene.cam.dir.x, scene.cam.dir.y, scene.cam.dir.z, scene.cam.fov);
	printf("L= [%.1f,%.1f,%.1f] [%.1f] [%d,%d,%d]\n", scene.light.pos.x, scene.light.pos.y, scene.light.pos.z,
		scene.light.brightness, scene.light.color.r, scene.light.color.g, scene.light.color.b);
}

void	print_bvh(t_bvh *root, int depth)
{
	int	i;

	if (root == NULL)
		return ;
	i = 0;
	while (i < depth)
	{
		printf("_");
		++i;
	}
	printf("object on node : %i, box : [%f -> %f] [%f -> %f] [%f-> %f]\n",
		root->obj.type, root->box.x_min, root->box.x_max, root->box.y_min, root->box.y_max, root->box.z_min, root->box.z_max);
	print_bvh(root->left, depth + 1);
	print_bvh(root->right, depth + 1);
}

int	main(int ac, char **av)
{
	int		err;
	//t_mlx	mlx;
	t_scene	scene;

	err = parsing(ac, av, &scene);
	if (err)
	{
		print_scene(scene);
		print_bvh(scene.root, 0);
		print_infinite(scene.inf_obj);
		free_scene(&scene);
		return (err);
	}
	print_scene(scene);
	print_bvh(scene.root, 0);
	print_infinite(scene.inf_obj);
	free_scene(&scene);
	// init_window(&mlx, av[1]);
	// mlx_hook(mlx.win, ON_KEYDOWN, 1L << 0, key_event, &mlx);
	// mlx_hook(mlx.win, ON_DESTROY, 1L << 17, cross_button_handler, &mlx);
	// mlx_loop(mlx.mlx);
	return (0);
}
