/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:42:42 by cviel             #+#    #+#             */
/*   Updated: 2025/12/27 16:13:51 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ret_val.h"
#include "mlx.h"
#include "parsing.h"
#include "window.h"
#include "scene.h"
#include "color.h"

int	sphere_check(t_vect3 ray, t_sph sphere, t_pt3 *ptr_hit);

void	free_scene(t_scene *scene)
{
	free_obj(scene->obj);
}

void	print_sphere(t_vector vector_sph)
{
	size_t	i;

	i = 0;
	while (i < vector_sph.size)
	{
		printf("obj type = %d, center [%f,%f,%f], radius %f\n",
				((t_obj *)vector_sph.data)[i].type,
				((t_obj *)vector_sph.data)[i].shape.sphere.center.x,
				((t_obj *)vector_sph.data)[i].shape.sphere.center.y,
				((t_obj *)vector_sph.data)[i].shape.sphere.center.z,
				((t_obj *)vector_sph.data)[i].shape.sphere.radius);
		++i;
	}
}

void	print_cylinder(t_vector vector_cyl)
{
	size_t	i;

	i = 0;
	while (i < vector_cyl.size)
	{
		printf("obj type = %d, origin [%f,%f,%f], radius = %f, normal [%f,%f,%f], height = %f\n",
				((t_obj *)vector_cyl.data)[i].type,
				((t_obj *)vector_cyl.data)[i].shape.cyl.origin.x,
				((t_obj *)vector_cyl.data)[i].shape.cyl.origin.y,
				((t_obj *)vector_cyl.data)[i].shape.cyl.origin.z,
				((t_obj *)vector_cyl.data)[i].shape.cyl.radius,
				((t_obj *)vector_cyl.data)[i].shape.cyl.normal.x,
				((t_obj *)vector_cyl.data)[i].shape.cyl.normal.y,
				((t_obj *)vector_cyl.data)[i].shape.cyl.normal.z,
				((t_obj *)vector_cyl.data)[i].shape.cyl.height);
		++i;
	}
}

void	print_plane(t_vector vector_plane)
{
	size_t	i;
	
	i = 0;
	while (i < vector_plane.size)
	{
		printf("obj type = %d, coord [%f,%f,%f], normal vect [%f,%f,%f], color [%d,%d,%d]\n",
			((t_obj *)vector_plane.data)[i].type,
			((t_obj *)vector_plane.data)[i].shape.plane.origin.x,
			((t_obj *)vector_plane.data)[i].shape.plane.origin.y,
			((t_obj *)vector_plane.data)[i].shape.plane.origin.z,
			((t_obj *)vector_plane.data)[i].shape.plane.normal.x,
			((t_obj *)vector_plane.data)[i].shape.plane.normal.y,
			((t_obj *)vector_plane.data)[i].shape.plane.normal.z,
			((t_obj *)vector_plane.data)[i].color.r,
			((t_obj *)vector_plane.data)[i].color.g,
			((t_obj *)vector_plane.data)[i].color.b);
		++i;
	}
}

void	print_obj(t_vector *obj)
{
	print_sphere(obj[SPHERE]);
	print_cylinder(obj[CYLINDER]);
	print_plane(obj[PLANE]);
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

#include "ray.h"
int	main(int ac, char **av)
{
	int		err;
	t_mlx	mlx;
	t_scene	scene;

	err = parsing(ac, av, &scene);
	if (err)
	{
		print_scene(scene);
		print_obj(scene.obj);
		free_scene(&scene);
		print_error(err);
		return (err);
	}
	print_scene(scene);
	print_obj(scene.obj);
	// t_vect3	hit;
	// int	ret = sphere_check(scene.cam.dir,
	// 	((t_obj *)scene.obj[SPHERE].data)[0].shape.sphere, &hit);
	// printf("%d\n", ret);
	// if (ret == TRUE)
	// 	printf("%f %f %f\n", hit.x, hit.y, hit.z);
	free_scene(&scene);
	init_window(&mlx, av[1]);
	// raycast_loop(mlx, scene);
	display_background(&mlx, scene);
	mlx_hook(mlx.win, ON_KEYDOWN, 1L << 0, key_event, &mlx);
	mlx_hook(mlx.win, ON_DESTROY, 1L << 17, cross_button_handler, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
