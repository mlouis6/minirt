/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:03:59 by cviel             #+#    #+#             */
/*   Updated: 2025/11/07 20:24:46 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"

int	ft_vector_init(t_vector *ptr_vector, size_t data_size, size_t capacity,
	void (*free_vector)(void *))
{
	ptr_vector->data = malloc(data_size * capacity);
	if (ptr_vector->data == NULL)
		return (FAILURE_ALLOC);
	ptr_vector->data_size = data_size;
	ptr_vector->capacity = capacity;
	ptr_vector->size = 0;
	ptr_vector->free_vector = free_vector;
	return (OK);
}
