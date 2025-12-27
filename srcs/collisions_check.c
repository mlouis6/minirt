/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:59:05 by cviel             #+#    #+#             */
/*   Updated: 2025/12/18 09:31:09 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "dim3.h"
#include "ret_val.h"
#include "objects.h"
#include "ray.h"
#include "deg2.h"

double	min_pos(double t1, double t2);
t_vect3	orth(t_vect3 u, t_vect3 OM);

int	sphere_check(t_ray ray, t_sph sph, t_pt3 *ptr_hit)
{
	t_vect3	oc;
	t_coef	coef;
	double	sol1;
	double	sol2;

	oc = vect3_add(sph.center, vect3_mult_nb(ray.origin, -1));
	coef.a = vect3_mult(ray.dir, ray.dir);
	coef.b = -2.0f * vect3_mult(ray.dir, oc);
	coef.c = vect3_mult(oc, oc) - pow(sph.radius, 2);
	coef.delta = pow(coef.b, 2) - 4 * coef.a * coef.c;
	sol1 = -coef.b / (2 * coef.a);
	if (coef.delta == 0 && sol1 > 0)
	{
		*ptr_hit = vect3_add(ray.origin, vect3_mult_nb(ray.dir, sol1));
		return (TRUE);
	}
	sol1 = (-coef.b - sqrt(coef.delta)) / (2 * coef.a);
	sol2 = (-coef.b + sqrt(coef.delta)) / (2 * coef.a);
	if (coef.delta > 0 && min_pos(sol1, sol2) > 0)
	{
		*ptr_hit = vect3_add(ray.origin,
				vect3_mult_nb(ray.dir, min_pos(sol1, sol2)));
		return (TRUE);
	}
	return (FALSE);
}

int	cylinder_check(t_ray ray, t_cyl cyl, t_pt3 *ptr_hit)
{
	t_vect3	oc_orth;
	t_vect3	ray_orth;
	t_coef	coef;
	double	sol1;
	double	sol2;

	oc_orth = orth(cyl.normal, vect3_add(cyl.origin,
				vect3_mult_nb(ray.origin, -1)));
	ray_orth = orth(cyl.normal, ray.dir);
	coef.a = vect3_mult(ray_orth, ray_orth);
	coef.b = -2.0f * vect3_mult(oc_orth, ray_orth);
	coef.c = vect3_mult(oc_orth, oc_orth) - pow(cyl.radius, 2);
	coef.delta = pow(coef.b, 2) - 4 * coef.a * coef.c;
	sol1 = -coef.b / (2 * coef.a);
	if (coef.delta == 0 && sol1 > 0)
	{
		*ptr_hit = vect3_add(ray.origin, vect3_mult_nb(ray.dir, sol1));
		return (TRUE);
	}
	sol1 = (-coef.b - sqrt(coef.delta)) / (2 * coef.a);
	sol2 = (-coef.b + sqrt(coef.delta)) / (2 * coef.a);
	if (coef.delta > 0 && min_pos(sol1, sol2) > 0)
	{
		*ptr_hit = vect3_add(ray.origin,
				vect3_mult_nb(ray.dir, min_pos(sol1, sol2)));
		return (TRUE);
	}
	return (FALSE);
}

int	plane_check(t_ray ray, t_plane pl, t_pt3 *ptr_hit)
{
	t_vect3	oc;
	double	sol;

	oc = vect3_add(pl.origin, vect3_mult_nb(ray.origin, -1));
	sol = vect3_mult(oc, pl.normal) / vect3_mult(ray.dir, pl.normal);
	if (sol > 0)
	{
		*ptr_hit = vect3_add(ray.origin, vect3_mult_nb(ray.dir, sol));
		return (TRUE);
	}
	return (FALSE);
}

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
