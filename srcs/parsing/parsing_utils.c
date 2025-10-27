/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:07:10 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/27 11:25:58 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "objects.h"

int	get_coordinates(char *line, int *pos, t_pt3 *origin)
{
	(void) line; (void) pos; (void) origin;
	return (0);
}

int	get_norm_vect(char *line, int *pos, t_vect3 *normal)
{
	(void) line; (void) pos; (void) normal;
	return (0);
}

int	get_float(char *line, int *pos, float *nb)
{
	(void) line; (void) pos; (void) nb;
	return (0);
}

int	get_integer(char *line, int *pos, uint8_t *nb)
{
	(void) line; (void) pos; (void) nb;
	return (0);
}

int	get_color(char *line, int *pos, t_color *color)
{
	(void) line; (void) pos; (void) color;
	return (0);
}

int	check_elements(t_scene scene)
{
	(void) scene;
	return (0);
}

void	bvh_add(t_bvh *root, t_bvh *node)
{
	(void) node; (void) root;
}
