/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:46:27 by cviel             #+#    #+#             */
/*   Updated: 2025/11/05 16:39:39 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "ret_val.h"
#include "scene.h"

int	get_integer(char *line, int *ptr_int)
{
	int		i;
	uint8_t	sign;
	
	sign = 1;
	i = 0;
	if (line[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (line[i] == '+')
		++i;
	*ptr_int = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		*ptr_int = *ptr_int * 10 + line[i] - '0';
		++i;
	}
	if (line[i] != '\0')
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

int	get_double(char *line, double *ptr_double)
{
	int		comma;
	int		i;
	
	i = 0;
	if (line[i] == '-' || line[i] == '+')
		++i;
	*ptr_double = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		*ptr_double = *ptr_double * 10 + line[i] - '0';
		++i;
	}
	comma = 0;
	if (line[i] == '.')
	{
		++comma;
		++i;
	}
	while (line[i] >= '0' && line[i] <= '9')
	{
		*ptr_double = *ptr_double + (line[i] - '0') / powerd(10, comma);
		++comma;
		++i;
	}
	if (line[i] != '\0')
		return (INVALID_FILE);
	if (line[0] == '-')
		*ptr_double =  - *ptr_double;
	return (SUCCESS);
}
