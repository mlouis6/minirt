/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:59:05 by cviel             #+#    #+#             */
/*   Updated: 2026/01/13 19:35:11 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include "minirt.h"
#include "dim3.h"
#include "objects.h"
#include "ray.h"
#include "deg2.h"

double	find_sol(t_cyl cyl, t_coef coef, t_ray ray);

int	sphere_check(t_ray ray, t_sph sph, double *t)
{
	t_vect3	oc;
	t_coef	coef;
	double	sol1;
	double	sol2;

	oc = vect3_sub(sph.center, ray.origin);
	coef.a = vect3_dot(ray.dir, ray.dir);
	coef.b = -2.0f * vect3_dot(ray.dir, oc);
	coef.c = vect3_dot(oc, oc) - pow(sph.radius, 2);
	coef.delta = pow(coef.b, 2) - 4 * coef.a * coef.c;
	sol1 = -coef.b / (2 * coef.a);
	if (coef.delta == 0 && sol1 > __FLT_EPSILON__)
	{
		*t = sol1;
		return (true);
	}
	sol1 = (-coef.b - sqrt(coef.delta)) / (2 * coef.a);
	sol2 = (-coef.b + sqrt(coef.delta)) / (2 * coef.a);
	if (coef.delta > 0 && min_pos(sol1, sol2) > __FLT_EPSILON__)
	{
		*t = min_pos(sol1, sol2);
		return (true);
	}
	return (false);
}

int	cylinder_check(t_ray ray, t_cyl cyl, double *t)
{
	t_vect3	oc_orth;
	t_vect3	ray_orth;
	t_coef	coef;

	oc_orth = vect3_orth(cyl.normal, vect3_sub(ray.origin, cyl.origin));
	ray_orth = vect3_orth(cyl.normal, ray.dir);
	coef.a = vect3_dot(ray_orth, ray_orth);
	coef.b = 2.0f * vect3_dot(oc_orth, ray_orth);
	coef.c = vect3_dot(oc_orth, oc_orth) - pow(cyl.radius, 2);
	coef.delta = pow(coef.b, 2) - 4 * coef.a * coef.c;
	*t = find_sol(cyl, coef, ray);
	if (*t < __FLT_EPSILON__)
		return (false);
	return (true);
}

int	check_sol(t_cyl cyl, t_ray ray, double sol)
{
	t_pt3	pt_hit;
	t_vect3	cm;

	if (sol < __FLT_EPSILON__)
		return (false);
	pt_hit = vect3_add(ray.origin, vect3_mult(ray.dir, sol));
	cm = vect3_sub(pt_hit, cyl.origin);
	if (vect3_dot(cm, cyl.normal) >= 0
		&& vect3_dot(cm, cyl.normal) <= cyl.height)
		return (true);
	return (false);
}

double	find_sol(t_cyl cyl, t_coef coef, t_ray ray)
{
	double	sol;

	if (coef.delta < -__FLT_EPSILON__)
		return (-1);
	if (coef.delta >= -__FLT_EPSILON__ && coef.delta <= __FLT_EPSILON__)
	{
		sol = -coef.b / (2 * coef.a);
		if (check_sol(cyl, ray, sol) == true)
			return (sol);
		return (-1);
	}
	sol = (-coef.b - sqrt(coef.delta)) / (2 * coef.a);
	if (check_sol(cyl, ray, sol) == true)
		return (sol);
	sol = (-coef.b + sqrt(coef.delta)) / (2 * coef.a);
	if (check_sol(cyl, ray, sol) == true)
		return (sol);
	return (-1);
}

int	plane_check(t_ray ray, t_plane pl, double *t)
{
	t_vect3	co;
	double	div;
	double	sol;

	div = vect3_dot(ray.dir, pl.normal);
	if (div == 0)
		return (false);
	co = vect3_sub(pl.origin, ray.origin);
	sol = vect3_dot(co, pl.normal) / div;
	if (sol > __FLT_EPSILON__)
	{
		*t = sol;
		return (true);
	}
	return (false);
}
