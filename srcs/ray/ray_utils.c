/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:01:52 by mlouis            #+#    #+#             */
/*   Updated: 2025/11/25 11:59:51 by mlouis           ###   ########.fr       */
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

double	get_viewport_height(t_camera cam)
{
	// return (2 * tan((cam.fov / 2) * (M_PI / 180)));
	return (2 * tan(cam.fov / 2));
}

double	get_viewport_width(t_camera cam)
{
	return (RATIO * get_viewport_height(cam));
}
