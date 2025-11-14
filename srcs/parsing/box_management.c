/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:28:22 by cviel             #+#    #+#             */
/*   Updated: 2025/11/14 17:25:05 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ret_val.h"
#include "bvh.h"
#include "objects.h"

t_box	box_sphere(t_shape shape);
t_box	box_cylinder(t_shape shape);

t_box	find_box(t_obj obj)
{
	t_box	box;

	if (obj.type == SPHERE)
		box = box_sphere(obj.shape);
	else
		box = box_cylinder(obj.shape);
	return (box);
}

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

t_box	box_regroup(t_box box1, t_box box2)
{
	t_box	box;

	box.x_min = fmin(box1.x_min, box2.x_min);
	box.x_max = fmax(box1.x_max, box2.x_max);
	box.y_min = fmin(box1.y_min, box2.y_min);
	box.y_max = fmax(box1.y_max, box2.y_max);
	box.z_min = fmin(box1.z_min, box2.z_min);
	box.z_max = fmax(box1.z_max, box2.z_max);
	return (box);
}

int	box_contained(t_box big, t_box small)
{
	if (big.x_min > small.x_min
		|| big.x_max < small.x_max
		|| big.y_min > small.y_min
		|| big.y_max < small.y_max
		|| big.z_min > small.z_min
		|| big.z_max < small.z_max)
	{
		return (FALSE);
	}
	return (TRUE);
}
