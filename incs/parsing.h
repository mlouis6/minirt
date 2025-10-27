/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:38:20 by cviel             #+#    #+#             */
/*   Updated: 2025/10/27 11:22:33 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define WHITE_SPACES "\t\n\v\f\r "

#include "scene.h"

int	parsing(int ac, char **av, t_scene *ptr_scene);
int	get_line(int fd, char **ptr_line);
int	fill_ambient_info(char *line, t_scene *ptr_scene);
int	fill_camera_info(char *line, t_scene *ptr_scene);
int	fill_light_info(char *line, t_scene *ptr_scene);
int	fill_object_info(char *line, t_scene *ptr_scene, t_type type);
int fill_plane_info(char *line, t_obj *ptr_obj);
int fill_sphere_info(char *line, t_obj *ptr_obj);
int fill_cylinder_info(char *line, t_obj *ptr_obj);
int	get_coordinates(char *line, int *pos, t_pt3 *origin);
int	get_norm_vect(char *line, int *pos, t_vect3 *normal);
int	get_float(char *line, int *pos, float *nb);
int	get_integer(char *line, int *pos, uint8_t *nb);
int	get_color(char *line, int *pos, t_color *color);
int	check_elements(t_scene scene);
void	bvh_add(t_bvh *root, t_bvh *node);

#endif