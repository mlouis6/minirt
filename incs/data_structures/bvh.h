/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:48:42 by cviel             #+#    #+#             */
/*   Updated: 2025/11/03 21:43:05 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

# define NB_FINITE 2

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
	int				nb_leaves;
	struct s_bvh	*left;
	struct s_bvh	*right;
}	t_bvh;

t_box	box_regroup(t_box box1, t_box box2);
t_box	box_sphere(t_shape shape);
t_box	box_cylinder(t_shape shape);

static	t_box (*const g_box_finder[NB_FINITE])(t_shape) = 
{
	box_sphere,
	box_cylinder
};

#endif