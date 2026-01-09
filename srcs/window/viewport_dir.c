/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:49:41 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/09 14:03:32 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim3.h"
#include "scene.h"

t_vect3	get_right(t_camera cam)
{
	t_vect3	right;
	t_vect3	tmp;
	t_vect3	up;

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
