/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:38:20 by mlouis            #+#    #+#             */
/*   Updated: 2025/12/30 18:46:17 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ray.h"
#include <stdbool.h>

/**
 * check t with new t
 * (might hit itself right from the start)
 */
int	check_hit_light(t_scene scene, t_obj *obj, double t)
{
	obj->ray = init_ray_obj(t, scene);
	if (loop_objects(scene, &(obj->ray), &obj))
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
	c.r = obj.color.r * c.r / 255;
	c.g = obj.color.g * c.g / 255;
	c.b = obj.color.b * c.b / 255;
	return (c);
}
#include <stdio.h>
t_color	add_light(t_color c, t_scene scene, t_obj obj)
{
	double	disp;

	disp = vect3_mult(scene.ray.dir, obj.ray.dir);
	// printf("SCENE-> [%.2f, %.2f, %.2f]\n", scene.ray.dir.x, scene.ray.dir.y, scene.ray.dir.z);
	// printf("OBJET-> [%.2f, %.2f, %.2f]\n", obj.ray.dir.x, obj.ray.dir.y, obj.ray.dir.z);
	
	if (disp < 0)
		disp = 0;	
	c.r *= scene.light.brightness * disp; 
	c.g *= scene.light.brightness * disp; 
	c.b *= scene.light.brightness * disp;
	return (c);
}
