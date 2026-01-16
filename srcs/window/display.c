/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:50:12 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/16 20:06:47 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "mlx.h"
#include "minirt.h"
#include "scene.h"
#include "objects.h"
#include "color.h"
#include "window.h"

static t_vect3	get_normal(t_scene scene, t_obj *obj)
{
	t_vect3		normal;

	if (obj->type == PLANE)
		normal = obj->shape.plane.normal;
	else if (obj->type == CYLINDER)
	{
		normal = vect3_sub(obj->hit, obj->shape.cyl.origin);
		normal = vect3_normalize(vect3_orth(obj->shape.cyl.normal, normal));
	}
	else
		normal = vect3_normalize(vect3_sub(obj->hit, obj->shape.sphere.center));
	if (vect3_dot(normal, vect3_sub(obj->hit, scene.cam.pos)) > 0)
		normal = vect3_mult(normal, -1);
	return (normal);
}

t_color	color_object(t_scene scene, t_obj *obj)
{
	t_color_sum	sum;
	t_vect3		normal;
	bool		hit_light;

	obj->hit = vect3_add(scene.ray.origin,
			vect3_mult(scene.ray.dir, scene.ray.tmax));
	normal = get_normal(scene, obj);
	sum = init_color(scene.amb);
	hit_light = check_hit_light(scene, obj, scene.ray.tmax, normal);
	if (hit_light)
		sum = add_light(sum, scene, *obj, normal);
	sum = add_obj_color(sum, *obj);
	if (hit_light)
		sum = add_specular(sum, scene, *obj, normal);
	return (color_normalize(sum));
}

void	display_scene(t_mlx *mlx, t_scene scene)
{
	t_pxl		win_pxl;
	t_obj		*obj;
	t_color		color;

	obj = NULL;
	scene.vp = init_viewport(scene.cam);
	win_pxl.y = 0;
	while (win_pxl.y < WINDOW_HEIGHT)
	{
		win_pxl.x = 0;
		while (win_pxl.x < WINDOW_WIDTH)
		{
			scene.ray = init_ray_cam(scene.cam);
			scene.vp.curr_pt = pixel_to_vp_pt(scene, win_pxl);
			scene.ray.dir = vect3_normalize(
					vect3_sub(scene.vp.curr_pt, scene.ray.origin));
			color = (t_color){0, 0, 0};
			if (loop_objects(scene, &scene.ray, &obj))
				color = color_object(scene, obj);
			put_img(mlx->img, win_pxl, color);
			++(win_pxl.x);
		}
		++(win_pxl.y);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}
