/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:04:58 by cviel             #+#    #+#             */
/*   Updated: 2026/01/08 18:05:14 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "dim3.h"

double	min_pos(double t1, double t2)
{
	if (t1 > 0 && t2 > 0)
		return (fmin(t1, t2));
	return ((t1 > 0) * t1 + (t2 > 0) * t2);
}

t_vect3	orth(t_vect3 u, t_vect3 om)
{
	return (vect3_add(om, \
vect3_mult_nb(vect3_mult_nb(u, vect3_mult(om, u)), -1)));
}
