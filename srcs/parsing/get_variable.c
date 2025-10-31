/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:46:27 by cviel             #+#    #+#             */
/*   Updated: 2025/10/31 21:19:01 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "ret_val.h"
#include "scene.h"

int	get_integer(char *line, int *ptr_i, int *ptr_int)
{
	uint8_t	sign;
	
	*ptr_i = 0;
	if (line[0] == '-')
	{
		sign = -1;
		++(*ptr_i);
	}
	else if (line[0] == '+')
		++(*ptr_i);
	*ptr_int = 0;
	while (line[*ptr_i] >= '0' && line[*ptr_i] <= '9')
	{
		*ptr_int = *ptr_int * 10 + line[*ptr_i] - '0';
		++(*ptr_i);
	}
	if (line[*ptr_i] != '\0')
		return (INVALID_FILE);
	*ptr_int *= sign;
	return (SUCCESS);
}

double	powerd(int n, int p)
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

int	get_double(char *line, int *ptr_i, double *ptr_double)
{
	uint8_t	sign;
	int		comma;
	
	*ptr_i = 0;
	if (line[0] == '-')
	{
		sign = -1;
		++(*ptr_i);
	}
	else if (line[0] == '+')
		++(*ptr_i);
	*ptr_double = 0;
	while (line[*ptr_i] >= '0' && line[*ptr_i] <= '9')
	{
		*ptr_double = *ptr_double * 10 + line[*ptr_i] - '0';
		++(*ptr_i);
	}
	comma = 0;
	if (line[*ptr_i] == '.')
		++comma;
	while (line[*ptr_i] >= '0' && line[*ptr_i] <= '9')
	{
		*ptr_double = *ptr_double + (line[*ptr_i] - '0') / powerd(10, comma);
		++comma;
		++(*ptr_i);
	}	
	if (line[*ptr_i] != '\0')
		return (INVALID_FILE);
	*ptr_double *= sign;
	return (SUCCESS);
}

int	get_coordinates(char *line, int *ptr_i, t_pt3 *ptr_point)
{
	int	ret;
	
	*ptr_i = 0;
	ret = get_double(line, ptr_i, (*ptr_point).x);
	if (ret != SUCCESS)
		return (ret);
	 
}