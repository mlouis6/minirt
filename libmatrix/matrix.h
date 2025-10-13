/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:04:39 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/13 18:07:28 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <unistd.h>

typedef struct s_matrix
{
	size_t	m;
	size_t	n;
	float	**val;
}	t_matrix;

// MANAGE
int		matrix_create(t_matrix *mx, size_t m, size_t n, float **values);
int		matrix_create_empty(t_matrix	*mx, size_t m, size_t n);
void	print_matrix(t_matrix *mx);
void	matrix_destroy(t_matrix *mx);


// OPERATIONS
int	matrix_add(t_matrix *r_mx, t_matrix *mx1, t_matrix *mx2);
int	matrix_multiply_number(t_matrix *r_mx, t_matrix *mx, float nb);
int	matrix_multiply(t_matrix *r_mx, t_matrix *mx1, t_matrix *mx2);


typedef struct s_vect3
{
	float	x;
	float	y;
	float	z;
}	t_vect3;

t_vect3 create_vect3(float x, float y, float z);
t_vect3	vect3_add(t_vect3 v1, t_vect3 v2);
t_vect3	vect3_mutiply(t_vect3 v1, t_vect3 v2);



void	*ft_calloc(size_t nmemb, size_t size); //TODO: move

#endif
