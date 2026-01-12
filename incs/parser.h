/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:12:03 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/12 20:05:40 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define NB_INFO_AMB 2
# define NB_INFO_CAM 3
# define NB_INFO_LIGHT 3
# define NB_INFO_SPH 3
# define NB_INFO_PL 3
# define NB_INFO_CYL 5

# include <sys/types.h>
# include <stddef.h>
# include "parsing.h"

typedef struct s_parser
{
	int		(*getter)(char *, void *);
	size_t	offset;
}	t_parser;

static const t_parser	g_amb_parser[] = {
{&get_intensity, offsetof(t_ambient, lightning)},
{&get_color, offsetof(t_ambient, color)}};

static const t_parser	g_cam_parser[] = {
{&get_coordinates, offsetof(t_camera, pos)},
{&get_norm_vect3, offsetof(t_camera, dir)},
{&get_fov, offsetof(t_camera, fov)}};

static const t_parser	g_light_parser[] = {
{&get_coordinates, offsetof(t_light, pos)},
{&get_intensity, offsetof(t_light, brightness)},
{&get_color, offsetof(t_light, color)}};

static const t_parser	g_sph_parser[] = {
{&get_coordinates, offsetof(t_obj, shape) + offsetof(t_shape, sphere)
	+ offsetof(t_sph, center)},
{&get_radius, offsetof(t_obj, shape) + offsetof(t_shape, sphere)
	+ offsetof(t_sph, radius)},
{&get_color, offsetof(t_obj, color)}};

static const t_parser	g_pl_parser[] = {
{&get_coordinates, offsetof(t_obj, shape) + offsetof(t_shape, plane)
	+ offsetof(t_plane, origin)},
{&get_norm_vect3, offsetof(t_obj, shape) + offsetof(t_shape, plane)
	+ offsetof(t_plane, normal)},
{&get_color, offsetof(t_obj, color)}};

static const t_parser	g_cyl_parser[] = {
{&get_coordinates, offsetof(t_obj, shape) + offsetof(t_shape, cyl)
	+ offsetof(t_cyl, origin)},
{&get_norm_vect3, offsetof(t_obj, shape) + offsetof(t_shape, cyl)
	+ offsetof(t_cyl, normal)},
{&get_radius, offsetof(t_obj, shape) + offsetof(t_shape, cyl)
	+ offsetof(t_cyl, radius)},
{&get_dist, offsetof(t_obj, shape) + offsetof(t_shape, cyl)
	+ offsetof(t_cyl, height)},
{&get_color, offsetof(t_obj, color)}};

#endif
