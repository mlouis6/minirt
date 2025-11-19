/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:48:56 by mlouis            #+#    #+#             */
/*   Updated: 2025/11/19 18:34:55 by mlouis           ###   ########.fr       */
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

/** bool	hit_box(t_ray ray, t_box box)
// {
// 	double	t_enter;
// 	double	t_exit;

// 	t_enter = find_t_enter(ray, box);
// 	t_exit = find_t_exit(ray, box);
// 	if (t_enter <= t_exit && t_exit >= 0)
// 		return (true);
// 	else
// 		return (false);
// }

// // TODO: return closest_pl (maybe closest_t)
// //? add t from box if hit
// bool	hit_plane(t_ray r, t_vector pls[])
// {
// 	t_plane	closest_pl;
// 	t_plane pl;
// 	double	denom;
// 	double	t;
// 	double	closest_t;
// 	bool	hit;
// 	int		i;

// 	t = 0;
// 	hit = false;
// 	i = 0;
// 	while (i < NB_INF)
// 	{
// 		pl = ((t_obj *)pls[i].data)->shape.plane;
// 		denom = vect3_mult(pl.normal, r.dir);
// 		if (fabs(denom) < DBL_EPSILON)
// 			continue ;
// 		closest_t = t;
// 		t = vect3_mult(vect3_sub(pl.origin, r.origin), pl.normal) / denom;
// 		if (t > 0 && t < closest_t)
// 		{
// 			closest_t = t;
// 			closest_pl = pl;
// 			hit = true;
// 		}
// 		++i;
// 	}
// 	return (hit);
// } */
// TODO:
//** uncomment above */

// u -> right
// v -> right
// dir is forward
// void	raycast_loop(t_bvh *bvh, t_mlx mlx, t_scene scene) //! RT1week
// {
// 	int		i;
// 	int		j;
// 	t_vect3	vect_u;
// 	t_vect3	vect_v;
// 	double	u;
// 	double	v;
// 	t_ray	ray;
// 	static	double r_tmax = 1.0e30;
// 	double	vh = 2 * tan((scene.cam.fov * M_PI / 180) / 2);
// 	double	vw = vh * RATIO;
// 	t_vect3	vu = vect3_div_nb((t_vect3){vw,0,0}, 2);
// 	t_vect3 vv = vect3_div_nb((t_vect3){0, -vh, 0}, 2);
// 	t_pt3	up_left = vect3_sub(vect3_sub((t_vect3){0,0,-1}, vect3_div_nb(vu, 2)), vv);
// 	t_vect3	delta_u = vect3_div_nb(vu, WINDOW_WIDTH);
// 	t_vect3	delta_v = vect3_div_nb(vv, WINDOW_HEIGHT);
// 	t_pt3	anchor = vect3_add(up_left, vect3_div_nb(vect3_add(delta_u, delta_v), 2));

// 	j = 0;
// 	while (j < WINDOW_HEIGHT)
// 	{
// 		i = 0;
// 		while (i < WINDOW_WIDTH)
// 		{
// 			t_pt3 pix = vect3_add(anchor, vect3_add(vect3_mult_nb(delta_u, i), vect3_mult_nb(delta_v, j)));
// 			++i;
// 		}
// 		++j;
// 	}

// 	(void) bvh; (void) mlx;

// 	ray.origin = scene.cam.pos; // should be const
// 	ray.dir = vect3_normalize(vect3_sub(anchor, scene.cam.pos));
// 	ray.tmax = r_tmax;
// 	i = 0;
// 	// vp_h = 2 * tan(scene.cam.fov / 2);
// 	//forward = vect3_normalize(scene.cam.dir);
// 	vect_u = vect3_normalize(vect3_cross((t_vect3){0,1,0}, scene.cam.dir));
// 	vect_v = vect3_normalize(vect3_cross(vect_u, scene.cam.dir));
// 	while (i < VIEWPORT_HEIGHT)
// 	{
// 		j = 0;
// 		v = (i / WINDOW_HEIGHT - 0.5) * VIEWPORT_HEIGHT;
// 		while (j < VIEWPORT_WIDTH)
// 		{
// 			u = (j / WINDOW_WIDTH - 0.5) * VIEWPORT_WIDTH;
// 			// t = vect3_add(scene.cam.pos, //

// 			//! OLD STUFF TO MODIFY
// 			// ray.dir.x = j;
// 			// if (hit_bvh(ray, *bvh))
// 			// {
// 			// 	ray.tmax = find_t_exit(ray, bvh->box);
// 			// 	if (bvh->left)
// 			// 		raycast_loop(bvh->left, mlx, scene);
// 			// 	else if (bvh->right)
// 			// 		raycast_loop(bvh->right, mlx, scene);
// 			// 	else
// 			// 	{
// 			// 		// TODO: get object
// 			// 		// put_img_object(mlx.img, j, i, bvh->obj, scene);
// 			// 		// put_img_object();
// 			// 	}
// 			// 	if (hit_plane(ray, scene.planes))
// 			// 	{
// 			// 		// put color cause should be closer
// 			// 	}
// 			// }
// 			// // TODO: check for plane
// 			// // loop if multiple planes
// 			// put_img_ambient(mlx.img, j, i, scene.amb);
// 			//! END OLD STUFF
// 			++j;
// 		}
// 		++i;
// 	}
// }

// void	raycast_loop(t_bvh *bvh, t_mlx mlx, t_scene scene)
// {
// 	int		x;
// 	int		y;
// 	t_vect3	vect_u;
// 	t_vect3	vect_v;
// 	double	u;
// 	double	v;
// 	t_ray	ray;
// 	static	double r_tmax = 1.0e30;
// 	double	vh = 2 * tan((scene.cam.fov * M_PI / 180) / 2);
// 	double	vw = vh * RATIO;
// 	t_vect3	vu = vect3_div_nb((t_vect3){vw,0,0}, 2);
// 	t_vect3 vv = vect3_div_nb((t_vect3){0, -vh, 0}, 2);
// 	t_pt3	up_left = vect3_sub(vect3_sub((t_vect3){0,0,-1}, vect3_div_nb(vu, 2)), vv);
// 	t_vect3	delta_u = vect3_div_nb(vu, WINDOW_WIDTH);
// 	t_vect3	delta_v = vect3_div_nb(vv, WINDOW_HEIGHT);
// 	t_pt3	anchor = vect3_add(up_left, vect3_div_nb(vect3_add(delta_u, delta_v), 2));

// 	y = 0;
// 	while (y < WINDOW_HEIGHT)
// 	{
// 		x = 0;
// 		while (x < WINDOW_WIDTH)
// 		{
// 			t_pt3 pix = vect3_add(anchor, vect3_add(vect3_mult_nb(delta_u, x), vect3_mult_nb(delta_v, y)));
// 			++x;
// 		}
// 		++y;
// 	}

// 	(void) bvh; (void) mlx;

// 	ray.origin = scene.cam.pos; // should be const
// 	ray.dir = vect3_normalize(vect3_sub(anchor, scene.cam.pos));
// 	ray.tmax = r_tmax;

// 	// vp_h = 2 * tan(scene.cam.fov / 2);
// 	//forward = vect3_normalize(scene.cam.dir);
// 	vect_u = vect3_normalize(vect3_cross((t_vect3){0,1,0}, scene.cam.dir));
// 	vect_v = vect3_normalize(vect3_cross(vect_u, scene.cam.dir));
// 	while (i < VIEWPORT_HEIGHT)
// 	{
// 		j = 0;
// 		v = (i / WINDOW_HEIGHT - 0.5) * VIEWPORT_HEIGHT;
// 		while (j < VIEWPORT_WIDTH)
// 		{
// 			u = (j / WINDOW_WIDTH - 0.5) * VIEWPORT_WIDTH;
// 			// t = vect3_add(scene.cam.pos, //

// 			//! OLD STUFF TO MODIFY
// 			// ray.dir.x = j;
// 			// if (hit_bvh(ray, *bvh))
// 			// {
// 			// 	ray.tmax = find_t_exit(ray, bvh->box);
// 			// 	if (bvh->left)
// 			// 		raycast_loop(bvh->left, mlx, scene);
// 			// 	else if (bvh->right)
// 			// 		raycast_loop(bvh->right, mlx, scene);
// 			// 	else
// 			// 	{
// 			// 		// TODO: get object
// 			// 		// put_img_object(mlx.img, j, i, bvh->obj, scene);
// 			// 		// put_img_object();
// 			// 	}
// 			// 	if (hit_plane(ray, scene.planes))
// 			// 	{
// 			// 		// put color cause should be closer
// 			// 	}
// 			// }
// 			// // TODO: check for plane
// 			// // loop if multiple planes
// 			// put_img_ambient(mlx.img, j, i, scene.amb);
// 			//! END OLD STUFF
// 			++j;
// 		}
// 		++i;
// 	}
// }

static inline t_pt3	pt3_img_to_cam(double x, double y, double dist)
{
	return ((t_pt3) {x - VIEWPORT_WIDTH / 2, y - VIEWPORT_HEIGHT / 2, dist});
}

t_vect3	vect3_translate(t_vect3 v1, t_vect3 v2)
{
	t_vect3 res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

#include <stdio.h>
void	raycast_loop(t_bvh *bvh, t_mlx mlx, t_scene scene)
{
	(void) bvh; (void) mlx; (void) scene;
	// t_ray	ray;

	// ray.origin = scene.cam.pos; // O
	double	dist = 1; //focale
	// t_vect3	vp_center_from_cam = {0,0, dist};
	t_pt3	upper_left = pt3_img_to_cam(0, 0, dist);

	printf("======== VIEWPORT ========\n");
	printf("\t%.2fx%.2f\n", VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
	printf("[%.2f, %.2f, %.2f]\n", upper_left.x, upper_left.y, upper_left.z);
	t_pt3	rand_pt = pt3_img_to_cam(5, 3, dist);
	t_pt3	rand_ts = vect3_translate((t_vect3){-3,-2,1}, (t_vect3){VIEWPORT_WIDTH/2, VIEWPORT_HEIGHT/2, 0});
	printf("[%.2f, %.2f, %.2f]\n", rand_pt.x, rand_pt.y, rand_pt.z);
	printf("[%.2f, %.2f, %.2f]\n", rand_ts.x, rand_ts.y, rand_ts.z);
}