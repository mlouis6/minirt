/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:46:04 by cviel             #+#    #+#             */
/*   Updated: 2025/10/20 19:06:53 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM4_H
# define DIM4_H

typedef	struct s_vect4
{
	float	x;
	float	y;
	float	z;
	float	t;
}	t_vect4;

typedef struct s_mat4
{
	float	coeff[4][4];
}	t_mat4;

t_mat4	mat4_add(t_mat4 m1, t_mat4 m2);
t_mat4	mat4_mult_nb(t_mat4 m, float lambda);
t_mat4	mat4_mult(t_mat4 m1, t_mat4 m2);
t_mat4	mat4_trans(t_mat4 m);
float	scalar4(t_vect4 v1, t_vect4 v2);
t_vect4	vect4_add(t_vect4 v1, t_vect4 v2);
t_vect4	vect4_mult_nb(t_vect4 v, float lambda);
t_vect4	mat4_mult_vect4(t_mat4 m, t_vect4 v);
t_vect4	vect4_mult_mat4(t_vect4 v, t_mat4 m);

#endif