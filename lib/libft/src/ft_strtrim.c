/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:37:58 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/18 16:51:08 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
	args:	s1 = str to br trimed
			set = chars to trim
	
	return:	trimmed str (begin & end from set chars)
			|| NULL is malloc fails
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	check_b;
	size_t	check_e;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	check_b = 0;
	while (ft_strchr(set, s1[check_b]) != NULL)
		check_b++;
	check_e = ft_strlen(s1);
	while (ft_strrchr(set, s1[check_e]) != NULL && check_e > 0)
		check_e--;
	check_e++;
	if (check_b > check_e)
		check_e = check_b;
	str = malloc(sizeof(char) * (check_e - check_b) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while ((check_b + (i++)) < check_e)
		str[i - 1] = s1[check_b + (i - 1)];
	str[i - 1] = '\0';
	return (str);
}
