/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:52:55 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/18 13:55:23 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_l;

	i = 0;
	len_l = ft_strlen(little);
	if (*little == '\0' || len < 0)
		return ((char *) big);
	if (len_l > ft_strlen(big) || len_l > len)
		return (NULL);
	while (len-- && big[i] != '\0')
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] == little[j] && j <= len)
			j++;
		if (j == len_l)
			return ((char *) big + i);
		i++;
	}
	return (NULL);
}
