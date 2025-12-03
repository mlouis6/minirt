/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:15:25 by mlouis            #+#    #+#             */
/*   Updated: 2025/12/03 14:03:01 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim3.h"
#include <math.h>
//mat4 * vect4

t_vect3	vect3_add(t_vect3 v1, t_vect3 v2)
{
	t_vect3	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vect3	vect3_mult_nb(t_vect3 v, double nb)
{
	t_vect3	res;

	res.x = v.x * nb;
	res.y = v.y * nb;
	res.z = v.z * nb;
	return (res);
}

double	vect3_mult(t_vect3 v1, t_vect3 v2) //? dot
{
	double	res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}

t_vect3	mat3_mult_vect3(t_mat3 mx, t_vect3 v)
{
	t_vect3	res;
	uint8_t	i;
	double	*ptr;		

	i = 0;
	ptr = (double *)&v;
	while (i < 3)
	{
		res.x += mx.coeff[0][i] * ptr[i];
		res.y += mx.coeff[1][i] * ptr[i];
		res.z += mx.coeff[2][i] * ptr[i];
		++i;
	}
	return (res);
}

t_vect3	vect3_sub(t_vect3 v1, t_vect3 v2)
{
	t_vect3	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	return (res);
}

t_vect3	vect3_normalize(t_vect3 vect)
{
	t_vect3	v_norm;
	int		length;

	length = sqrt(pow(vect.x, 2) + pow(vect.y, 2) + pow(vect.z, 2));
	v_norm.x = vect.x / length;
	v_norm.y = vect.y / length;
	v_norm.z = vect.z / length;
	return (v_norm);
}

t_vect3 vect3_cross(t_vect3 v1, t_vect3 v2)
{
	t_vect3 res;

	res.x = (v1.y * v2.z) - (v1.z * v2.y);
	res.y = (v1.z * v2.x) - (v1.x * v2.z);
	res.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (res);
}

t_vect3	vect3_div_nb(t_vect3 v, double nb)
{
	t_vect3	res;

	res.x = v.x / nb;
	res.y = v.y / nb;
	res.z = v.z / nb;
	return (res);
}
