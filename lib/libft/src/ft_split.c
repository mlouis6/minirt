/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:50:23 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/14 18:40:52 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	nb_strings(char const *s, char c);
static size_t	next_str(char const *s, char c, size_t i);
static size_t	next_c(char const *s, char c);

/**
	args:	s = str to split
			c = delimiter char

	return:	strings[] (a new one per delimiter occurence + NULL)
			|| NULL is a malloc fails -> free before return
 */

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	n;
	size_t	len;
	size_t	nbs;

	nbs = nb_strings(s, c);
	strs = ft_calloc(sizeof(char *), nbs + 1);
	if (!strs || !s)
		return (NULL);
	i = 0;
	n = 0;
	while (n++ < nbs)
	{
		i = next_str(s, c, i);
		len = next_c(&s[i], c);
		strs[n - 1] = ft_substr(s, i, len);
		if (!strs[n - 1])
		{
			free_arr((void *)strs, n - 1);
			return (NULL);
		}
		i += len;
	}
	return (strs);
}

static size_t	nb_strings(char const *s, char c)
{
	size_t	count;
	size_t	i;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static size_t	next_str(char const *s, char c, size_t i)
{
	while (s[i] == c)
		i++;
	return (i);
}

static size_t	next_c(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}
