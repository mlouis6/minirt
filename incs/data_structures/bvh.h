/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:48:42 by cviel             #+#    #+#             */
/*   Updated: 2025/10/31 20:45:31 by cviel            ###   ########.fr       */
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
	int				nb_leaves;
	struct s_bvh	*left;
	struct s_bvh	*right;
}	t_bvh;

static const	t_box (*g_box_finder[NB_TYPES])(t_shape) = {
	box_sphere, \
	box_cylinder
};

t_box	box_regroup(t_box box1, t_box box2);


#endif