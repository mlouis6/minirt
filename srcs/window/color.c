/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:31:04 by mlouis            #+#    #+#             */
/*   Updated: 2025/12/29 18:47:29 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "scene.h"
#include "window.h"

static inline int	encode_color(t_color c)
{
	return (c.r << 16 | c.g << 8 | c.b);
}

void	put_img_ambient(t_img img, t_pxl win_pxl, t_ambient ambi)
{
	char	*pix;
	int		i;

	i = img.bpp - 8;
	pix = img.addr + (win_pxl.y * img.len + win_pxl.x * (img.bpp / 8));
	while (i >= 0)
	{
		if (img.endian != 0)
			*pix++ = ((encode_color(ambi.color) >> i) & 0xFF) * ambi.lightning;
		else
			*pix++ = ((encode_color(ambi.color) >> (img.bpp - 8 - i))
					& 0xFF) * ambi.lightning;
		i -= 8;
	}
}

void	put_img_object(t_img img, t_pxl win_pxl, t_obj obj, t_scene scene)
{
	char	*pix;
	int		i;
	t_color	c;

	c.r = (obj.color.r * scene.amb.color.r) / 255 * scene.amb.lightning;
	c.g = (obj.color.g * scene.amb.color.g) / 255 * scene.amb.lightning;
	c.b = (obj.color.b * scene.amb.color.b) / 255 * scene.amb.lightning;
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
