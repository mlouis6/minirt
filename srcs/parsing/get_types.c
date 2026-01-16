/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:17:02 by cviel             #+#    #+#             */
/*   Updated: 2026/01/16 17:08:10 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ret_val.h"
#include "dim3.h"
#include "color.h"
#include "libft.h"

int	get_coordinates(char *line, void *ptr_point)
{
	char	*ptr_end;

	((t_pt3 *)ptr_point)->x = ft_strtod(line, &ptr_end);
	if (line == ptr_end || *ptr_end != ','
		|| ((t_pt3 *)ptr_point)->x == INFINITY
		|| ((t_pt3 *)ptr_point)->x == -INFINITY)
		return (INVALID_FILE);
	line = ptr_end + 1;
	((t_pt3 *)ptr_point)->y = ft_strtod(line, &ptr_end);
	if (line == ptr_end || *ptr_end != ','
		|| ((t_pt3 *)ptr_point)->y == INFINITY
		|| ((t_pt3 *)ptr_point)->y == -INFINITY)
		return (INVALID_FILE);
	line = ptr_end + 1;
	((t_pt3 *)ptr_point)->z = ft_strtod(line, &ptr_end);
	if (line == ptr_end || *ptr_end != '\0'
		|| ((t_pt3 *)ptr_point)->z == INFINITY
		|| ((t_pt3 *)ptr_point)->z == -INFINITY)
		return (INVALID_FILE);
	return (SUCCESS);
}

double	norm_sq(t_vect3 vect3)
{
	return (pow(vect3.x, 2) + pow(vect3.y, 2) + pow(vect3.z, 2));
}

int	get_norm_vect3(char *line, void *ptr_vect3)
{
	int		ret;
	double	norm;

	ret = get_coordinates(line, ptr_vect3);
	if (ret != SUCCESS)
		return (ret);
	norm = sqrt(norm_sq(*(t_vect3 *)ptr_vect3));
	if (norm > 1.0f + 1e-3 || norm < 1.0f - 1e-3)
		return (INVALID_FILE);
	if (norm != 1.0f)
		*(t_vect3 *)ptr_vect3 = vect3_normalize(*(t_vect3 *)ptr_vect3);
	return (SUCCESS);
}

int	get_color(char *line, void *ptr_color)
{
	int		ret;
	int		data;
	char	*ptr_end;

	ret = ft_strtoi(line, &ptr_end, &data);
	if (ret != SUCCESS || line == ptr_end
		|| *ptr_end != ',' || data < 0 || data > 255)
		return (INVALID_FILE);
	((t_color *)ptr_color)->r = data;
	line = ptr_end + 1;
	ret = ft_strtoi(line, &ptr_end, &data);
	if (ret != SUCCESS || line == ptr_end
		|| *ptr_end != ',' || data < 0 || data > 255)
		return (INVALID_FILE);
	((t_color *)ptr_color)->g = data;
	line = ptr_end + 1;
	ret = ft_strtoi(line, &ptr_end, &data);
	if (ret != SUCCESS || line == ptr_end
		|| *ptr_end != '\0' || data < 0 || data > 255)
		return (INVALID_FILE);
	((t_color *)ptr_color)->b = data;
	return (SUCCESS);
}
