/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:59:05 by cviel             #+#    #+#             */
/*   Updated: 2026/01/09 22:15:51 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "dim3.h"
#include "ret_val.h"
#include "objects.h"
#include "ray.h"
#include "deg2.h"

double	find_sol(t_cyl cyl, t_coef coef, t_ray ray);
double	min_pos(double t1, double t2);

double	min_pos(double t1, double t2)
{
	if (t1 > 0 && t2 > 0)
		return (fmin(t1, t2));
	return ((t1 > 0) * t1 + (t2 > 0) * t2);
}

int	sphere_check(t_ray ray, t_sph sph, double *t)
{
	t_vect3	oc;
	t_coef	coef;
	double	sol1;
	double	sol2;

	oc = vect3_sub(sph.center, ray.origin);
	coef.a = vect3_mult(ray.dir, ray.dir);
	coef.b = -2.0f * vect3_mult(ray.dir, oc);
	coef.c = vect3_mult(oc, oc) - pow(sph.radius, 2);
	coef.delta = pow(coef.b, 2) - 4 * coef.a * coef.c;
	sol1 = -coef.b / (2 * coef.a);
	if (coef.delta == 0 && sol1 > __FLT_EPSILON__)
	{
		*t = sol1;
		return (TRUE);
	}
	sol1 = (-coef.b - sqrt(coef.delta)) / (2 * coef.a);
	sol2 = (-coef.b + sqrt(coef.delta)) / (2 * coef.a);
	if (coef.delta > 0 && min_pos(sol1, sol2) > __FLT_EPSILON__)
	{
		*t = min_pos(sol1, sol2);
		return (TRUE);
	}
	return (FALSE);
}

int	cylinder_check(t_ray ray, t_cyl cyl, double *t)
{
	t_vect3	oc_orth;
	t_vect3	ray_orth;
	t_coef	coef;

	oc_orth = vect3_orth(cyl.normal, vect3_sub(ray.origin, cyl.origin));
	ray_orth = vect3_orth(cyl.normal, ray.dir);
	coef.a = vect3_mult(ray_orth, ray_orth);
	coef.b = 2.0f * vect3_mult(oc_orth, ray_orth);
	coef.c = vect3_mult(oc_orth, oc_orth) - pow(cyl.radius, 2);
	coef.delta = pow(coef.b, 2) - 4 * coef.a * coef.c;
	*t = find_sol(cyl, coef, ray);
	if (*t <= __FLT_EPSILON__)
		return (FALSE);
	return (TRUE);
}

int	check_sol(t_cyl cyl, t_ray ray, double sol)
{
	t_pt3	pt_hit;
	t_vect3	cm;
	
	if (sol <= __FLT_EPSILON__)
		return (FALSE);
	pt_hit = vect3_add(ray.origin, vect3_mult_nb(ray.dir, sol));
	cm = vect3_sub(pt_hit, cyl.origin);
	if (vect3_mult(cm, cyl.normal) >= 0
			&& vect3_mult(cm, cyl.normal) <= cyl.height)
		return (TRUE);
	return (FALSE);
}

double	find_sol(t_cyl cyl, t_coef coef, t_ray ray)
{
	double	sol;

	if (coef.delta <= -__FLT_EPSILON__)
		return (-1);
	if (coef.delta > -__FLT_EPSILON__ && coef.delta < __FLT_EPSILON__)
	{
		sol = -coef.b / (2 * coef.a);
		if (check_sol(cyl, ray, sol) == TRUE)
			return (sol);
		return (-1);
	}
	sol = (-coef.b - sqrt(coef.delta)) / (2 * coef.a);
	if (check_sol(cyl, ray, sol) == TRUE)
		return (sol);
	sol = (-coef.b + sqrt(coef.delta)) / (2 * coef.a);
	if (check_sol(cyl, ray, sol) == TRUE)
		return (sol);
	return (-1);
}

int	plane_check(t_ray ray, t_plane pl, double *t)
{
	t_vect3	oc;
	double	sol;

	oc = vect3_sub(pl.origin, ray.origin);
	sol = vect3_mult(oc, pl.normal) / vect3_mult(ray.dir, pl.normal);
	if (sol > __FLT_EPSILON__)
	{
		*t = sol;
		return (TRUE);
	}
	return (FALSE);
}
