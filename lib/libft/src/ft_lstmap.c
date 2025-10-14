/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:22:38 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/29 11:10:39 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	node_failure_handler(
				t_list *lst, void *content, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*start;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	start = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		if (!tmp)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		node = ft_lstnew(tmp);
		if (!node)
		{
			node_failure_handler(start, tmp, del);
			return (NULL);
		}
		ft_lstadd_back(&start, node);
		lst = lst->next;
	}
	return (start);
}

static void	node_failure_handler(
	t_list *lst, void *content, void (*del)(void *))
{
	del(content);
	ft_lstclear(&lst, del);
}
