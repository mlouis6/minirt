/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:48:42 by cviel             #+#    #+#             */
/*   Updated: 2025/10/24 18:22:32 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

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
	t_obj			obj
	t_box			box;
	struct s_bvh	*left;
	struct s_bvh	*right;
}	t_bvh;

#endif