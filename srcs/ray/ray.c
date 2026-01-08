/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:48:56 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/08 18:01:25 by mlouis           ###   ########.fr       */
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

t_pt3	ray_at(t_ray ray, double t)
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
	t_pt3	at;
	t_vect3	dir;
	int		length;

	at = ray_at(scene.ray, t - __FLT_EPSILON__);//1.0e-6);
	dir = vect3_sub(scene.light.pos, at);
	length = sqrt(pow(dir.x, 2) + pow(dir.y, 2) + pow(dir.z, 2));
	ray.tmax = length;
	ray.curr_t = ray.tmax;
	ray.origin = at;
	ray.dir = vect3_normalize(dir);
	return (ray);
}
#include <stdlib.h>

int	dispatch_func_call(t_type OBJ, t_scene scene, t_ray ray, size_t k, double *t)
{
	int	res;

	res = 0;
	if (OBJ == SPHERE)
	{
		res = sphere_check(ray,
				((t_obj *)scene.obj[SPHERE].data)[k].shape.sphere, t);
	}
	else if (OBJ == CYLINDER)
	{
		res = cylinder_check(ray,
				((t_obj *)scene.obj[CYLINDER].data)[k].shape.cyl, t);
	}
	else if (OBJ == PLANE)
	{
		res = plane_check(ray,
				((t_obj *)scene.obj[PLANE].data)[k].shape.plane, t);
	}
	return (res);
}

int	check_closest(double t, double *closest, t_obj **obj, t_obj *curr_obj)
{
	if (t < *closest)
	{
		*closest = t;
		if (obj != NULL)
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
	while (obj_type < NB_OBJ)
	{
		k = 0;
		while (k < scene.obj[obj_type].size)
		{
			res = dispatch_func_call(obj_type, scene, *ray, k, &t);
			if (res && check_closest(t, &(ray->tmax), obj,
					&((t_obj *)scene.obj[obj_type].data)[k]))
				hit = 1;
			++k;
		}
		++obj_type;
	}
	return (hit);
}
