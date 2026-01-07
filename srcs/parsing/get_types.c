/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:17:02 by cviel             #+#    #+#             */
/*   Updated: 2026/01/07 22:19:05 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ret_val.h"
#include "parsing.h"
#include "scene.h"
#include "dim3.h"
#include "color.h"
#include "libft.h"

int	get_coordinates(char *line, void *ptr_point)
{
	char	*ptr_end;

	((t_pt3 *)ptr_point)->x = ft_strtod(line, &ptr_end);
	if (*ptr_end != ',')
		return (INVALID_FILE);
	line = ptr_end + 1;
	((t_pt3 *)ptr_point)->y = ft_strtod(line, &ptr_end);
	if (*ptr_end != ',')
		return (INVALID_FILE);
	line = ptr_end + 1;
	((t_pt3 *)ptr_point)->z = ft_strtod(line, &ptr_end);
	if (*ptr_end != '\0')
		return (INVALID_FILE);
	return (SUCCESS);
}

double	norm_sq(t_vect3 vect3)
{
	return (pow(vect3.x, 2) + pow(vect3.y, 2) + pow(vect3.z, 2));
}

int	get_norm_vect3(char *line, void *ptr_vect3)
{
	int	ret;

	ret = get_coordinates(line, ptr_vect3);
	if (ret != SUCCESS)
		return (ret);
	if (norm_sq(*(t_vect3 *)ptr_vect3) != 1.0f)
		return (INVALID_FILE);
	return (SUCCESS);
}

int	get_color(char *line, void *ptr_color)
{
	int		data;
	char	*ptr_end;

	data = ft_strtoi(line, &ptr_end);
	if (*ptr_end != ',' || data < 0 || data > 255)
		return (INVALID_FILE);
	((t_color *)ptr_color)->r = data;
	line = ptr_end + 1;
	data = ft_strtoi(line, &ptr_end);
	if (*ptr_end != ',' || data < 0 || data > 255)
		return (INVALID_FILE);
	((t_color *)ptr_color)->g = data;
	line = ptr_end + 1;
	data = ft_strtoi(line, &ptr_end);
	if (*ptr_end != '\0' || data < 0 || data > 255)
		return (INVALID_FILE);
	((t_color *)ptr_color)->b = data;
	return (SUCCESS);
}

int	get_intensity(char *line, void *ptr_intensity)
{
	double	data;
	char	*ptr_end;

	data = ft_strtod(line, &ptr_end);
	if (*ptr_end != '\0' || data < 0 || data > 1)
		return (INVALID_FILE);
	*(double *)ptr_intensity = data;
	return (SUCCESS);
}

int	get_dist(char *line, void *ptr_dist)
{
	double	data;
	char	*ptr_end;

	data = ft_strtod(line, &ptr_end);
	if (*ptr_end != '\0' || data < 0)
		return (INVALID_FILE);
	*(double *)ptr_dist = data;
	return (SUCCESS);
}

int	get_radius(char *line, void *ptr_radius)
{
	int	ret;

	ret = get_dist(line, ptr_radius);
	if (ret != SUCCESS)
		return (ret);
	*(double *)ptr_radius /= 2;
	return (SUCCESS);
}

int	get_fov(char *line, void *ptr_fov)
{
	char	*ptr_end;
	int		data;

	data = ft_strtoi(line, &ptr_end);
	if (*ptr_end != '\0' || data < 0 || data >= 180)
		return (INVALID_FILE);
	*(int *)ptr_fov = data;
	return (SUCCESS);
}
