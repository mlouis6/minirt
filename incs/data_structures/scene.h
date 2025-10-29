/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:33:37 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/28 15:52:07 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# define t_vect3 t_pt3
# define NB_ITEM 3

# include "dim3.h"
// # include "bvh.h"
# include "color.h"
// # include "parsing.h"

// static const t_func g_table_item[NB_ITEM] = {
// 	{"A", fill_ambient_info},
// 	{"C", fill_camera_info},
// 	{"L", fill_light_info},
// };

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
	t_bvh		*root;
}	t_scene;

#endif
