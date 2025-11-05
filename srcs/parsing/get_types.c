/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:17:02 by cviel             #+#    #+#             */
/*   Updated: 2025/11/05 17:42:11 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ret_val.h"
#include "parsing.h"
#include "scene.h"
#include "dim3.h"
#include "color.h"
#include "libft.h"

int	get_coordinates(char *line, t_pt3 *ptr_point)
{
	int		ret;
	char	**line_split;
	int		i;

	line_split = split_line(line, ",");
	if (line_split == NULL)
		return (ERROR_MALLOC);
	i = 0;
	ret = get_double(line_split[i], &ptr_point->x);
	if (ret != SUCCESS)
	{
		free_split(line_split);
		return (ret);
	}
	++i;
	ret = get_double(line_split[i], &ptr_point->y);
	if (ret != SUCCESS)
	{
		free_split(line_split);
		return (ret);
	}
	++i;
	ret = get_double(line_split[i], &ptr_point->z);
	if (ret != SUCCESS)
	{
		free_split(line_split);
		return (ret);
	}
	++i;
	if (line_split[i] != NULL || line[ft_strlen(line) - 1] == ',')
		ret = INVALID_FILE;
	free_split(line_split);
	return (ret);
}

int	get_color(char *line, t_color *ptr_color)
{
	int		ret;
	char	**line_split;
	int		primary;
	int		i;

	line_split = split_line(line, ",");
	if (line_split == NULL)
		return (ERROR_MALLOC);
	i = 0;
	ret = get_integer(line_split[i], &primary);
	if (ret != SUCCESS || primary < 0 || primary > 255)
	{
		free_split(line_split);
		if (ret != SUCCESS)
			return (ret);
		return (INVALID_FILE);
	}
	ptr_color->r = primary;
	++i;
	ret = get_integer(line_split[i], &primary);
	if (ret != SUCCESS || primary < 0 || primary > 255)
	{
		free_split(line_split);
		if (ret != SUCCESS)
			return (ret);
		return (INVALID_FILE);
	}
	ptr_color->g = primary;
	++i;
	ret = get_integer(line_split[i], &primary);
	if (ret != SUCCESS || primary < 0 || primary > 255)
	{
		free_split(line_split);
		if (ret != SUCCESS)
			return (ret);
		return (INVALID_FILE);
	}
	ptr_color->b = primary;
	++i;
	if (line_split[i] != NULL)
		ret = INVALID_FILE;
	free_split(line_split);
	return (ret);
}

double	powd(double n, int p)
{
	double	m;
	int		i;

	m = 1;
	i = 0;
	while (i < p)
	{
		m *= n;
		++i;
	}
	return (m);
}

double	norm_sq(t_vect3 vect3)
{
	return (powd(vect3.x, 2) + powd(vect3.y, 2) + powd(vect3.z, 2));
}

int	get_norm_vect3(char *line, t_vect3 *ptr_vect3)
{
	int	ret;

	ret = get_coordinates(line, ptr_vect3);
	if (ret != SUCCESS)
		return (ret);
	if (norm_sq(*ptr_vect3) != 1.0)
		return (INVALID_FILE);
	return (SUCCESS);
}
