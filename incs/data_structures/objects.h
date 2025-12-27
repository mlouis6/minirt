/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:02:40 by cviel             #+#    #+#             */
/*   Updated: 2025/12/15 17:16:31 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# define NB_OBJ 3

# include "dim3.h"
# include "color.h"

typedef enum e_type
{
	SPHERE = 0,
	CYLINDER,
	PLANE
}	t_type;

typedef struct s_sph
{
	t_pt3	center;
	double	radius;
}	t_sph;

typedef struct s_plane
{
	t_pt3	origin;
	t_vect3	normal;
}	t_plane;

typedef struct s_cyl
{
	t_pt3	origin;
	t_vect3	normal;
	double	radius;
	double	height;
}	t_cyl;

typedef union u_shape
{
	t_sph	sphere;
	t_plane	plane;
	t_cyl	cyl;
}	t_shape;

typedef struct s_obj
{
	t_type	type;
	t_shape	shape;
	t_color	color;
}	t_obj;

#endif