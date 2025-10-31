/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:13:25 by cviel             #+#    #+#             */
/*   Updated: 2025/10/31 20:38:55 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ret_val.h"
#include "bvh.h"

double	cost(t_bvh *root, t_bvh *node);
t_box	find_box(t_obj obj);
t_box	box_regroup(t_box box1, t_box box2);
int		box_contained(t_box big, t_box small);
t_bvh	*find_insert(t_bvh *root, t_bvh *node, double *ptr_cost);
int		insert_above(t_bvh **ptr_root, t_bvh *node);

int	bvh_add(t_bvh **ptr_root, t_bvh *node)
{
	int		ret;
	t_bvh	*insert;
	
	node->box = find_box(node->obj);
	if (*ptr_root != NULL)
	{
		if ((*ptr_root)->obj.type != NONE || box_contained((*ptr_root)->box, node->box) == FALSE)
			ret = insert_above(ptr_root, node);
		else
		{
			insert = find_insert(*ptr_root, node, NULL);
			ret = bvh_add(&insert, node);
		}
		if (ret != SUCCESS)
			return (ret);
		(*ptr_root)->nb_leaves = (*ptr_root)->left->nb_leaves + (*ptr_root)->right->nb_leaves;
		return (SUCCESS);
	}
	*ptr_root = node;
	node->nb_leaves = 1;
	return (SUCCESS);
}

int	box_contained(t_box big, t_box small)
{
	if (big.x_min > small.x_min
		|| big.x_max < small.x_max
		|| big.y_min > small.y_min
		|| big.y_max < small.y_max
		|| big.z_min > small.z_min
		|| big.z_max < small.z_max)
	{
		return (FALSE);
	}
	return (TRUE);
}

int	insert_above(t_bvh **ptr_root, t_bvh *node)
{
	t_bvh	*new_root;

	new_root = malloc(sizeof(t_bvh));
	if (new_root == NULL)
		return (ERROR_MALLOC);
	new_root->obj.type = NONE;
	new_root->left = *ptr_root;
	new_root->right = node;
	new_root->box = box_regroup((*ptr_root)->box, node->box);
	*ptr_root = new_root;
	(*ptr_root)->nb_leaves = (*ptr_root)->left->nb_leaves + (*ptr_root)->right->nb_leaves;
	return (SUCCESS);
}

double	cost(t_bvh *root, t_bvh *node)
{
	t_box	box;

	box = box_regroup(root->box, node->box);
	return (2 * ((box.x_max - box.x_min) * (box.y_max - box.y_min) + \
			(box.x_max - box.x_min) * (box.z_max - box.z_min) + \
			(box.y_max - box.y_min) * (box.z_max - box.z_min)
			* (root->nb_leaves + 1)));
}

t_bvh	*find_insert(t_bvh *root, t_bvh *node, double *ptr_cost)
{
	double	left_cost;
	double	right_cost;
	t_bvh	*left_path;
	t_bvh	*right_path;
	
	left_path = root->left;
	right_path = root->right;
	left_cost = cost(root->left, node);
	right_cost = cost(root->right, node);
	if (left_cost == right_cost)
	{
		if (left_path->obj.type == NONE && box_contained(left_path->box, node->box) == TRUE)
			left_path = find_insert(left_path, node, &left_cost);
		if (left_path->obj.type == NONE && box_contained(right_path->box, node->box) == TRUE)
			right_path = find_insert(right_path, node, &right_cost);
	}
	if (left_cost < right_cost)
		return (left_path);
	return (right_path);
}

t_box	find_box(t_obj obj)
{
	t_box	box;

	return (box);
}

t_box	box_regroup(t_box box1, t_box box2)
{
	t_box box;

	box.x_min = min(box1.x_min, box2.x_min);
	box.x_max = max(box1.x_max, box2.x_max);
	box.y_min = min(box1.y_min, box2.y_min);
	box.y_max = max(box1.y_max, box2.y_max);
	box.z_min = min(box1.z_min, box2.z_min);
	box.z_max = max(box1.z_max, box2.z_max);
	return (box);
}