/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:48:56 by mlouis            #+#    #+#             */
/*   Updated: 2025/11/10 16:21:33 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>
#include "ray.h"
#include "window.h"
#include "dim3.h"
#include "color.h"
#include "bvh.h"
#include "objects.h"

static inline t_pt3	ray_at(t_ray ray, double t)
{
	return (vect3_add(ray.origin, vect3_mult_nb(ray.dir, t)));
}

bool	hit_bvh(t_ray r, t_bvh bvh)
{
	t_pt3	at;
	int		i;

	i = bvh.box.z_min;
	while (i < bvh.box.z_max)
	{
		at = ray_at(r, i);
		if (at.x >= bvh.box.x_min && at.x <= bvh.box.x_max)
		{
			if (at.y >= bvh.box.y_min && at.y <= bvh.box.y_max)
			{
				if (at.z >= bvh.box.z_min && at.z <= bvh.box.z_max)
				{
					return (true);
				}
			}
		}
		++i;
	}
	return (false);
}

bool	hit_plane(t_ray r, t_lst *planes)
{
	t_pt3	at;
	t_plane	pl;
	double	denom;
	double	t;

	pl = *planes->content;
	while (*planes)
	{
		pl = *planes;
		denom = vect3_mult(pl.normal, r.dir);
		if (fabs(denom) > 0.0001f)
		{
			r. origin = vect3_mult_nb(r.origin, -1);
			t = vect3_mult(vect3_add(pl.origin, r.origin), pl.normal) / denom;
			if (t > 0)
				return (true);
		}
		*planes = planes->content.next;
	}
	return (false);
}

double	**calculate_t_axis(t_ray ray, t_box box, char axis)
{
	double	t[3][1];

	if (axis == 'x')
	{
		t[0][0] = (box.x_min - ray.origin.x) / ray.dir.x;
		t[0][1] = (box.x_max - ray.origin.x) / ray.dir.x;
	}
	else if (axis == 'y')
	{
		t[1][0] = (box.y_min - ray.origin.y) / ray.dir.y;
		t[1][1] = (box.y_max - ray.origin.y) / ray.dir.y;
	}
	else if (axis == 'z')
	{
		t[2][0] = (box.z_min - ray.origin.z) / ray.dir.z;
		t[2][1] = (box.z_max - ray.origin.z) / ray.dir.z;
	}
	return (t);
}

// double	calculate_t_axis(t_ray ray, t_box box, char axis)
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
// }

void	raycast_loop(t_bvh *bvh, t_mlx mlx, t_scene scene)
{
	int		i; //? static or if (hit_bvh) in another function
	int		j; //? static
	t_ray	ray;
	static	r_tmax = 1e30;
	double	t_enter;
	double	t_exit;

	ray.origin = scene.cam.pos; // should be const
	ray.dir.z = 1;
	ray.tmax = r_tmax;
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		ray.dir.y = i;
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			ray.dir.x = j;
			if (hit_bvh(ray, *bvh))
			{
				if (bvh->left)
					raycast_loop(bvh->left, mlx, scene);
				else if (bvh->right)
					raycast_loop(bvh->right, mlx, scene);
				else
				{
					put_img_object(mlx.img, j, i, bvh->obj, scene);
					// put_img_object();
				}
			}
			// TODO: check for plane
			// loop if multiple planes
			put_img_ambient(mlx.img, j, i, scene.amb);
			++j;
		}
		++i;
	}
}


