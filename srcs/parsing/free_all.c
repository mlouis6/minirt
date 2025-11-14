/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:23:16 by cviel             #+#    #+#             */
/*   Updated: 2025/11/14 16:56:03 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_vector.h"
#include "bvh.h"

void	free_inf(t_vector *inf_obj)
{
	size_t	i;

	i = 0;
	while (i < NB_INF)
	{
		ft_vector_free(&inf_obj[i]);
		++i;
	}
}

void	free_bvh(t_bvh *root)
{
	if (root == NULL)
		return ;
	free_bvh(root->left);
	free_bvh(root->right);
	free(root);
	root = NULL;
}

