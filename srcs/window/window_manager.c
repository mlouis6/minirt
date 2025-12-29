/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:43:27 by mlouis            #+#    #+#             */
/*   Updated: 2025/12/29 18:42:55 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "mlx.h"
#include "libft.h"
#include "window.h"

static bool	check_window_size(t_mlx *mlx)
{
	mlx_get_screen_size(mlx->mlx, &mlx->screen_x, &mlx->screen_y);
	if (mlx->screen_x < WINDOW_WIDTH || mlx->screen_y < WINDOW_HEIGHT)
	{
		ft_printf("x= %d ; y= %d\n", mlx->screen_x, mlx->screen_y);
		ft_putendl_fd("Error\n", 2);
		ft_putendl_fd("Window is too big", 2);
		close_window(mlx);
		return (false);
	}
	return (true);
}

void	init_window(t_mlx *mlx, char *file)
{
	mlx->height = WINDOW_HEIGHT;
	mlx->width = WINDOW_WIDTH;
	mlx->win = NULL;
	mlx->mlx = mlx_init();
	mlx->img_width = WINDOW_WIDTH;
	if (WINDOW_HEIGHT < 1)
		mlx->img_height = 1;
	else
		mlx->img_height = WINDOW_HEIGHT;
	if (!mlx->mlx)
		close_window(mlx);
	if (!check_window_size(mlx))
		exit (1);
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, file);
	if (!mlx->win)
		close_window(mlx);
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->img_width, mlx->img_height);
	if (!mlx->img.img)
		close_window(mlx);
	mlx->img.addr = mlx_get_data_addr(
			mlx->img.img, &mlx->img.bpp, &mlx->img.len, &mlx->img.endian);
	if (!mlx->img.addr)
		close_window(mlx);
}

int	cross_button_handler(t_mlx *mlx)
{
	close_window(mlx);
	return (0);
}

int	key_event(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		close_window(mlx);
	return (0);
}

int	close_window(t_mlx *mlx) // , int err_stage)
{
	if (mlx->img.img)
		mlx_destroy_image(mlx->mlx, mlx->img.img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(1);
}

// static inline int	encode_color(t_color c)
// {
// 	return (c.r << 16 | c.g << 8 | c.b);
// }

// void	put_img_ambient(t_img img, t_pxl win_pxl, t_ambient ambi)
// {
// 	char	*pix;
// 	int		i;

// 	i = img.bpp - 8;
// 	pix = img.addr + (win_pxl.y * img.len + win_pxl.x * (img.bpp / 8));
// 	while (i >= 0)
// 	{
// 		if (img.endian != 0)
// 			*pix++ = ((encode_color(ambi.color) >> i) & 0xFF) * ambi.lightning;
// 		else
// 			*pix++ = ((encode_color(ambi.color) >> (img.bpp - 8 - i))
// 					& 0xFF) * ambi.lightning;
// 		i -= 8;
// 	}
// }

// void	put_img_object(t_img img, t_pxl win_pxl, t_obj obj, t_scene scene)
// {
// 	char	*pix;
// 	int		i;
// 	t_color	c;

// 	c.r = (obj.color.r * scene.amb.color.r) / 255 * scene.amb.lightning;
// 	c.g = (obj.color.g * scene.amb.color.g) / 255 * scene.amb.lightning;
// 	c.b = (obj.color.b * scene.amb.color.b) / 255 * scene.amb.lightning;
// 	i = img.bpp - 8;
// 	pix = img.addr + (win_pxl.y * img.len + win_pxl.x * (img.bpp / 8));
// 	while (i >= 0)
// 	{
// 		if (img.endian != 0)
// 			*pix++ = ((encode_color(c) >> i) & 0xFF);
// 		else
// 			*pix++ = ((encode_color(c) >> (img.bpp - 8 - i)) & 0xFF);
// 		i -= 8;
// 	}
// }

// t_vect3	get_right(t_camera cam)
// {
// 	t_vect3	right;
// 	t_vect3	tmp;
// 	t_vect3	up;

// 	if (cam.dir.z != 0)
// 		up = (t_vect3){0, 1, 0};
// 	else
// 		up = (t_vect3){0, 0, 1};
// 	tmp = vect3_cross(cam.dir, up);
// 	right = vect3_normalize(tmp);
// 	return (right);
// }

// t_vect3	get_up(t_camera cam)
// {
// 	return (vect3_cross(cam.dir, get_right(cam)));
// }

// t_pt3	get_vp_center(t_camera cam, double focale)
// {
// 	t_pt3	center;

// 	center = vect3_add(cam.pos, vect3_mult_nb(cam.dir, focale));
// 	return (center);
// }

// t_pt3	get_vp_top_left(t_camera cam, double focale)
// {
// 	t_pt3	vp_c;
// 	t_pt3	vp_tl;

// 	vp_c = get_vp_center(cam, focale);
// 	vp_tl = vect3_add(vect3_sub(vp_c,
// 				vect3_mult_nb(get_right(cam), get_viewport_width(cam) / 2)),
// 			vect3_mult_nb(get_up(cam), get_viewport_height(cam) / 2));
// 	return (vp_tl);
// }

// t_vp	init_viewport(t_camera cam)
// {
// 	t_vp	vp;

// 	vp.focale = 1.0;
// 	vp.height = get_viewport_height(cam);
// 	vp.width = get_viewport_width(cam);
// 	vp.top_left = get_vp_top_left(cam, vp.focale);
// 	return (vp);
// }

// t_ray	init_ray(t_camera cam)
// {
// 	t_ray	ray;

// 	ray.tmax = 1.0e30;
// 	ray.curr_t = ray.tmax;
// 	ray.origin = cam.pos;
// 	return (ray);
// }

// int	dispatch_func_call(t_type OBJ, t_scene scene, size_t k, double *t)
// {
// 	int	res;

// 	res = 0;
// 	if (OBJ == SPHERE)
// 	{
// 		res = sphere_check(scene.ray,
// 				((t_obj *)scene.obj[SPHERE].data)[k].shape.sphere, t);
// 	}
// 	else if (OBJ == CYLINDER)
// 	{
// 		res = cylinder_check(scene.ray,
// 				((t_obj *)scene.obj[CYLINDER].data)[k].shape.cyl, t);
// 	}
// 	else if (OBJ == PLANE)
// 	{
// 		res = plane_check(scene.ray,
// 				((t_obj *)scene.obj[PLANE].data)[k].shape.plane, t);
// 	}
// 	return (res);
// }

// int	check_closest(double t, double *closest, t_obj **obj, t_obj *curr_obj)
// {
// 	if (t < *closest)
// 	{
// 		*closest = t;
// 		*obj = curr_obj;
// 		return (true);
// 	}
// 	return (false);
// }

// int	loop_objects(t_scene scene, t_ray *ray, t_obj **obj)
// {
// 	size_t	k;
// 	t_type	obj_type;
// 	int		res;
// 	double	t;
// 	int		hit;

// 	obj_type = 0;
// 	hit = 0;
// 	ray->tmax = 1.0e30;
// 	while (obj_type < NB_TYPE)
// 	{
// 		k = 0;
// 		while (k < scene.obj[obj_type].size)
// 		{
// 			res = dispatch_func_call(obj_type, scene, *ray, k, &t);
// 			if (res && check_closest(t, &(ray->tmax), obj,
// 					&((t_obj *)scene.obj[obj_type].data)[k]))
// 				hit = 1;
// 			++k;
// 		}
// 		++obj_type;
// 	}
// 	return (hit);
// }

// void	complete_scene(t_scene *ptr_scene)
// {
// 	ptr_scene->vp = init_viewport(ptr_scene->cam);
// 	ptr_scene->ray = init_ray(ptr_scene->cam);
// }

// t_pt3	pixel_to_vp_pt(t_scene scene, t_pxl win_pxl)
// {
// 	t_pt3	vp_pt;

// 	vp_pt.z = 0;
// 	vp_pt.x = (win_pxl.x + 0.5) * scene.vp.width / WINDOW_WIDTH;
// 	vp_pt.y = (win_pxl.y + 0.5) * scene.vp.height / WINDOW_HEIGHT;
// 	vp_pt = vect3_add(scene.vp.top_left, vect3_sub(
// 				vect3_mult_nb(get_right(scene.cam), vp_pt.x),
// 				vect3_mult_nb(get_up(scene.cam), vp_pt.y)));
// 	return (vp_pt);
// }

// void	display_background(t_mlx *mlx, t_scene scene)
// {
// 	t_pxl	win_pxl;
// 	t_obj	*obj;

// 	obj = NULL;
// 	complete_scene(&scene);
// 	win_pxl.y = 0;
// 	while (win_pxl.y < WINDOW_HEIGHT)
// 	{
// 		win_pxl.x = 0;
// 		while (win_pxl.x < WINDOW_WIDTH)
// 		{
// 			scene.vp.curr_pt = pixel_to_vp_pt(scene, win_pxl);
// 			scene.ray.dir = vect3_normalize(
// 					vect3_sub(scene.vp.curr_pt, scene.ray.origin));
// 			if (loop_objects(scene, &scene.ray, &obj))
// 				put_img_object(mlx->img, win_pxl, *obj, scene);
// 			else
// 				put_img_ambient(mlx->img, win_pxl, scene.amb);
// 			++(win_pxl.x);
// 		}
// 		++(win_pxl.y);
// 	}
// 	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
// }
