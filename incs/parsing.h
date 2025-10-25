/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:38:20 by cviel             #+#    #+#             */
/*   Updated: 2025/10/25 09:12:13 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define WHITE_SPACES "\t\n\v\f\r "

#include "scene.h"

typedef struct s_func
{
	char	*name;
	int		(*f)(char *, t_scene *);
}	t_func;

int	    parsing(int ac, char **av, t_scene *ptr_scene);
int	    get_line(int fd, char **ptr_line);
int     split_line(char *line, char *set, char ***ptr_split);
void    free_split(char **split);

#endif