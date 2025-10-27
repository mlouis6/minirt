/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:42:00 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/27 17:20:19 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"
#include "parsing.h"
#include "ret_val.h"
#include <stdlib.h>

static t_ambient	parse_ambient_light(char **strs, int *err);
static t_camera		parse_camera(char **strs, int *err);
static t_light		parse_light(char **strs, int *err);

double	ft_strtod(char *str)
{
	double	res;
	char	**tmp;
	int		i;

	res = 0.0;
	tmp = ft_split(str, '.');
	if (tmp[1])
	{
		res = ft_atoi(tmp[1]);
		i = ft_strlen(tmp[1]);
		while (i > 0)
		{
			res /= 10;
			--i;
		}
	}
	res += ft_atoi(tmp[0]);
	if (tmp[1])
		free_arr((void *)tmp, 3);
	else
		free_arr((void *)tmp, 2);
	return (res);
}

/**
 * while gnl
 * 	read first char
 * 	if A -> parse_ambient
 * 	if C -> parse_camera
 * 	if L -> parse_light
 * 	if A (again) -> ERROR
 * 	if another letter -> ERROR
 * 	if missing one -> ERROR
*/
#include <stdio.h>
static int	dispatch_parsing_scene(t_scene **scene, char *str)
{
	static uint8_t	count_a = 0;
	static uint8_t	count_c = 0;
	static uint8_t	count_l = 0;
	int				err;

	err = 0;
	while (*str && !ft_isalpha(*str))
		str++;
	if (*str == 'A')
	{
		++count_a;
		(*scene)->amb = parse_ambient_light(ft_split(str, ' '), &err);

	}
	else if (*str == 'C')
	{
		++count_c;
		(*scene)->cam = parse_camera(ft_split(str, ' '), &err);
	}
	else if (*str == 'L')
	{
		++count_l;
		(*scene)->light = parse_light(ft_split(str, ' '), &err);
	}
	else //objects
		;
	if (count_a > 1 || count_c > 1 || count_l > 1)
		return (ERROR_ARGUMENT);
	return (err);
}

int	parse_scene(t_scene **scene, int fd)
{
	char	*line;
	int		err;

	err = 0;
	line = NULL;
	err = get_line(fd, &line);
	while (line && !err)
	{
		if (err)
			return (ERROR_SYSCALL);
		err = dispatch_parsing_scene(scene, line);
		free (line);
		err = get_line(fd, &line);
	}
	free (line);
	return (err);		
}

static t_ambient	parse_ambient_light(char **strs, int *err)
{
	t_ambient	a;
	char		**colors;

	a.lightning = ft_strtod(strs[1]); 
	colors = ft_split(strs[2], ',');
	if (!colors)
	{
		*err = ERROR_SYSCALL;
		return (a);
	}
	a.color.r = ft_atoi(colors[0]);
	a.color.g = ft_atoi(colors[1]);
	a.color.b = ft_atoi(colors[2]);
	free_arr((void *) colors, 4);
	free_arr((void *)strs, 4);
	return (a);
}

static t_camera	parse_camera(char **strs, int *err)
{
	t_camera	c;
	char		**tmp;

	tmp = ft_split(strs[1], ',');
	if (!tmp)
	{
		*err = ERROR_SYSCALL;
		c.pos.x = -1;
		return (c);
	}
	c.pos.x = ft_strtod(tmp[0]);
	c.pos.y = ft_strtod(tmp[1]);
	c.pos.z = ft_strtod(tmp[2]);
	free_arr((void *)tmp, 4);
	tmp = ft_split(strs[2], ',');
	if (!tmp)
	{
		*err = ERROR_SYSCALL;
		return (c);
	}
	c.dir.x = ft_atoi(tmp[0]);
	c.dir.y = ft_atoi(tmp[1]);
	c.dir.z = ft_atoi(tmp[2]);
	free_arr((void *)tmp, 4);
	c.fov = ft_atoi(strs[3]);
	free_arr((void *)strs, 5);
	return (c);
}

static t_light	parse_light(char **strs, int *err)
{
	t_light	l;
	char	**tmp;

	tmp = ft_split(strs[1], ',');
	if (!tmp)
	{
		*err = ERROR_SYSCALL;
		l.pos.x = -1;
		return (l);
	}
	l.pos.x = ft_strtod(tmp[0]);
	l.pos.y = ft_strtod(tmp[1]);
	l.pos.z = ft_strtod(tmp[2]);
	free_arr((void *)tmp, 4);
	l.brightness = ft_strtod(strs[2]);
	tmp = ft_split(strs[3], ',');
	if (!tmp)
	{
		*err = ERROR_SYSCALL;
		return (l);
	}
	l.color.r = ft_atoi(tmp[0]);
	l.color.g = ft_atoi(tmp[1]);
	l.color.b = ft_atoi(tmp[2]);
	free_arr((void *)tmp, 4);
	free_arr((void *)strs, 5);
	return (l);
}
