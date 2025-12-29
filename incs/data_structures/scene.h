/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:33:37 by mlouis            #+#    #+#             */
/*   Updated: 2025/12/29 17:41:52 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "ft_vector.h"
# include "dim3.h"
# include "color.h"
# include "objects.h"
# include "ray.h"

typedef struct s_ambient
{
	double	lightning;
	t_color	color;
}	t_ambient;

typedef struct s_camera
{
	t_pt3	pos;
	t_vect3	dir;
	int		fov;
}	t_camera;

typedef struct s_light
{
	t_pt3	pos;
	double	brightness;
	t_color	color;
}	t_light;

typedef	struct s_vp
{
	double	height;
	double	width;
	t_pt3	top_left;
	t_pt3	curr_pt;
	double	focale;
}	t_vp;

typedef struct s_scene
{
	t_ambient	amb;
	t_camera	cam;
	t_light		light;
	t_vector	obj[NB_OBJ];
	t_vp		vp;
	t_ray		ray;
}	t_scene;

double	get_viewport_height(t_camera cam);
double	get_viewport_width(t_camera cam);

#endif
