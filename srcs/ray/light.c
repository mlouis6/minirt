/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:38:20 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/16 16:22:29 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>
#include "scene.h"
#include "objects.h"
#include "dim3.h"
#include "ray.h"
#include "color.h"
#include "minirt.h"

int	check_hit_light(t_scene scene, t_obj *obj, double t, t_vect3 normal)
{
	obj->ray = init_ray_obj(t, scene, normal);
	if (!loop_objects(scene, &(obj->ray), NULL))
		return (true);
	return (false);
}

t_color_sum	init_color(t_ambient amb)
{
	t_color_sum	sum;

	sum.r = amb.color.r * amb.lightning / 255.0f;
	sum.g = amb.color.g * amb.lightning / 255.0f;
	sum.b = amb.color.b * amb.lightning / 255.0f;
	return (sum);
}

t_color_sum	add_obj_color(t_color_sum sum, t_obj obj)
{
	sum.r = obj.color.r * sum.r / 255.0f;
	sum.g = obj.color.g * sum.g / 255.0f;
	sum.b = obj.color.b * sum.b / 255.0f;
	return (sum);
}

t_color_sum	add_specular(t_color_sum sum, t_scene scene, t_obj obj,
	t_vect3 normal)
{
	t_vect3		reflexion;
	double		specular;

	reflexion = vect3_sub(vect3_mult(normal,
				vect3_dot(normal, obj.ray.dir) * 2), obj.ray.dir);
	specular = pow(fmax(0, vect3_dot(reflexion,
					vect3_normalize(vect3_sub(scene.cam.pos, obj.hit)))), 60);
	sum.r += scene.light.color.r * scene.light.brightness * specular / 255.0f;
	sum.g += scene.light.color.g * scene.light.brightness * specular / 255.0f;
	sum.b += scene.light.color.b * scene.light.brightness * specular / 255.0f;
	return (sum);
}

t_color_sum	add_light(t_color_sum sum, t_scene scene, t_obj obj, t_vect3 normal)
{
	double		diffusion;

	diffusion = fmax(0, vect3_dot(normal, obj.ray.dir));
	sum.r += diffusion * scene.light.color.r * scene.light.brightness / 255.0f;
	sum.g += diffusion * scene.light.color.g * scene.light.brightness / 255.0f;
	sum.b += diffusion * scene.light.color.b * scene.light.brightness / 255.0f;
	return (sum);
}
