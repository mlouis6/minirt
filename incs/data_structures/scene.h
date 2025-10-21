/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:33:37 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/20 11:04:20 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <inttypes.h>
# include "matrix.h"

typedef struct s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_color;

typedef struct s_ambient
{
	float	lightning;
	t_color	color;
}	t_ambient;

typedef struct s_camera
{
	t_vect3	pos;
	t_vect3	dir;
	uint8_t	fov;
}	t_camera;

typedef struct s_light
{
	t_vect3	pos;
	float	brightness;
	t_color	color;
}	t_light;

//? maybe too verbose because scene->light.color.b is gonna be so looooooong
typedef struct s_scene
{
	t_ambient	ambi_l;
	t_camera	cam;
	t_light		light;
	// t_object **objs;
}	t_scene;

#endif
