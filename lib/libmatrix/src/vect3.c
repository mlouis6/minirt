/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:15:25 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/22 08:49:23 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim3.h"
//mat4 * vect4

t_vect3	vect3_add(t_vect3 v1, t_vect3 v2)
{
	t_vect3	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.x = v1.x + v2.x;
	return (res);
}

t_vect3	vect3_mult_nb(t_vect3 v, float nb)
{
	t_vect3	res;

	res.x = v.x * nb;
	res.y = v.y * nb;
	res.x = v.x * nb;
	return (res);
}

float	vect3_mult(t_vect3 v1, t_vect3 v2)
{
	float	res;

	res = 0;
	res += v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}

t_vect3	mat3_mult_vect3(t_mat3 mx, t_vect3 v)
{
	t_vect3	res;
	uint8_t	i;
	float	*ptr;		

	i = 0;
	ptr = (float *)&v;
	while (i < 3)
	{
		res.x += mx.coeff[0][i] * ptr[i];
		res.y += mx.coeff[1][i] * ptr[i];
		res.z += mx.coeff[2][i] * ptr[i];
		++i;
	}
	return (res);
}
