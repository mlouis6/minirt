/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:51:42 by mlouis            #+#    #+#             */
/*   Updated: 2025/11/10 14:59:54 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "objects.h"

typedef	struct s_ray
{
	t_pt3	origin;
	t_vect3	dir;
	double	tmax;
}	t_ray;

static inline t_pt3	ray_at(t_ray ray, double t);

#endif
