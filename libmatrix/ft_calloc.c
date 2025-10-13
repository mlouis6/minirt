/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:57:44 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/18 16:43:20 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;
	size_t	total;

	total = nmemb * size;
	if (total == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if (nmemb != 0 && total / nmemb != size)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
