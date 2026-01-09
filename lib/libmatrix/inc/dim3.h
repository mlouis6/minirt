/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:45:52 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/09 14:44:15 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM3_H
# define DIM3_H

typedef struct s_vect3
{
	double	x;
	double	y;
	double	z;
}	t_vect3;

typedef t_vect3	t_pt3;

t_vect3	vect3_add(t_vect3 v1, t_vect3 v2);
t_vect3	vect3_mult_nb(t_vect3 v, double nb);
t_vect3	vect3_sub(t_vect3 v1, t_vect3 v2);
t_vect3	vect3_div_nb(t_vect3 v, double nb);

t_vect3	vect3_normalize(t_vect3 vect);
t_vect3	vect3_cross(t_vect3 v1, t_vect3 v2);
double	vect3_mult(t_vect3 v1, t_vect3 v2);
t_vect3	vect3_orth(t_vect3 u, t_vect3 om);

#endif