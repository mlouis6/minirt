/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:45:52 by mlouis            #+#    #+#             */
/*   Updated: 2025/12/18 11:15:41 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM3_H
# define DIM3_H

# include <unistd.h>
# include <inttypes.h>

#define t_pt3 t_vect3

/** MATRIX 3 */
typedef struct s_mat3
{
	float	coeff[3][3];
}	t_mat3;

t_mat3	mat3_add(t_mat3 mx1, t_mat3 mx2);
t_mat3	mat3_mult_nb(t_mat3 mx, float nb);
t_mat3	mat3_mult(t_mat3 mx1, t_mat3 mx2);
t_mat3	mat3_trans(t_mat3 mx);

/** VECTOR */
typedef struct s_vect3
{
	double	x;
	double	y;
	double	z;
}	t_vect3;

t_vect3	vect3_add(t_vect3 v1, t_vect3 v2);
t_vect3	vect3_mult_nb(t_vect3 v, double nb);
double	vect3_mult(t_vect3 v1, t_vect3 v2);
t_vect3	mat3_mult_vect3(t_mat3 mx, t_vect3 v);

t_vect3	vect3_sub(t_vect3 v1, t_vect3 v2);
t_vect3	vect3_normalize(t_vect3 vect);
t_vect3 vect3_cross(t_vect3 v1, t_vect3 v2);
t_vect3	vect3_div_nb(t_vect3 v, double nb);

#endif