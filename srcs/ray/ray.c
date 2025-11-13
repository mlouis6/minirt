/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:48:56 by mlouis            #+#    #+#             */
/*   Updated: 2025/11/13 14:34:38 by mlouis           ###   ########.fr       */
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

// static inline t_pt3	ray_at(t_ray ray, double t)
// {
// 	return (vect3_add(ray.origin, vect3_mult_nb(ray.dir, t)));
// }

void	calculate_t_axis(double t[3][2], t_ray ray, t_box box)
{
	t[0][0] = (box.x_min - ray.origin.x) / ray.dir.x;
	t[0][1] = (box.x_max - ray.origin.x) / ray.dir.x;
	t[1][0] = (box.y_min - ray.origin.y) / ray.dir.y;
	t[1][1] = (box.y_max - ray.origin.y) / ray.dir.y;
	t[2][0] = (box.z_min - ray.origin.z) / ray.dir.z;
	t[2][1] = (box.z_max - ray.origin.z) / ray.dir.z;
}

double	find_t_enter(t_ray ray, t_box box)
{
	double	t[3][2];
	double	t_xmin;
	double	t_ymin;
	double	t_zmin;
	double	tmp_max;

	calculate_t_axis(t, ray, box);
	t_xmin = fmin(t[0][0], t[0][1]);
	t_ymin = fmin(t[1][0], t[1][1]);
	t_zmin = fmin(t[2][0], t[2][1]);
	tmp_max = fmax(t_xmin, t_ymin);
	return (fmax(tmp_max, t_zmin));
}

double	find_t_exit(t_ray ray, t_box box)
{
	double	t[3][2];
	double	t_xmax;
	double	t_ymax;
	double	t_zmax;
	double	tmp_min;

	calculate_t_axis(t, ray, box);
	t_xmax = fmax(t[0][0], t[0][1]);
	t_ymax = fmax(t[1][0], t[1][1]);
	t_zmax = fmax(t[2][0], t[2][1]);
	tmp_min = fmin(t_xmax, t_ymax);
	return (fmin(tmp_min, t_zmax));
}

bool	hit_box(t_ray ray, t_box box)
{
	double	t_enter;
	double	t_exit;

	t_enter = find_t_enter(ray, box);
	t_exit = find_t_exit(ray, box);
	if (t_enter <= t_exit && t_exit >= 0)
		return (true);
	else
		return (false);
}

//! HERERERERE
// TODO: add to libmatrix
t_vect3	vect3_sub(t_vect3 v1, t_vect3 v2)
{
	t_vect3	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.x = v1.x - v2.x;
	return (res);
}

// TODO: return closest_pl (maybe closest_t)
//? add t from box if hit
bool	hit_plane(t_ray r, t_vector pls[])
{
	t_plane	closest_pl;
	t_plane pl;
	double	denom;
	double	t;
	double	closest_t;
	bool	hit;
	int		i;

	t = 0;
	hit = false;
	i = 0;
	while (i < NB_INF)
	{
		pl = ((t_obj *)pls[i].data)->shape.plane;
		denom = vect3_mult(pl.normal, r.dir);
		if (fabs(denom) < DBL_EPSILON)
			continue ;
		closest_t = t;
		t = vect3_mult(vect3_sub(pl.origin, r.origin), pl.normal) / denom;
		if (t > 0 && t < closest_t)
		{
			closest_t = t;
			closest_pl = pl;
			hit = true;
		}
		++i;
	}
	return (hit);
}

// TODO: pray it's not needed
// double	calculate_t_axis_minmax(t_ray ray, t_box box, char axis, bool need_max)
// {
// 	double	t1;
// 	double	t2;

// 	if (axis == 'x')
// 	{
// 		t1 = (box.x_min - ray.origin.x) / ray.dir.x;
// 		t2 = (box.x_max - ray.origin.x) / ray.dir.x;
// 	}
// 	else if (axis == 'y')
// 	{
// 		t1 = (box.y_min - ray.origin.y) / ray.dir.y;
// 		t2 = (box.y_max - ray.origin.y) / ray.dir.y;
// 	}
// 	else if (axis == 'z')
// 	{
// 		t1 = (box.z_min - ray.origin.z) / ray.dir.z;
// 		t2 = (box.z_max - ray.origin.z) / ray.dir.z;
// 	}
// 	if (need_max)
// 		return (fmax(t1, t2));
// 	else
// 		return (fmin(t1, t2));
// }


// static inline double	get_viewport_height(t_camera cam)
// {
// 	return (2 * tan((cam.fov / 2) * (M_PI / 180)));
// }

// static inline double	get_viewport_width(t_camera cam)
// {
// 	return (RATIO * get_viewport_height(cam));
// }

void	raycast_loop(t_bvh *bvh, t_mlx mlx, t_scene scene)
{
	int		i;
	int		j;
	double	u;
	double	v;
	t_ray	ray;
	static	double r_tmax = 1.0e30;
	// double	t_enter;
	// double	t_exit;
	(void) bvh; (void) mlx;
	// double	t;

	ray.origin = scene.cam.pos; // should be const
	ray.dir.z = 1;
	ray.tmax = r_tmax;
	i = 0;
	// vp_h = 2 * tan(scene.cam.fov / 2);
	while (i < VIEWPORT_HEIGHT)
	{
		j = 0;
		v = (i / WINDOW_HEIGHT - 0.5) * VIEWPORT_HEIGHT;
		while (j < VIEWPORT_WIDTH)
		{
			u = (j / WINDOW_WIDTH - 0.5) * VIEWPORT_WIDTH;
			// t = vect3_add(scene.cam.pos, //

			//! OLD STUFF TO MODIFY
			// ray.dir.x = j;
			// if (hit_bvh(ray, *bvh))
			// {
			// 	ray.tmax = find_t_exit(ray, bvh->box);
			// 	if (bvh->left)
			// 		raycast_loop(bvh->left, mlx, scene);
			// 	else if (bvh->right)
			// 		raycast_loop(bvh->right, mlx, scene);
			// 	else
			// 	{
			// 		// TODO: get object
			// 		// put_img_object(mlx.img, j, i, bvh->obj, scene);
			// 		// put_img_object();
			// 	}
			// 	if (hit_plane(ray, scene.planes))
			// 	{
			// 		// put color cause should be closer
			// 	}
			// }
			// // TODO: check for plane
			// // loop if multiple planes
			// put_img_ambient(mlx.img, j, i, scene.amb);
			//! END OLD STUFF
			++j;
		}
		++i;
	}
}


