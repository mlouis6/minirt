/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:59:05 by cviel             #+#    #+#             */
/*   Updated: 2025/11/28 18:32:15 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ret_val.h"
#include "objects.h"

double	vect3_mult(t_vect3 u, t_vect3 v);
t_vect3	closest(t_vect3 ray, double t1, double t2);
#include <stdio.h>
int	sphere_check(t_vect3 ray, t_sph sphere, t_pt3 *ptr_hit)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	
	a = vect3_mult(ray, ray);
	printf("a = %f\n", a);
	b = -2 * vect3_mult(ray, sphere.center);
	printf("b = %f\n", b);
	printf("center %f %f %f\n", sphere.center.x, sphere.center.y, sphere.center.z);
	c = vect3_mult(sphere.center, sphere.center) - pow(sphere.radius, 2);
	printf("c = %f\n", c);
	delta = pow(b, 2) - 4 * a * c;
	printf("delta = %f\n", delta);
	if (delta < 0)
		return (FALSE);
	if (delta == 0)
	{
		*ptr_hit = vect3_mult_nb(ray, -b / (2 * a));
		return (TRUE);
	}
	*ptr_hit = closest(ray, (-b - sqrt(delta)) / (2 * a), (-b + sqrt(delta)) / (2 * a));
	return (TRUE);
}

t_vect3	closest(t_vect3 ray, double t1, double t2)
{
	t_vect3	path1;
	t_vect3	path2;
	
	path1 = vect3_mult_nb(ray, t1);
	path2 = vect3_mult_nb(ray, t2);
	if (vect3_mult(path1, path1) <= vect3_mult(path2, path2))
		return (path1);
	return (path2);	
}
