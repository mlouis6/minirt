/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:37:03 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/09 14:03:16 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scene.h"
#include "dim3.h"

static double	get_viewport_width(t_camera cam)
{
	return (2 * tan((cam.fov / 2) * (M_PI / 180)));
}

static double	get_viewport_height(t_camera cam)
{
	return (RATIO * get_viewport_width(cam));
}

static t_pt3	get_vp_top_left(t_camera cam, double focale)
{
	t_pt3	vp_c;
	t_pt3	vp_tl;

	vp_c = get_vp_center(cam, focale);
	vp_tl = vect3_add(vect3_sub(vp_c,
				vect3_mult_nb(get_right(cam), get_viewport_width(cam) / 2)),
			vect3_mult_nb(get_up(cam), get_viewport_height(cam) / 2));
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
