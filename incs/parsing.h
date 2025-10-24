#ifndef PARSING_H
# define PARSING_H

# include "scene.h"

int	parsing(char *pathname, t_scene **scene);
int	parse_scene(t_scene **scene, int fd);

#endif
