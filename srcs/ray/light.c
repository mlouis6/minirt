/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:38:20 by mlouis            #+#    #+#             */
/*   Updated: 2025/12/31 16:17:52 by mlouis           ###   ########.fr       */
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
int	loop_objects2(t_scene scene, t_ray *ray, t_obj obj)
{
	size_t	k;
	t_type	obj_type;
	int		res;
	double	t;
	int		hit;

	obj_type = 0;
	hit = 0;
	// check obj passed and get farthest t
	while (obj_type < NB_TYPE)
	{
		k = 0;
		while (k < scene.obj[obj_type].size)
		{
			// if obj == obj continue ;
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

t_color	add_light(t_color c, t_scene scene, t_obj obj)
{
	double	disp;

	disp = vect3_mult(scene.ray.dir, obj.ray.dir);
	if (disp < 0)
	{
		// disp = 0;
		c.r = 0; 
		c.g = 255; 
		c.b = 0;
	}
	else {
		c.r *= scene.light.brightness * disp; 
		c.g *= scene.light.brightness * disp; 
		c.b *= scene.light.brightness * disp;

	}
	return (c);
}

t_color	remove_color(t_color c)
{
	c.r = 224; 
	c.g = 33; 
	c.b = 128;
	return (c);
}
