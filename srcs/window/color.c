/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:31:04 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/09 13:42:19 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "scene.h"
#include "window.h"
#include <math.h>

static inline int	encode_color(t_color c)
{
	return (c.r << 16 | c.g << 8 | c.b);
}

void	put_img(t_img img, t_pxl win_pxl, t_color c)
{
	char	*pix;
	int		i;

	i = img.bpp - 8;
	pix = img.addr + (win_pxl.y * img.len + win_pxl.x * (img.bpp / 8));
	while (i >= 0)
	{
		if (img.endian != 0)
			*pix++ = ((encode_color(c) >> i) & 0xFF);
		else
			*pix++ = ((encode_color(c) >> (img.bpp - 8 - i)) & 0xFF);
		i -= 8;
	}
}

t_color	color_normalize(t_color_sum sum)
{
	t_color	color;

	color.r = fmin(sum.r, 1) * 255;
	color.g = fmin(sum.g, 1) * 255;
	color.b = fmin(sum.b, 1) * 255;
	return (color);
}
