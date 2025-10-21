/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:45:52 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/21 15:25:14 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM3_D
# define DIM3_D

# include <unistd.h>
# include <inttypes.h>

/** MATRIX 3 */
typedef struct s_mat3
{
	float coeff[3][3];
}	t_mat3;

void	print_matrix(void *mx, uint8_t m);
t_mat3	mat3_add(t_mat3 mx1, t_mat3 mx2);
t_mat3	mat3_mult_nb(t_mat3 mx, float nb);
t_mat3	mat3_mult(t_mat3 mx1, t_mat3 mx2);
t_mat3	mat3_trans(t_mat3 mx);

/** VECTOR */
typedef struct s_vect3
{
	float	x;
	float	y;
	float	z;
}	t_vect3;

t_vect3	create_vect3(float x, float y, float z);
t_vect3	vect3_add(t_vect3 v1, t_vect3 v2);
t_vect3	vect3_mutiply(t_vect3 v1, t_vect3 v2);
t_vect3	mat3_mult_vect3(t_mat3 mx, t_vect3 v);

#endif