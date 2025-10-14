/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:16:06 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/18 16:55:03 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
	*f ->	int: index of str
			char: new char of str[i]
 */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}
