/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:43:27 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/20 11:43:14 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdbool.h>
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

int key_event(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		close_window(mlx);
	return (0);
}

int	close_window(t_mlx *mlx) // , int err_stage)
{
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(1);
}
