/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:50:12 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/05 21:28:42 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdbool.h>
#include "mlx.h"
#include "scene.h"
#include "window.h"
#include <stdio.h>

void	display_scene(t_mlx *mlx, t_scene scene)
{
	t_pxl		win_pxl;
	t_obj		*obj;
	t_color		color;
	t_sum_color	sum;

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
			{
				sum = init_color(scene.amb);
				obj->hit = ray_at(scene.ray, scene.ray.tmax);
				if (check_hit_light(scene, obj, scene.ray.tmax))
					sum = add_light(sum, scene, *obj);
				sum = add_obj_color(sum, *obj);
				color = color_normalize(sum);
			}
			put_img(mlx->img, win_pxl, color);
			++(win_pxl.x);
		}
		++(win_pxl.y);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}
