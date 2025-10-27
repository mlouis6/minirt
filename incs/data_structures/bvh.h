/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:48:42 by cviel             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/10/24 22:17:38 by cviel            ###   ########.fr       */
=======
/*   Updated: 2025/10/27 10:57:05 by mlouis           ###   ########.fr       */
>>>>>>> 4187963ce0eecab090d054d0548e9e1a3a7bda87
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

<<<<<<< HEAD
#include "objects.h"
=======
# include "objects.h"
>>>>>>> 4187963ce0eecab090d054d0548e9e1a3a7bda87

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