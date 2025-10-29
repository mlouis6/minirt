/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:02:40 by cviel             #+#    #+#             */
/*   Updated: 2025/10/28 15:43:20 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# define t_vect3 t_pt3
# define NB_TYPES 3

# include "dim3.h"
# include "color.h"
# include "parsing.h"

// static const t_func g_table_obj[NB_TYPES] = {
// 	{"sp", fill_sphere_info},
// 	{"pl", fill_plane_info},
// 	{"cy", fill_cylinder_info},
// };

typedef enum e_type
{
	PLANE,
	SPHERE,
	CYLINDER,
	NONE
}	t_type;

typedef struct s_sph
{
	t_pt3	center;
	float	radius;
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
	float	radius;
	float	height;
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