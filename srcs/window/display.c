/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:50:12 by mlouis            #+#    #+#             */
/*   Updated: 2025/12/29 19:07:59 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdbool.h>
#include "mlx.h"
#include "scene.h"
#include "window.h"

void	display_scene(t_mlx *mlx, t_scene scene)
{
	t_pxl	win_pxl;
	t_obj	*obj;

	obj = NULL;
	complete_scene(&scene);
	win_pxl.y = 0;
	while (win_pxl.y < WINDOW_HEIGHT)
	{
		win_pxl.x = 0;
		while (win_pxl.x < WINDOW_WIDTH)
		{
			scene.vp.curr_pt = pixel_to_vp_pt(scene, win_pxl);
			scene.ray.dir = vect3_normalize(
					vect3_sub(scene.vp.curr_pt, scene.ray.origin));
			if (loop_objects(scene, &scene.ray, &obj))
				put_img_object(mlx->img, win_pxl, *obj, scene);
			else
				put_img_ambient(mlx->img, win_pxl, scene.amb);
			++(win_pxl.x);
		}
		++(win_pxl.y);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}
