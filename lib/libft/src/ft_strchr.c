/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:13:18 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/27 16:11:58 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	cmp;

	cmp = (char) c;
	while (*s != '\0' && *s != cmp && *s != cmp)
		s++;
	if (*s == cmp || *s == cmp)
		return ((char *) s);
	return (NULL);
}

int	ft_strchr_pos(const char *s, int c)
{
	char	cmp;
	int		i;

	i = 0;
	cmp = (char) c;
	while (*s != '\0' && *s != cmp && *s != cmp)
	{
		s++;
		i++;
	}
	if (*s == cmp || *s == cmp)
		return (i);
	return (-1);
}
