/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:38:20 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/08 17:41:32 by cviel            ###   ########.fr       */
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
	while (obj_type < NB_OBJ)
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

t_color_sum init_color(t_ambient amb)
{
	t_color_sum	sum;

	sum.r = amb.color.r * amb.lightning / 255.0f;
	sum.g = amb.color.g * amb.lightning / 255.0f;
	sum.b = amb.color.b * amb.lightning / 255.0f;
	return (sum);
}

t_color_sum	add_obj_color(t_color_sum sum, t_obj obj)
{
	sum.r = obj.color.r * sum.r / 255;
	sum.g = obj.color.g * sum.g / 255;
	sum.b = obj.color.b * sum.b / 255;
	return (sum);
}

void	vect3_print(char *name, t_vect3 v)
{
	printf("%s= [%.2f, %.2f, %.2f]\n", name, v.x, v.y, v.z);
}

t_vect3	orth(t_vect3 u, t_vect3 om);

t_color_sum	add_light(t_color_sum sum, t_scene scene, t_obj obj)
{
	double	diffusion;
	t_vect3	normal;

	if (obj.type == PLANE)
		normal = obj.shape.plane.normal;
	else if (obj.type == CYLINDER)
	{
		normal = vect3_sub(obj.hit, obj.shape.cyl.origin);
		normal = vect3_normalize(orth(obj.shape.cyl.normal, normal));
	}
	else
	{
		normal = vect3_normalize(vect3_sub(obj.hit, obj.shape.sphere.center));
		// normal = vect3_mult_nb(obj.ray.dir, 1 / obj.shape.sphere.radius);
	}
	if (vect3_mult(normal, vect3_sub(obj.hit, scene.cam.pos)) > 0)
			normal = vect3_mult_nb(normal, -1);
	diffusion = vect3_mult(normal, vect3_normalize(obj.ray.dir));
	if (diffusion < 0)
		diffusion = 0;
	sum.r += scene.light.color.r * scene.light.brightness * diffusion / 255;
	sum.g += scene.light.color.g * scene.light.brightness * diffusion / 255;
	sum.b += scene.light.color.b * scene.light.brightness * diffusion / 255;
	return (sum);
}

t_color	color_normalize(t_color_sum sum)
{
	t_color	color;

	color.r = 255 * sum.r / (double)(1 + sum.r);
	color.g = 255 * sum.g / (double)(1 + sum.g);
	color.b = 255 * sum.b / (double)(1 + sum.b);
	return (color);
}

// t_color	remove_color(t_color c)
// {
// 	c.r = 0;
// 	c.g = 0;
// 	c.b = 0;
// 	return (c);
// }
