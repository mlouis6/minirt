/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:38:20 by cviel             #+#    #+#             */
/*   Updated: 2026/01/07 17:36:58 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define WHITE_SPACES "\t\n\v\f\r "

# include "color.h"
# include "objects.h"
# include "scene.h"

int	    parsing(int ac, char **av, t_scene *ptr_scene);
int	    get_line(int fd, char **ptr_line);
char	**split_line(char *line, char *set);
void    free_split(char **split);
int		get_line(int fd, char **ptr_line);
int		fill_ambient_info(char **line_split, t_scene *ptr_scene);
int		fill_camera_info(char **line_split, t_scene *ptr_scene);
int		fill_light_info(char **line_split, t_scene *ptr_scene);
int		fill_object_info(char **line_split, t_scene *ptr_scene);
int 	fill_plane_info(char **line_split, t_obj *ptr_obj);
int 	fill_sphere_info(char **line_split, t_obj *ptr_obj);
int 	fill_cylinder_info(char **line_split, t_obj *ptr_obj);
int		get_coordinates(char *line, t_pt3 *ptr_point);
int		get_norm_vect3(char *line, t_vect3 *ptr_vect3);
int		get_color(char *line, t_color *color);
void	free_obj(t_vector *obj);

#endif
