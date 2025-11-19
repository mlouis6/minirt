/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:51:42 by mlouis            #+#    #+#             */
/*   Updated: 2025/11/19 18:08:16 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "window.h"
# include "objects.h"
# include "scene.h"

typedef	struct s_ray
{
	t_pt3	origin;
	t_vect3	dir;
	double	tmax;
}	t_ray;

inline t_pt3	ray_at(t_ray ray, double t);
// void	calculate_t_axis(double t[3][2], t_ray ray, t_box box);
// double	find_t_enter(t_ray ray, t_box box);
// double	find_t_exit(t_ray ray, t_box box);
inline double	get_viewport_height(t_camera cam);
inline double	get_viewport_width(t_camera cam);


void	raycast_loop(t_bvh *bvh, t_mlx mlx, t_scene scene);

#endif
