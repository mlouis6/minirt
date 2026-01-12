/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:47:50 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/12 11:54:10 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parsing.h"
#include "scene.h"

static void	print_sphere(t_vector vector_sph)
{
	size_t	i;

	i = 0;
	while (i < vector_sph.size)
	{
		printf("obj type = %d, center [%f,%f,%f], radius %f\n",
			((t_obj *)vector_sph.data)[i].type,
			((t_obj *)vector_sph.data)[i].shape.sphere.center.x,
			((t_obj *)vector_sph.data)[i].shape.sphere.center.y,
			((t_obj *)vector_sph.data)[i].shape.sphere.center.z,
			((t_obj *)vector_sph.data)[i].shape.sphere.radius);
		++i;
	}
}

static void	print_cylinder(t_vector vector_cyl)
{
	size_t	i;

	i = 0;
	while (i < vector_cyl.size)
	{
		printf("obj type = %d, origin [%f,%f,%f], "
			"radius = %f, normal [%f,%f,%f], height = %f\n",
			((t_obj *)vector_cyl.data)[i].type,
			((t_obj *)vector_cyl.data)[i].shape.cyl.origin.x,
			((t_obj *)vector_cyl.data)[i].shape.cyl.origin.y,
			((t_obj *)vector_cyl.data)[i].shape.cyl.origin.z,
			((t_obj *)vector_cyl.data)[i].shape.cyl.radius,
			((t_obj *)vector_cyl.data)[i].shape.cyl.normal.x,
			((t_obj *)vector_cyl.data)[i].shape.cyl.normal.y,
			((t_obj *)vector_cyl.data)[i].shape.cyl.normal.z,
			((t_obj *)vector_cyl.data)[i].shape.cyl.height);
		++i;
	}
}

static void	print_plane(t_vector vector_plane)
{
	size_t	i;

	i = 0;
	while (i < vector_plane.size)
	{
		printf("obj type = %d, coord [%f,%f,%f], "
			"normal vect [%f,%f,%f], color [%d,%d,%d]\n",
			((t_obj *)vector_plane.data)[i].type,
			((t_obj *)vector_plane.data)[i].shape.plane.origin.x,
			((t_obj *)vector_plane.data)[i].shape.plane.origin.y,
			((t_obj *)vector_plane.data)[i].shape.plane.origin.z,
			((t_obj *)vector_plane.data)[i].shape.plane.normal.x,
			((t_obj *)vector_plane.data)[i].shape.plane.normal.y,
			((t_obj *)vector_plane.data)[i].shape.plane.normal.z,
			((t_obj *)vector_plane.data)[i].color.r,
			((t_obj *)vector_plane.data)[i].color.g,
			((t_obj *)vector_plane.data)[i].color.b);
		++i;
	}
}

void	print_obj(t_vector *obj)
{
	print_sphere(obj[SPHERE]);
	print_cylinder(obj[CYLINDER]);
	print_plane(obj[PLANE]);
}
