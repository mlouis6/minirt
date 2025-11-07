/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add_single.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:09:46 by cviel             #+#    #+#             */
/*   Updated: 2025/11/07 18:19:29 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"
#include "libft.h"

int	ft_vector_add_single(t_vector *ptr_vector, void *elem)
{
	void	*tmp;

	if (ptr_vector->size == ptr_vector->capacity)
	{
		tmp = malloc(ptr_vector->data_size * (ptr_vector->capacity << 1));
		if (tmp == NULL)
			return (FAILURE_ALLOC);
		ft_memcpy(tmp, ptr_vector->data,
			ptr_vector->data_size * ptr_vector->size);
		free(ptr_vector->data);
		ptr_vector->data = tmp;
	}
	ft_memcpy(ptr_vector->data + ptr_vector->data_size * ptr_vector->size,
		elem, ptr_vector->data_size);
	return (SUCCESS);
}
