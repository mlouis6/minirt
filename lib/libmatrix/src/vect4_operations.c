/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect4_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:14:23 by cviel             #+#    #+#             */
/*   Updated: 2025/10/20 19:07:16 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "dim4.h"

float	scalar4(t_vect4 v1, t_vect4 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.t * v2.t);
}

t_vect4	vect4_add(t_vect4 v1, t_vect4 v2)
{
	t_vect4	res;

	res.x = v1.x + v2.x;	
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	res.t = v1.t + v2.t;
	return (res);
}

t_vect4	vect4_mult_nb(t_vect4 v, float lambda)
{
	t_vect4	res;

	res.x = lambda * v.x;	
	res.y = lambda * v.y;
	res.z = lambda * v.z;
	res.t = lambda * v.t;
	return (res);
}

t_vect4	mat4_mult_vect4(t_mat4 m, t_vect4 v)
{
	t_vect4	res;
	uint8_t	i;

	res.x += m.coeff[0][0] * v.x + m.coeff[0][1] * v.y \
			 + m.coeff[0][2] * v.z + m.coeff[0][3] * v.t;
	res.y += m.coeff[1][0] * v.x + m.coeff[1][1] * v.y \
			 + m.coeff[1][2] * v.z + m.coeff[1][3] * v.t;
	res.z += m.coeff[2][0] * v.x + m.coeff[2][1] * v.y \
			 + m.coeff[2][2] * v.z + m.coeff[2][3] * v.t;
	res.t += m.coeff[3][0] * v.x + m.coeff[3][1] * v.y \
			 + m.coeff[3][2] * v.z + m.coeff[3][3] * v.t;
	return (res);
}

t_vect4	vect4_mult_mat4(t_vect4 v, t_mat4 m)
{
	t_vect4	res;
	uint8_t	i;

	res.x += v.x * m.coeff[0][0] + v.y * m.coeff[1][0] \
			 + v.z * m.coeff[2][0] + v.t * m.coeff[3][0];
	res.y += v.x * m.coeff[0][1] + v.y * m.coeff[1][1] \
			 + v.z * m.coeff[2][1] + v.t * m.coeff[3][1];
	res.z += v.x * m.coeff[0][2] + v.y * m.coeff[1][2] \
			 + v.z * m.coeff[2][2] + v.t * m.coeff[3][2];
	res.t += v.x * m.coeff[0][3] + v.y * m.coeff[1][3] \
			 + v.z * m.coeff[2][3] + v.t * m.coeff[3][3];
	return (res);
}
