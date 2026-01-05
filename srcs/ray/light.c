/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:38:20 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/05 16:28:02 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ray.h"
#include <stdbool.h>

/**
 * check t with new t
 * (might hit itself right from the start)
 */
#include <stdio.h>

int	check_closest2(double t, double *closest)
{
	if (t < *closest)
	{
		*closest = t;
		return (true);
	}
	return (false);
}
#include <math.h>

int	loop_objects2(t_scene scene, t_ray *ray)
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
			res = dispatch_func_call(obj_type, scene, *ray, k, &t);
			if (res && check_closest2(t, &(ray->tmax)))
				hit = 1;
			++k;
		}
		++obj_type;
	}
	return (hit);
}

int	check_hit_light(t_scene scene, t_obj *obj, double t)
{
	obj->ray = init_ray_obj(t, scene);
	if (!loop_objects2(scene, &(obj->ray)))
		return (true);
	return (false);
}

t_color init_color(t_ambient amb)
{
	t_color	c;

	c.r = amb.color.r * amb.lightning;
	c.g = amb.color.g * amb.lightning;
	c.b = amb.color.b * amb.lightning;
	return (c);
}

t_color	add_obj_color(t_color c, t_obj obj)
{
	c.r = (obj.color.r * c.r) / 255.0;
	c.g = (obj.color.g * c.g) / 255.0;
	c.b = (obj.color.b * c.b) / 255.0;
	return (c);
}

void	vect3_print(char *name, t_vect3 v)
{
	printf("%s= [%.2f, %.2f, %.2f]\n", name, v.x, v.y, v.z);
}

t_color	add_light(t_color c, t_scene scene, t_obj obj)
{
	double	diffusion;
	t_vect3	normal;

	if (obj.type == PLANE)
	{
		normal = obj.shape.plane.normal;
		if (vect3_mult(normal, obj.ray.dir) < 0)
			normal = vect3_mult_nb(normal, -1);
	}
	else if (obj.type == CYLINDER)
		normal = obj.shape.cyl.normal;
	else
		normal = vect3_normalize(vect3_sub(obj.ray.origin, obj.shape.sphere.center));
		// normal = vect3_mult_nb(obj.ray.dir, 1 / obj.shape.sphere.radius);
	diffusion = vect3_mult(normal, vect3_normalize(obj.ray.dir));
	if (diffusion < 0)
		diffusion = 0;
	c.r *= scene.light.brightness * diffusion; 
	c.g *= scene.light.brightness * diffusion; 
	c.b *= scene.light.brightness * diffusion;
	return (c);
}

t_color	remove_color(t_color c)
{
	c.r = 0;
	c.g = 0;
	c.b = 0;
	return (c);
}
