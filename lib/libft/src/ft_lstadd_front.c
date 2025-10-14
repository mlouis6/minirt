/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:49:07 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/29 11:09:32 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
	lst: address of ptr (1st of list)
	new: address of ptr new node

	add new at beginning of list
 */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		new->next = NULL;
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
