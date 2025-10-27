/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 08:27:51 by mlouis            #+#    #+#             */
/*   Updated: 2025/10/27 13:07:30 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

int	find_endl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i + 1);
	return (0);
}

char	*cut_endl(char *str, int n)
{
	int	i;

	i = 0;
	while (str[n + i])
	{
		str[i] = str[n + i];
		str[n + i] = '\0';
		i++;
	}
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * n + 1);
	if (!str)
	{
		free (s1);
		return (NULL);
	}
	i = 0;
	while (s1 && (s1[i] != '\0' && i < n))
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0' && (i + j) < n)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free (s1);
	return (str);
}
