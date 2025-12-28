/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:43:27 by mlouis            #+#    #+#             */
/*   Updated: 2025/12/28 16:55:20 by mlouis           ###   ########.fr       */
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
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, &mlx->img.len, &mlx->img.endian);
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

#include "color.h"

static inline int	encode_color(t_color c)
{
	return (c.r << 16 | c.g << 8 | c.b);
}

#include "ray.h"
#include "dim3.h"

void	put_img(t_img img, int x, int y, int color)
{
	char	*pix;
	int		i;

	i = img.bpp - 8;
	pix = img.addr + (y * img.len + x * (img.bpp / 8));
	while (i >= 0)
	{
		if (img.endian != 0)
			*pix++ = ((color >> i) & 0xFF) * 0.2;
		else
			*pix++ = ((color >> (img.bpp - 8 - i)) & 0xFF) * 0.2;
		i -= 8;
	}
}

// //TODO: add img to mlx struct && move destroy_img to close window
// void	display_background(t_mlx *mlx, t_color c)
// {
// 	int		i;
// 	int		j;
// 	int		rgb;

// 	mlx->img.img = mlx_new_image(mlx->mlx, mlx->img_width, mlx->img_height);
// 	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, &mlx->img.len, &mlx->img.endian);
// 	rgb = encode_color(c);
// 	i = 0;
// 	while (i < WINDOW_HEIGHT)
// 	{
// 		j = 0;
// 		while (j < WINDOW_WIDTH)
// 		{
// 			put_img(mlx->img, j, i, rgb);
// 			++j;
// 		}
// 		++i;
// 	}
// 	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
// }

void	put_img_ambient(t_img img, int x, int y, t_ambient ambi)
{
	char	*pix;
	int		i;

	i = img.bpp - 8;
	pix = img.addr + (y * img.len + x * (img.bpp / 8));
	while (i >= 0)
	{
		if (img.endian != 0)
			*pix++ = ((encode_color(ambi.color) >> i) & 0xFF) * ambi.lightning;
		else
			*pix++ = ((encode_color(ambi.color) >> (img.bpp - 8 - i)) & 0xFF) * ambi.lightning;
		i -= 8;
	}
}
#include <stdio.h>
void	put_img_object(t_img img, int x, int y, t_obj obj, t_scene scene)
{
	char	*pix;
	int		i;
	t_color	c;

	c.r = (obj.color.r * scene.amb.color.r)/255 * scene.amb.lightning;
	c.g = (obj.color.g * scene.amb.color.g)/255 * scene.amb.lightning;
	c.b = (obj.color.b * scene.amb.color.b)/255 * scene.amb.lightning;
	i = img.bpp - 8;
	pix = img.addr + (y * img.len + x * (img.bpp / 8));
	while (i >= 0)
	{
		if (img.endian != 0)
			*pix++ = ((encode_color(c) >> i) & 0xFF);
		else
			*pix++ = ((encode_color(c) >> (img.bpp - 8 - i)) & 0xFF);
		i -= 8;
	}
}

// void	put_img_object(t_img img, int x, int y, t_obj obj)
// {
// 	char	*pix;
// 	int		i;

// 	i = img.bpp - 8;
// 	pix = img.addr + (y * img.len + x * (img.bpp / 8));
// 	while (i >= 0)
// 	{
// 		if (img.endian != 0)
// 			*pix++ = ((encode_color(ambi.color) >> i) & 0xFF) * ambi.lightning;
// 		else
// 			*pix++ = ((encode_color(ambi.color) >> (img.bpp - 8 - i)) & 0xFF) * ambi.lightning;
// 		i -= 8;
// 	}
// }

int	sphere_check(t_ray ray, t_sph sph, double *t); // t_pt3 *ptr_hit);
int	cylinder_check(t_ray ray, t_cyl cyl, double *t);
int	plane_check(t_ray ray, t_plane pl, double *t);
#include <stdio.h>

//? VIEWPORT (world space)
t_vect3	get_right(t_camera cam)
{
	t_vect3 right;
	t_vect3 tmp;
	t_vect3	up;

	if (cam.dir.z != 0)
		up = (t_vect3) {0, 1, 0};
	else
		up = (t_vect3) {0, 0, 1};
	tmp = vect3_cross(cam.dir, up);
	right = vect3_normalize(tmp);
	return (right);
}

t_vect3	get_up(t_camera cam)
{
	return (vect3_cross(cam.dir, get_right(cam)));
}

t_pt3	get_vp_center(t_camera cam, double focale)
{
	t_pt3	center;

	center = vect3_add(cam.pos, vect3_mult_nb(cam.dir, focale));
	return (center);
}

t_pt3	get_vp_top_left(t_camera cam, double focale)
{
	t_pt3	vp_c;
	t_pt3	vp_tl;

	vp_c = get_vp_center(cam, focale);
	vp_tl = vect3_add(vect3_sub(vp_c, vect3_mult_nb(get_right(cam), get_viewport_width(cam)/2)), vect3_mult_nb(get_up(cam), get_viewport_height(cam)/2));
	return (vp_tl);
}

// TODO:
/**
 * take closest hit
 * loop through all objects
 * cast ray to light
 */

void	display_background(t_mlx *mlx, t_scene scene)
{
	// VIEWPORT
	double	focale = 1.0;

	t_pt3	vp_tl = get_vp_top_left(scene.cam, focale);

	// RAY
	t_ray	ray;
	ray.origin = scene.cam.pos;

	// IMAGE
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->img_width, mlx->img_height);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, &mlx->img.len, &mlx->img.endian);

	int	i;
	int	j;
	t_pt3	curr_pt;
	double	x;
	double	y;
	double	closest;
	double	t;
	
	size_t k;

	t_obj	obj;
	int		hit;

	i = 0;
	ray.tmax = 1.0e30;

	// t_obj test;

	// test.color.r = 10;
	// test.color.g = 0;
	// test.color.b = 255;
	// test.type = SPHERE;
	// test.shape.sphere.center = (t_pt3) {-50,0,50};
	// test.shape.sphere.radius = 12.6;

	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			hit = 0;
			closest = ray.tmax;
			x = (j + 0.5) * get_viewport_width(scene.cam) / WINDOW_WIDTH;
			y = (i + 0.5) * get_viewport_height(scene.cam) / WINDOW_HEIGHT;
			curr_pt = vect3_add(vp_tl, vect3_sub(vect3_mult_nb(get_right(scene.cam), x), vect3_mult_nb(get_up(scene.cam), y)));
			ray.dir = vect3_normalize(vect3_sub(curr_pt, ray.origin));
			// sphere
			k = 0;
			while (k < scene.obj[SPHERE].size)
			{
				int	res = sphere_check(ray, ((t_obj *)scene.obj[SPHERE].data)[k].shape.sphere, &t);
				if (res)
				{
					if (t < closest)
					{
						obj = ((t_obj *)scene.obj[SPHERE].data)[k];
						closest = t;
						hit = 1;
					}
				}
				++k;
			}
			// cylinder
			k = 0;
			while (k < scene.obj[CYLINDER].size)
			{
				int	res = cylinder_check(ray, ((t_obj *)scene.obj[CYLINDER].data)[k].shape.cyl, &t);
				if (res)
				{
					if (t < closest)
					{
						obj = ((t_obj *)scene.obj[CYLINDER].data)[k];
						closest = t;
						hit = 1;
					}
				}
				++k;
			}
			// plane
			k = 0;
			while (k < scene.obj[PLANE].size)
			{
				int	res = plane_check(ray, ((t_obj *)scene.obj[PLANE].data)[k].shape.plane, &t);
				if (res)
				{
					if (t < closest)
					{
						obj = ((t_obj *)scene.obj[PLANE].data)[k];
						closest = t;
						++hit;
					}
				}
				++k;
			}

			if (hit)
			{
				put_img_object(mlx->img, j, i, obj, scene);
			}
			else
			{
				put_img_ambient(mlx->img, j, i, scene.amb);
			}
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

/**
 * cast ray
 * if hit box -> check right or left child -> loop til leaf -> color
 * else		  -> cast next ray
 */



