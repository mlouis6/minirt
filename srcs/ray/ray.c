/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:48:56 by mlouis            #+#    #+#             */
/*   Updated: 2025/12/30 18:50:07 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>
// #include <float.h>
#include "ray.h"
#include "window.h"
#include "dim3.h"
#include "scene.h"
#include "objects.h"

static inline t_pt3	ray_at(t_ray ray, double t)
{
	return (vect3_add(ray.origin, vect3_mult_nb(ray.dir, t)));
}

t_ray	init_ray_cam(t_camera cam)
{
	t_ray	ray;

	ray.tmax = 1.0e30;
	ray.curr_t = ray.tmax;
	ray.origin = cam.pos;
	return (ray);
}
#include <stdio.h>

t_ray	init_ray_obj(double t, t_scene scene)
{
	t_ray	ray;
	t_vect3	dir;
	t_pt3	at;

	at = ray_at(scene.ray, t);
	dir.x = pow(scene.light.pos.x - at.x, 2);
	dir.y = pow(scene.light.pos.y - at.y, 2);
	dir.z = pow(scene.light.pos.z - at.z, 2);
	ray.tmax = 1.0e30; //sqrt(dir.x + dir.y + dir.z);
	ray.curr_t = ray.tmax;
	ray.origin = at;
	ray.dir = vect3_normalize(dir);
	// printf("DIREC-> [%.2f, %.2f, %.2f]\n", scene.ray.dir.x, scene.ray.dir.y, scene.ray.dir.z);
	// printf("RAYON-> [%.2f, %.2f, %.2f]\n", scene.ray.origin.x, scene.ray.origin.y, scene.ray.origin.z);
	// printf("TTTTT-> %.2f\n", t);
	return (ray);
}

int	dispatch_func_call(t_type OBJ, t_scene scene, size_t k, double *t)
{
	int	res;

	res = 0;
	if (OBJ == SPHERE)
	{
		res = sphere_check(scene.ray,
				((t_obj *)scene.obj[SPHERE].data)[k].shape.sphere, t);
	}
	else if (OBJ == CYLINDER)
	{
		res = cylinder_check(scene.ray,
				((t_obj *)scene.obj[CYLINDER].data)[k].shape.cyl, t);
	}
	else if (OBJ == PLANE)
	{
		res = plane_check(scene.ray,
				((t_obj *)scene.obj[PLANE].data)[k].shape.plane, t);
	}
	return (res);
}

int	check_closest(double t, double *closest, t_obj **obj, t_obj *curr_obj)
{
	if (t < *closest)
	{
		*closest = t;
		*obj = curr_obj;
		return (true);
	}
	return (false);
}

int	loop_objects(t_scene scene, t_ray *ray, t_obj **obj)
{
	size_t	k;
	t_type	obj_type;
	int		res;
	double	t;
	int		hit;

	obj_type = 0;
	hit = 0;
	while (obj_type < NB_TYPE)
	{
		k = 0;
		while (k < scene.obj[obj_type].size)
		{
			res = dispatch_func_call(obj_type, scene, k, &t);
			if (res && check_closest(t, &(ray->tmax), obj,
					&((t_obj *)scene.obj[obj_type].data)[k]))
				hit = 1;
			++k;
		}
		++obj_type;
	}
	return (hit);
}
