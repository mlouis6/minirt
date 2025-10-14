/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:36:31 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/29 17:32:06 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*src;
	char	*cpy;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	src = (char *) s;
	len = ft_strlen(src);
	cpy = malloc(sizeof(*src) * len + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
