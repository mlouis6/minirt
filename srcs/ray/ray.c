/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:48:56 by mlouis            #+#    #+#             */
/*   Updated: 2025/11/05 15:58:53 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ray.h"
#include "window.h"
#include "dim3.h"
#include "color.h"
#include "bvh.h"

static inline t_pt3	ray_at(t_ray ray, double t)
{
	return (vect3_add(ray.origin, vect3_mult_nb(ray.dir, t)));
}

bool	hit_bvh(t_ray r, t_bvh bvh)
{
	t_pt3	at;
	int		i;

	i = 0;
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

void	raycast_loop(t_bvh *bvh, t_mlx mlx, t_scene scene)
{
	int		i; //? static or if (hit_bvh) in another function
	int		j; //? static
	t_ray	ray;

	ray.origin = scene.cam.pos; // should be const
	ray.dir.z = 1;
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
			put_img_ambient(mlx.img, j, i, scene.amb);
			++j;
		}
		++i;
	}
}
