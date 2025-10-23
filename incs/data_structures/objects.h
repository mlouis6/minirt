/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:02:40 by cviel             #+#    #+#             */
/*   Updated: 2025/10/23 17:45:36 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# define t_vect3 t_pt3

# include "dim3.h"

typedef enum e_type
{
	PLANE,
	SPHERE,
	CYLINDER
}	t_type;

typedef struct s_sph
{
	t_pt3			center;
	float			radius;
	unsigned char	color[3];
}	t_sph;

typedef struct s_plane
{
	t_pt3			origin;
	t_vect3			normal;
	unsigned char	color[3];
}	t_plane;

typedef struct s_cyl
{
	t_pt3	origin;
	t_vect3	normal;
	float	radius;
	float	height;
}	t_cyl;

typedef union u_obj
{
	t_type	type;
	t_sph	sphere;
	t_plane	plane;
	t_cyl	cyl;
}	t_obj;

#endif