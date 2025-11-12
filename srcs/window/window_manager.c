/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:43:27 by mlouis            #+#    #+#             */
/*   Updated: 2025/11/12 15:06:01 by mlouis           ###   ########.fr       */
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
	ft_printf("FILE= [%s]\n", file);
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
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "miniRT");
	if (!mlx->win)
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
#include "color.h"

// int	hit_sphere(double radius, const t_ray r)
// {
// 	t_pt3 tmp = vect3_mult_nb(r.origin, -1);
// 	t_vect3 oc = vect3_add(r.dir, tmp);
// 	double a, b, c, discriminant;
// 	a = vect3_mult(r.dir, r.dir);
// 	b = -2.0 * vect3_mult(r.dir, oc);
// 	c = vect3_mult(oc, oc) - radius * radius;
// 	discriminant = b * b - 4 * a * c;
// 	return (discriminant >= 0);
// }

// int	ray_color(const t_ray r)
// {
// 	t_color co;
// 	t_color co1;
// 	t_color co2;
// 	co.r = 255; co.g = 0; co.b = 0;
// 	co1.r = 255; co1.g = 255; co1.b = 255;
// 	co2.r = 255 * 0.5; co2.g = 255 * 0.7; co2.b = 255;
// 	if (hit_sphere(0.5, r))
// 		return (encode_color(co));
// 	double a = 0.5 * r.dir.y + 1.0;
// 	return (1.0 - a) * encode_color(co1) + a * encode_color(co2);
// }

void	put_img(t_img img, int x, int y, int color)
{
	char	*pix;
	int		i;
	// t_color co;
	// co.r = 255; co.g = 0; co.b = 0;
	// t_ray	r;

	// r.dir.x = 
	i = img.bpp - 8;
	pix = img.addr + (y * img.len + x * (img.bpp / 8));
	while (i >= 0)
	{
		// if (hit_sphere(0.5, r))
		// 	color = encode_color(co);
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

void	put_img_object(t_img img, int x, int y, t_obj obj, t_scene scene)
{
	char	*pix;
	int		i;

	i = img.bpp - 8;
	pix = img.addr + (y * img.len + x * (img.bpp / 8));
	while (i >= 0)
	{
		if (img.endian != 0)
			*pix++ = ((encode_color(obj.color) >> i) & 0xFF) * scene.amb.color;
		else
			*pix++ = ((encode_color(obj.color) >> (img.bpp - 8 - i)) & 0xFF) * scene.amb.color;
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

void	display_background(t_mlx *mlx, t_scene scene)
{
	int		i;
	int		j;

	mlx->img.img = mlx_new_image(mlx->mlx, mlx->img_width, mlx->img_height);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, &mlx->img.len, &mlx->img.endian);
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			put_img_ambient(mlx->img, j, i, scene.amb);
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



