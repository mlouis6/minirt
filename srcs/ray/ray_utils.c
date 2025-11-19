/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:01:52 by mlouis            #+#    #+#             */
/*   Updated: 2025/11/19 17:54:50 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>
#include <float.h>
#include "ray.h"
#include "window.h"
#include "dim3.h"
#include "color.h"
#include "bvh.h"
#include "objects.h"

inline t_pt3	ray_at(t_ray ray, double t)
{
	return (vect3_add(ray.origin, vect3_mult_nb(ray.dir, t)));
}

// void	calculate_t_axis(double t[3][2], t_ray ray, t_box box)
// {
// 	t[0][0] = (box.x_min - ray.origin.x) / ray.dir.x;
// 	t[0][1] = (box.x_max - ray.origin.x) / ray.dir.x;
// 	t[1][0] = (box.y_min - ray.origin.y) / ray.dir.y;
// 	t[1][1] = (box.y_max - ray.origin.y) / ray.dir.y;
// 	t[2][0] = (box.z_min - ray.origin.z) / ray.dir.z;
// 	t[2][1] = (box.z_max - ray.origin.z) / ray.dir.z;
// }

// double	find_t_enter(t_ray ray, t_box box)
// {
// 	double	t[3][2];
// 	double	t_xmin;
// 	double	t_ymin;
// 	double	t_zmin;
// 	double	tmp_max;

// 	calculate_t_axis(t, ray, box);
// 	t_xmin = fmin(t[0][0], t[0][1]);
// 	t_ymin = fmin(t[1][0], t[1][1]);
// 	t_zmin = fmin(t[2][0], t[2][1]);
// 	tmp_max = fmax(t_xmin, t_ymin);
// 	return (fmax(tmp_max, t_zmin));
// }

// double	find_t_exit(t_ray ray, t_box box)
// {
// 	double	t[3][2];
// 	double	t_xmax;
// 	double	t_ymax;
// 	double	t_zmax;
// 	double	tmp_min;

// 	calculate_t_axis(t, ray, box);
// 	t_xmax = fmax(t[0][0], t[0][1]);
// 	t_ymax = fmax(t[1][0], t[1][1]);
// 	t_zmax = fmax(t[2][0], t[2][1]);
// 	tmp_min = fmin(t_xmax, t_ymax);
// 	return (fmin(tmp_min, t_zmax));
// }

inline double	get_viewport_height(t_camera cam)
{
	return (2 * tan((cam.fov / 2) * (M_PI / 180)));
}

inline double	get_viewport_width(t_camera cam)
{
	return (RATIO * get_viewport_height(cam));
}
