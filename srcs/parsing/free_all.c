/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:23:16 by cviel             #+#    #+#             */
/*   Updated: 2025/11/24 18:05:04 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_vector.h"
#include "objects.h"

void	free_obj(t_vector *inf_obj)
{
	size_t	i;

	i = 0;
	while (i < NB_OBJ)
	{
		ft_vector_free(&inf_obj[i]);
		++i;
	}
}
