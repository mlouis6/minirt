/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:25:57 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/29 15:59:11 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1100
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 800
# endif

//? const globals
# define RATIO ((double) WINDOW_WIDTH / (double) WINDOW_HEIGHT)

# define VIEWPORT_HEIGHT 2.0
# define VIEWPORT_WIDTH (RATIO * VIEWPORT_HEIGHT)
//??

enum
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 33
};

enum
{
	KEY_ESC = 65307
};

typedef	struct s_mlx
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		screen_x;
	int		screen_y;
	int		img_height;
	int		img_width;
}	t_mlx;

void	init_window(t_mlx *mlx, char *file);
int		cross_button_handler(t_mlx *mlx);
int		key_event(int key, t_mlx *mlx);
int		close_window(t_mlx *mlx);

#endif
