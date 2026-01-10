/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:50:12 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/09 19:16:23 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdbool.h>
#include "mlx.h"
#include "scene.h"
#include "window.h"
#include <stdio.h>

t_color	color_object(t_scene scene, t_obj *obj)
{
	t_color_sum	sum;

	sum = init_color(scene.amb);
	obj->hit = vect3_add(scene.ray.origin,
			vect3_mult_nb(scene.ray.dir, scene.ray.tmax));
	sum = add_obj_color(sum, *obj);
	if (check_hit_light(scene, obj, scene.ray.tmax))
		sum = add_light(sum, scene, *obj);
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
