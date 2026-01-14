/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:18:46 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/14 17:39:56 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "dim3.h"
# include "scene.h"
# include "objects.h"
# include "ray.h"
# include "color.h"
# include "window.h"

t_vp		init_viewport(t_camera cam);
t_pt3		pixel_to_vp_pt(t_scene scene, t_pxl win_pxl);
void		put_img(t_img img, t_pxl win_pxl, t_color c);
void		display_scene(t_mlx *mlx, t_scene scene);

t_ray		init_ray_cam(t_camera cam);
t_ray		init_ray_obj(double t, t_scene scene);
int			loop_objects(t_scene scene, t_ray *ray, t_obj **obj);
int			check_hit_light(t_scene scene, t_obj *obj, double t);

int			sphere_check(t_ray ray, t_sph sph, double *t);
int			cylinder_check(t_ray ray, t_cyl cyl, double *t);
int			plane_check(t_ray ray, t_plane pl, double *t);
double		min_pos(double t1, double t2);

t_color_sum	init_color(t_ambient amb);
t_color_sum	add_light(t_color_sum sum, t_scene scene, t_obj obj, t_vect3 normal);
t_color_sum	add_specular(t_color_sum sum, t_scene scene, t_obj obj, t_vect3 normal);
t_color_sum	add_obj_color(t_color_sum sum, t_obj obj);
t_color		color_normalize(t_color_sum sum);

t_vect3		get_right(t_camera cam);
t_vect3		get_up(t_camera cam);
t_pt3		get_vp_center(t_camera cam, double focal);

#endif