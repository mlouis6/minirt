/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:17:02 by cviel             #+#    #+#             */
/*   Updated: 2025/11/13 14:10:03 by mlouis           ###   ########.fr       */
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
	char	*ptr_end;

	ptr_point->x = ft_strtod(line, &ptr_end);
	if (*ptr_end != ',')
		return (INVALID_FILE);
	line = ptr_end + 1;
	ptr_point->y = ft_strtod(line, &ptr_end);
	if (*ptr_end != ',')
		return (INVALID_FILE);
	line = ptr_end + 1;
	ptr_point->z = ft_strtod(line, &ptr_end);
	if (*ptr_end != '\0')
		return (INVALID_FILE);
	return (SUCCESS);
}

int	get_color(char *line, t_color *ptr_color)
{
	char	*ptr_end;
	int		primary;

	primary = ft_strtoi(line, &ptr_end);
	if (*ptr_end != ',' || primary < 0 || primary > 255)
		return (INVALID_FILE);
	ptr_color->r = primary;
	line = ptr_end + 1;
	primary = ft_strtoi(line, &ptr_end);
	if (*ptr_end != ',' || primary < 0 || primary > 255)
		return (INVALID_FILE);
	ptr_color->g = primary;
	line = ptr_end + 1;
	primary = ft_strtoi(line, &ptr_end);
	if (*ptr_end != '\0' || primary < 0 || primary > 255)
		return (INVALID_FILE);
	ptr_color->b = primary;
	return (SUCCESS);
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
