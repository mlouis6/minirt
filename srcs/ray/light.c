/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:38:20 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/09 11:36:26 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ray.h"
#include <stdbool.h>
#include <math.h>

int	check_hit_light(t_scene scene, t_obj *obj, double t)
{
	obj->ray = init_ray_obj(t, scene);
	if (!loop_objects(scene, &(obj->ray), NULL))
		return (true);
	return (false);
}

t_vect3	orth(t_vect3 u, t_vect3 om);

t_color_sum init_color(t_ambient amb)
{
	t_color_sum	sum;

	sum.r = amb.color.r * amb.lightning / 255;
	sum.g = amb.color.g * amb.lightning / 255;
	sum.b = amb.color.b * amb.lightning / 255;
	return (sum);
}

t_color_sum get_specular(t_scene scene, t_obj obj, t_vect3 normal)
{
	t_vect3		reflexion;
	double		specular;
	t_color_sum	spec_c;

	reflexion = vect3_sub(vect3_mult_nb(normal, vect3_mult(normal, obj.ray.dir) * 2), obj.ray.dir);
	specular = pow(fmax(0, vect3_mult(reflexion, vect3_normalize(vect3_sub(scene.cam.pos, obj.hit)))), 40);
	// reflexion = vect3_sub(scene.ray.dir, vect3_mult_nb(normal, vect3_mult(scene.ray.dir, normal) * 2));
	// specular = pow(vect3_mult(obj_ray.dir, reflexion), 60);
	spec_c.r = scene.light.color.r * scene.light.brightness * specular / 255;
	spec_c.g = scene.light.color.g * scene.light.brightness * specular / 255;
	spec_c.b = scene.light.color.b * scene.light.brightness * specular / 255;
	return (spec_c);
}

t_color_sum	add_obj_color(t_color_sum sum, t_obj obj)
{
	sum.r = obj.color.r * sum.r / 255;
	sum.g = obj.color.g * sum.g / 255;
	sum.b = obj.color.b * sum.b / 255;
	return (sum);
}

#include <stdio.h>
t_color_sum	add_light(t_color_sum sum, t_scene scene, t_obj obj)
{
	double	diffusion;
	t_vect3	normal;
	t_color_sum	specular;

	if (obj.type == PLANE)
		normal = obj.shape.plane.normal;
	else if (obj.type == CYLINDER)
	{
		normal = vect3_sub(obj.hit, obj.shape.cyl.origin);
		normal = vect3_normalize(orth(obj.shape.cyl.normal, normal));
	}
	else
		normal = vect3_normalize(vect3_sub(obj.hit, obj.shape.sphere.center));
	if (vect3_mult(normal, vect3_sub(obj.hit, scene.cam.pos)) > 0)
			normal = vect3_mult_nb(normal, -1);
	diffusion = fmax(vect3_mult(normal, vect3_normalize(obj.ray.dir)), 0);
	specular = get_specular(scene, obj, normal);
	sum.r = sum.r * diffusion + specular.r;
	sum.g = sum.g * diffusion + specular.g;
	sum.b = sum.b * diffusion + specular.b;
	return (sum);
}
t_color	color_normalize(t_color_sum sum)
{
	t_color	color;

	color.r = fmin(sum.r, 1) * 255; //255 * sum.r / (double)(1 + sum.r);
	color.g = fmin(sum.g, 1) * 255; //255 * sum.g / (double)(1 + sum.g);
	color.b = fmin(sum.b, 1) * 255; //255 * sum.b / (double)(1 + sum.b);
	return (color);
}

