/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:43:27 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/10 09:04:51 by mlouis           ###   ########.fr       */
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
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Window is too big", 2);
		return (false);
	}
	return (true);
}

int	init_window(t_mlx *mlx, char *file)
{
	if (WINDOW_HEIGHT < 1 || WINDOW_WIDTH < 1)
		return (1);
	mlx->height = WINDOW_HEIGHT;
	mlx->width = WINDOW_WIDTH;
	mlx->mlx = mlx_init();
	mlx->img_height = WINDOW_HEIGHT;
	mlx->img_width = WINDOW_WIDTH;
	if (!mlx->mlx)
		return (close_window(mlx));
	if (!check_window_size(mlx))
		return (close_window(mlx));
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, file);
	if (!mlx->win)
		return (close_window(mlx));
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->img_width, mlx->img_height);
	if (!mlx->img.img)
		return (close_window(mlx));
	mlx->img.addr = mlx_get_data_addr(
			mlx->img.img, &mlx->img.bpp, &mlx->img.len, &mlx->img.endian);
	if (!mlx->img.addr)
		return (close_window(mlx));
	return (0);
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

int	close_window(t_mlx *mlx)
{
	if (mlx->img.img)
		mlx_destroy_image(mlx->mlx, mlx->img.img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		mlx_loop_end(mlx->mlx);
	return (1);
}
