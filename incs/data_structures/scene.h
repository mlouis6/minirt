/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:33:37 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/23 18:45:11 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# define t_vect3 t_pt3

# include "dim3.h"
# include "color.h"

typedef struct s_ambient
{
	float	lightning;
	t_color	color;
}	t_ambient;

typedef struct s_camera
{
	t_pt3	pos;
	t_vect3	dir;
	uint8_t	fov;
}	t_camera;

typedef struct s_light
{
	t_pt3	pos;
	float	brightness;
	t_color	color;
}	t_light;

//? maybe too verbose because scene->light.color.b is gonna be so looooooong
typedef struct s_scene
{
	t_ambient	amb;
	t_camera	cam;
	t_light		light;
	// t_object **objs;
}	t_scene;

#endif
