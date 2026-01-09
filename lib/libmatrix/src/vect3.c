/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:15:25 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/09 14:20:14 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim3.h"
#include <math.h>

double	vect3_mult(t_vect3 v1, t_vect3 v2)
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
