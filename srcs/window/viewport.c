/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:37:03 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/05 18:21:31 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
// #include <stdbool.h>
#include "mlx.h"
#include "scene.h"
#include "window.h"
#include "dim3.h"

double	get_viewport_width(t_camera cam)
{
	return (2 * tan((cam.fov / 2) * (M_PI / 180)));
}
double	get_viewport_height(t_camera cam)
{
	return (RATIO * get_viewport_width(cam));
	// return (2 * tan(cam.fov / 2));
}


t_vect3	get_right(t_camera cam)
{
	t_vect3	right;
	t_vect3	tmp;
	t_vect3	up;

	// TODO: vector orthogonal a la dir
	up = (t_vect3){0, 1, 0};
	tmp = vect3_cross(up, cam.dir);
	if (tmp.x == 0 && tmp.y == 0 && tmp.z == 0)
		tmp = vect3_cross((t_vect3){0, 0, 1}, cam.dir);
	right = vect3_normalize(tmp);
	return (right);
}

t_vect3	get_up(t_camera cam)
{
	return (vect3_cross(cam.dir, get_right(cam)));
}

t_pt3	get_vp_center(t_camera cam, double focale)
{
	t_pt3	center;

	center = vect3_add(cam.pos, vect3_mult_nb(cam.dir, focale));
	return (center);
}
#include <stdio.h>
t_pt3	get_vp_top_left(t_camera cam, double focale)
{
	t_pt3	vp_c;
	t_pt3	vp_tl;

	vp_c = get_vp_center(cam, focale);
	vp_tl = vect3_add(vect3_sub(vp_c,
				vect3_mult_nb(get_right(cam), get_viewport_width(cam)/ 2)),
			vect3_mult_nb(get_up(cam), get_viewport_height(cam) / 2));
	printf("VIEWPORT [%.2fx%.2f]\n", get_viewport_width(cam), get_viewport_height(cam));
	printf("top left [%.2f, %.2f, %.2f]\n", vp_tl.x, vp_tl.y, vp_tl.z);
	printf("right [%.2f, %.2f, %.2f]\n", get_right(cam).x, get_right(cam).y, get_right(cam).z);
	printf("up [%.2f, %.2f, %.2f]\n", get_up(cam).x, get_up(cam).y, get_up(cam).z);
	printf("dir [%.2f, %.2f, %.2f]\n", cam.dir.x, cam.dir.y, cam.dir.z);
	return (vp_tl);
}

t_vp	init_viewport(t_camera cam)
{
	t_vp	vp;

	vp.focale = 1.0;
	vp.height = get_viewport_height(cam);
	vp.width = get_viewport_width(cam);
	vp.top_left = get_vp_top_left(cam, vp.focale);
	return (vp);
}

t_pt3	pixel_to_vp_pt(t_scene scene, t_pxl win_pxl)
{
	t_pt3	vp_pt;

	vp_pt.z = 0;
	vp_pt.x = (win_pxl.x + 0.5) * scene.vp.width / WINDOW_WIDTH;
	vp_pt.y = (win_pxl.y + 0.5) * scene.vp.height / WINDOW_HEIGHT;
	vp_pt = vect3_add(scene.vp.top_left, vect3_sub(
				vect3_mult_nb(get_right(scene.cam), vp_pt.x),
				vect3_mult_nb(get_up(scene.cam), vp_pt.y)));
	return (vp_pt);
}
