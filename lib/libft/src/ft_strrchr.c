/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:24:03 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/18 13:29:54 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cmp;
	size_t	len;

	cmp = (char) c;
	len = ft_strlen(s);
	s += len;
	while (len > 0 && *s != cmp)
	{
		s--;
		len--;
	}
	if (*s == cmp)
		return ((char *) s);
	return (NULL);
}
