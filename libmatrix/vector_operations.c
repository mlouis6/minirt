/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:53:22 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/13 17:58:11 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_vect3 create_vect3(float x, float y, float z)
{
	t_vect3 v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vect3	vect3_add(t_vect3 v1, t_vect3 v2)
{
	t_vect3 res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vect3	vect3_mutiply(t_vect3 v1, t_vect3 v2)
{
	t_vect3 res;

	res.x = v1.x * v2.x;
	res.y = v1.y * v2.y;
	res.z = v1.z * v2.z;
	return (res);
}
