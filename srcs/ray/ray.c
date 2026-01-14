/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:48:56 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/14 18:26:01 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>
#include "minirt.h"
#include "scene.h"
#include "ray.h"
#include "dim3.h"

t_ray	init_ray_cam(t_camera cam)
{
	t_ray	ray;

	ray.tmax = INFINITY;
	ray.curr_t = ray.tmax;
	ray.origin = cam.pos;
	return (ray);
}

t_ray	init_ray_obj(double t, t_scene scene)
{
	t_ray	ray;
	t_pt3	at;
	t_vect3	dir;
	int		length;

	at = vect3_add(scene.ray.origin,
			vect3_mult(scene.ray.dir, t));
	dir = vect3_sub(scene.light.pos, at);
	length = sqrt(pow(dir.x, 2) + pow(dir.y, 2) + pow(dir.z, 2));
	ray.tmax = length;
	ray.curr_t = ray.tmax;
	ray.origin = at;
	ray.dir = vect3_normalize(dir);
	return (ray);
}

static double	dispatch_func(t_type OBJ, t_scene scene, t_ray ray, size_t i)
{
	int		res;
	double	t;

	t = -1;
	res = 0;
	if (OBJ == SPHERE)
	{
		res = sphere_check(ray,
				((t_obj *)scene.obj[SPHERE].data)[i].shape.sphere, &t);
	}
	else if (OBJ == CYLINDER)
	{
		res = cylinder_check(ray,
				((t_obj *)scene.obj[CYLINDER].data)[i].shape.cyl, &t);
	}
	else if (OBJ == PLANE)
	{
		res = plane_check(ray,
				((t_obj *)scene.obj[PLANE].data)[i].shape.plane, &t);
	}
	if (res == 0)
		t = -1;
	return (t);
}

static int	check_closest(double t, double *closest, t_obj **obj, t_obj *curr)
{
	if (t < *closest)
	{
		*closest = t;
		if (obj != NULL)
			*obj = curr;
		return (true);
	}
	return (false);
}

int	loop_objects(t_scene scene, t_ray *ray, t_obj **obj)
{
	size_t	i;
	t_type	obj_type;
	double	t;
	int		hit;

	obj_type = 0;
	hit = 0;
	while (obj_type < NB_OBJ)
	{
		i = 0;
		while (i < scene.obj[obj_type].size)
		{
			t = dispatch_func(obj_type, scene, *ray, i);
			if (t > -1 && check_closest(t, &(ray->tmax), obj,
					&((t_obj *)scene.obj[obj_type].data)[i]))
				hit = 1;
			++i;
		}
		++obj_type;
	}
	return (hit);
}
