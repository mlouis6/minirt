/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:15:32 by cviel             #+#    #+#             */
/*   Updated: 2025/11/05 17:40:46 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "objects.h"

t_box	box_sphere(t_shape shape)
{
	t_box	box;

	box.x_min = shape.sphere.center.x - shape.sphere.radius;
	box.x_max = shape.sphere.center.x + shape.sphere.radius;
	box.y_min = shape.sphere.center.y - shape.sphere.radius;
	box.y_max = shape.sphere.center.y + shape.sphere.radius;
	box.z_min = shape.sphere.center.z - shape.sphere.radius;
	box.z_max = shape.sphere.center.z + shape.sphere.radius;
	return (box);
}

t_box	box_cylinder(t_shape shape)
{
	t_shape	base;
	t_shape	end;

	base.sphere.center = shape.cyl.origin;
	base.sphere.radius = shape.cyl.radius;
	end.sphere.center = vect3_add(shape.cyl.origin,
			vect3_mult_nb(shape.cyl.normal, shape.cyl.height));
	end.sphere.radius = shape.cyl.radius;
	return (box_regroup(box_sphere(base), box_sphere(end)));
}
