/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:07:10 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/27 21:32:32 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "objects.h"
#include "color.h"

int	get_coordinates(char *line, t_pt3 *origin)
{
	(void) line; (void) origin;
	return (0);
}

int	get_norm_vect(char *line, t_vect3 *normal)
{
	(void) line; (void) normal;
	return (0);
}

int	get_float(char *line, float *nb)
{
	(void) line; (void) nb;
	return (0);
}

int	get_integer(char *line, uint8_t *nb)
{
	(void) line; (void) nb;
	return (0);
}

int	get_color(char *line, t_color *color)
{
	(void) line; (void) color;
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
