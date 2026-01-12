/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:33:37 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/12 11:36:26 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "ft_vector.h"
# include "dim3.h"
# include "objects.h"
# include "window.h"
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

typedef struct s_vp
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

t_vp		init_viewport(t_camera cam);
t_pt3		pixel_to_vp_pt(t_scene scene, t_pxl win_pxl);
void		put_img(t_img img, t_pxl win_pxl, t_color c);
void		display_scene(t_mlx *mlx, t_scene scene);

t_ray		init_ray_cam(t_camera cam);
t_ray		init_ray_obj(double t, t_scene scene);
int			loop_objects(t_scene scene, t_ray *ray, t_obj **obj);

int			sphere_check(t_ray ray, t_sph sph, double *t);
int			cylinder_check(t_ray ray, t_cyl cyl, double *t);
int			plane_check(t_ray ray, t_plane pl, double *t);

int			check_hit_light(t_scene scene, t_obj *obj, double t);

t_color_sum	init_color(t_ambient amb);
t_color_sum	add_light(t_color_sum sum, t_scene scene, t_obj obj);
t_color_sum	add_obj_color(t_color_sum sum, t_obj obj);
t_color		color_normalize(t_color_sum sum);

t_vect3		get_right(t_camera cam);
t_vect3		get_up(t_camera cam);
t_pt3		get_vp_center(t_camera cam, double focale);

#endif
