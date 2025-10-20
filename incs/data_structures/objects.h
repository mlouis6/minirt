/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:02:40 by cviel             #+#    #+#             */
/*   Updated: 2025/10/13 17:40:41 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

typedef enum e_type
{
	PLANE,
	SPHERE,
	CYLINDER
}	t_type;

typedef struct s_sph
{
	t_pt			center;
	float			radius;
	unsigned char	color[3];
}	t_sph;

typedef struct s_plane
{
	t_pt			origin;
	t_vect			normal;
	unsigned char	color[3];
}	t_plane;

typedef struct s_cyl
{
	t_pt	origin;
	t_vect	normal;
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