/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 22:29:46 by cviel             #+#    #+#             */
/*   Updated: 2026/01/07 22:56:11 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ret_val.h"
#include "objects.h"
#include "scene.h"
#include "parsing.h"

#include <stdio.h>

int	fill_item(char **line_split, void *ptr_item, const t_parser parser[], size_t parser_size)
{
	int		ret;
	size_t	i;
	void	*curr_field;

	i = 0;
	printf("parser_size = %zu\n", parser_size);
	while (i < parser_size)
	{
		printf("%zu\n", i);
		if (line_split[i] == NULL)
		{
			printf("out here\n");
			return (INVALID_FILE);
		}
		curr_field = (unsigned char *)ptr_item + parser[i].offset;
		ret = parser[i].getter(line_split[i], curr_field);
		if (ret != SUCCESS)
		{
			printf("out there\n");
			return (ret);
		}
		++i;
	}
	printf("\n");
	if (line_split[i] != NULL)
		return (INVALID_FILE);
	return (SUCCESS);
}