/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:13:25 by cviel             #+#    #+#             */
/*   Updated: 2025/10/24 22:33:05 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bvh.h"

void	bvh_add(t_bvh **root, t_bvh *node)
{
	node->box = find_box(node->obj);
	if (*root != NULL)
	{
		if ((*root)->obj.type == NONE)
		{
			return ;
		}
	}
	*root = node;
}

t_box	find_box(t_obj obj)
{
	t_box	box;

	return (box);
}

t_box	regroup()