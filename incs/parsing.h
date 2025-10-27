/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:38:20 by cviel             #+#    #+#             */
/*   Updated: 2025/10/27 22:15:29 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define WHITE_SPACES "\t\n\v\f\r "
# define NB_ITEM 3

# include "scene.h"
# include "color.h"

typedef struct s_func
{
	const char	*name;
	int			(*f)(char **, void *);
}	t_func;

static const t_func g_fill_item[NB_ITEM] = {
	{"A", fill_ambient_info},
	{"C", fill_camera_info},
	{"L", fill_light_info},
};

int	    parsing(int ac, char **av, t_scene *ptr_scene);
int	    get_line(int fd, char **ptr_line);
char	**split_line(char *line, char *set);
void    free_split(char **split);
//int		parsing(int ac, char **av, t_scene *ptr_scene);
int		call_match(char **info_split, t_scene *ptr_scene, t_func *table, u_int8_t *otr_check);
int		get_line(int fd, char **ptr_line);
int		fill_ambient_info(char *line, t_scene *ptr_scene);
int		fill_camera_info(char *line, t_scene *ptr_scene);
int		fill_light_info(char *line, t_scene *ptr_scene);
int		fill_object_info(char *line, t_scene *ptr_scene, u_int8_t *ptr_check);
int 	fill_plane_info(char *line, t_obj *ptr_obj);
int 	fill_sphere_info(char *line, t_obj *ptr_obj);
int 	fill_cylinder_info(char *line, t_obj *ptr_obj);
int		get_coordinates(char *line, t_pt3 *origin);
int		get_norm_vect(char *line, t_vect3 *normal);
int		get_float(char *line, float *nb);
int		get_integer(char *line, uint8_t *nb);
int		get_color(char *line, t_color *color);
int		check_elements(t_scene scene);
void	bvh_add(t_bvh *root, t_bvh *node);
// int	parsing(char *pathname, t_scene **scene);
int	parse_scene(t_scene **scene, int fd);

#endif
