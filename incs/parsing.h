/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:38:20 by cviel             #+#    #+#             */
/*   Updated: 2025/11/03 21:55:15 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define WHITE_SPACES "\t\n\v\f\r "
# define NB_ITEM 3
# define NB_TYPES 3

# include "scene.h"
# include "color.h"

typedef struct s_func
{
	const char	*name;
	int			(*f)();
}	t_func;

int	    parsing(int ac, char **av, t_scene *ptr_scene);
int	    get_line(int fd, char **ptr_line);
char	**split_line(char *line, char *set);
void    free_split(char **split);
//int		parsing(int ac, char **av, t_scene *ptr_scene);
int		call_match(char **info_split, t_scene *ptr_scene, const t_func table[NB_ITEM], uint8_t *otr_check);
int		get_line(int fd, char **ptr_line);
int		fill_ambient_info(char **line_split, t_scene *ptr_scene);
int		fill_camera_info(char **line_split, t_scene *ptr_scene);
int		fill_light_info(char **line_split, t_scene *ptr_scene);
int		fill_object_info(char **line_split, t_scene *ptr_scene, uint8_t *ptr_check);
int 	fill_plane_info(char **line_split, t_obj *ptr_obj);
int 	fill_sphere_info(char **line_split, t_obj *ptr_obj);
int 	fill_cylinder_info(char **line_split, t_obj *ptr_obj);
int		get_coordinates(char *line, t_pt3 *ptr_point);
int		get_norm_vect3(char *line, t_vect3 *ptr_vect3);
int		get_float(char *line, float *nb);
int		get_integer(char *line, int *nb);
int		get_color(char *line, t_color *color);
int		check_elements(t_scene scene);
int		bvh_add(t_bvh **ptr_root, t_bvh *node);
// int	parsing(char *pathname, t_scene **scene);
int		parse_scene(t_scene **scene, int fd);

static t_func const g_table_obj[NB_TYPES] = 
{
	{"sp", fill_sphere_info},
	{"pl", fill_plane_info},
	{"cy", fill_cylinder_info},
};

static t_func const g_table_item[NB_ITEM] = 
{
	{"A", fill_ambient_info},
	{"C", fill_camera_info},
	{"L", fill_light_info},
};

#endif
