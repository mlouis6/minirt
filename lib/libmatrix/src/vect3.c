/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:15:25 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/12 19:25:31 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim3.h"
#include <math.h>

double	vect3_dot(t_vect3 v1, t_vect3 v2)
{
	double	res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}

t_vect3	vect3_normalize(t_vect3 vect)
{
	t_vect3	v_norm;
	double	length;

	length = sqrt(pow(vect.x, 2) + pow(vect.y, 2) + pow(vect.z, 2));
	v_norm.x = vect.x / length;
	v_norm.y = vect.y / length;
	v_norm.z = vect.z / length;
	return (v_norm);
}

t_vect3	vect3_cross(t_vect3 v1, t_vect3 v2)
{
	t_vect3	res;

	res.x = (v1.y * v2.z) - (v1.z * v2.y);
	res.y = (v1.z * v2.x) - (v1.x * v2.z);
	res.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (res);
}

t_vect3	vect3_orth(t_vect3 u, t_vect3 om)
{
	return (vect3_sub(om, vect3_mult(u, vect3_dot(om, u))));
}
