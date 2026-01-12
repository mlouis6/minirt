/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:16:13 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/12 17:24:31 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim3.h"

t_vect3	vect3_add(t_vect3 v1, t_vect3 v2)
{
	t_vect3	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vect3	vect3_mult(t_vect3 v, double nb)
{
	t_vect3	res;

	res.x = v.x * nb;
	res.y = v.y * nb;
	res.z = v.z * nb;
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
