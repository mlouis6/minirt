/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:21:32 by cviel             #+#    #+#             */
/*   Updated: 2025/11/07 18:40:21 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

int	ft_vector_copy(t_vector *ptr_dest, t_vector src)
{
	int	ret;

	ret = ft_vector_init(ptr_dest, src.data_size, src.capacity,
			src.free_vector);
	if (ret != SUCCESS)
		return (ret);
	ptr_dest->data_size = src.data_size;
	ptr_dest->capacity = src.capacity;
	ptr_dest->free_vector = src.free_vector;
	ft_memcpy(ptr_dest->data, src.data, src.data_size * src.size);
	ptr_dest->size = src.size;
	return (SUCCESS);
}
