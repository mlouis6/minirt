/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:01:13 by cviel             #+#    #+#             */
/*   Updated: 2025/11/07 18:40:03 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

#include <unistd.h>

enum e_ret
{
	SUCCESS = 0,
	FAILURE_ALLOC
};

typedef struct s_vector
{
	void	*data;
	size_t	data_size;
	size_t	size;
	size_t	capacity;
	void	(*free_vector)(void *);
}	t_vector;

int		ft_vector_init(t_vector *ptr_vector, size_t data_size, size_t capacity,
			void (*free_vector)(void *));
int		ft_vector_copy(t_vector *ptr_dest, t_vector src);
void	ft_vector_free(t_vector *ptr_vector);
int		ft_vector_add_single(t_vector *ptr_vector, void *elem);

#endif