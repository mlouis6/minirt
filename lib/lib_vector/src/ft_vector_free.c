/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:19:42 by cviel             #+#    #+#             */
/*   Updated: 2025/11/07 18:38:34 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"

void	ft_vector_free(t_vector *ptr_vector)
{
	if (ptr_vector->free_vector != NULL)
		ptr_vector->free_vector(ptr_vector->data);
	free(ptr_vector->data);
}
