/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:38:20 by cviel             #+#    #+#             */
/*   Updated: 2026/01/07 22:56:25 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define WHITE_SPACES "\t\n\v\f\r "
# define NB_INFO_AMB 2
# define NB_INFO_CAM 3
# define NB_INFO_LIGHT 3
# define NB_INFO_SPH 3
# define NB_INFO_PL 3
# define NB_INFO_CYL 5

# include "color.h"
# include "objects.h"
# include "scene.h"

typedef struct s_parser
{
	int		(*getter)(char *, void *);
	size_t	offset;
}	t_parser;

int	    parsing(int ac, char **av, t_scene *ptr_scene);
int	    get_line(int fd, char **ptr_line);
char	**split_line(char *line, char *set);
void    free_split(char **split);
int		get_line(int fd, char **ptr_line);
int		fill_item(char **line_split, void *ptr_item, const t_parser parser[], size_t parser_size);
int		get_coordinates(char *line, void *ptr_point);
int		get_norm_vect3(char *line, void *ptr_vect3);
int		get_color(char *line, void *color);
int		get_fov(char *line, void *ptr_fov);
int		get_intensity(char *line, void *ptr_intensity);
int		get_dist(char *line, void *ptr_dist);
int		get_radius(char *line, void *ptr_radius);
void	free_obj(t_vector *obj);

#endif
