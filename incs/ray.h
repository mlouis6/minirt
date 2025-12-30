/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:51:42 by mlouis            #+#    #+#             */
/*   Updated: 2025/12/30 15:25:43 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "dim3.h"

typedef	struct s_ray
{
	t_pt3	origin;
	t_vect3	dir;
	double	tmax;
	double	curr_t;
}	t_ray;

#endif
