/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:23:16 by cviel             #+#    #+#             */
/*   Updated: 2026/01/12 19:26:41 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_vector.h"
#include "objects.h"

void	free_obj(t_vector *obj)
{
	size_t	i;

	i = 0;
	while (i < NB_OBJ)
	{
		ft_vector_free(&obj[i]);
		++i;
	}
}
