/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:23:22 by mlouis            #+#    #+#             */
/*   Updated: 2025/02/15 14:00:26 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
	args:	s1 = prefix
			s2 = suffix

	return:	new str (s1 + s2)
			|| NULL if malloc fails
 */
static int	join_helper(char *dst, char *src, int offset);
static char	*null_str_manager(char *s1, char *s2);

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (null_str_manager(s1, s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	i = join_helper(str, s1, 0);
	j = join_helper(str, s2, i);
	str[i + j] = '\0';
	free(s1);
	return (str);
}

static int	join_helper(char *dst, char *src, int offset)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[offset + i] = src[i];
		i++;
	}
	return (i);
}

static char	*null_str_manager(char *s1, char *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		str = ft_strdup(s2);
	else
		str = ft_strdup(s1);
	if (!str)
		return (NULL);
	return (str);
}
