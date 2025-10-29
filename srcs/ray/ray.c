/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:48:56 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/29 15:38:01 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "window.h"

static inline t_pt3	ray_at(t_ray ray, double t)
{
	return (vect3_add(ray.origin, vect3_mult_nb(ray.dir, t)));
}

