/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:48:42 by cviel             #+#    #+#             */
/*   Updated: 2025/10/27 10:57:05 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

# include "objects.h"

typedef struct s_box
{
	float	x_min;
	float	x_max;
	float	y_min;
	float	y_max;
	float	z_min;
	float	z_max;
}	t_box;

typedef struct s_bvh
{
	t_obj			obj;
	t_box			box;
	struct s_bvh	*left;
	struct s_bvh	*right;
}	t_bvh;

#endif