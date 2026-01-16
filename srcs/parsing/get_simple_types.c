/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_simple_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:31:39 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/15 13:02:42 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ret_val.h"
#include "libft.h"

int	get_intensity(char *line, void *ptr_intensity)
{
	double	data;
	char	*ptr_end;

	data = ft_strtod(line, &ptr_end);
	if (line == ptr_end || *ptr_end != '\0' || data < 0 || data > 1)
		return (INVALID_FILE);
	*(double *)ptr_intensity = data;
	return (SUCCESS);
}

int	get_dist(char *line, void *ptr_dist)
{
	double	data;
	char	*ptr_end;

	data = ft_strtod(line, &ptr_end);
	if (line == ptr_end || *ptr_end != '\0'
		|| data < 0 || data == INFINITY)
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
	int		ret;
	char	*ptr_end;
	int		data;

	ret = ft_strtoi(line, &ptr_end, &data);
	if (ret != SUCCESS || line == ptr_end
		|| *ptr_end != '\0' || data < 0 || data >= 180)
		return (INVALID_FILE);
	*(int *)ptr_fov = data;
	return (SUCCESS);
}
