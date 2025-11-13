/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:33:37 by mlouis            #+#    #+#             */
/*   Updated: 2025/11/13 11:00:43 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# define t_vect3 t_pt3

# include "dim3.h"
# include "bvh.h"
# include "color.h"
# include "ft_vector.h"

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

// probably gonna use simple arrays for infinite objects (ex : planes)
// since they dont fit in a finite box
typedef struct s_scene
{
	t_ambient	amb;
	t_camera	cam;
	t_light		light;
	t_bvh		*root;
	t_vector	inf_obj[NB_INF];
}	t_scene;

#endif
