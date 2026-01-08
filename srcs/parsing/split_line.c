/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 08:19:58 by cviel             #+#    #+#             */
/*   Updated: 2026/01/08 17:59:28 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

size_t	count_words(char *line, char *set);
size_t	word_len(char **ptr_line, char *set);
char	*fill_word(char **ptr_line, size_t len);
void	free_split(char **split);

char	**split_line(char *line, char *set)
{
	char	**split;	
	size_t	count;
	size_t	i;

	count = count_words(line, set);
	split = malloc(sizeof(char *) * (count + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (*line != '\0')
	{
		count = word_len(&line, set);
		if (count == 0)
			break ;
		split[i] = fill_word(&line, count);
		if (split[i] == NULL)
		{
			free_split(split);
			return (NULL);
		}
		++i;
	}
	split[i] = NULL;
	return (split);
}

size_t	count_words(char *line, char *set)
{
	int	nb_words;

	nb_words = 0;
	while (*line != '\0')
	{
		while (*line != '\0' && ft_strchr(set, *line) != NULL)
			++line;
		if (*line == '\0')
			break ;
		++nb_words;
		while (ft_strchr(set, *line) == NULL)
			++line;
	}
	return (nb_words);
}

size_t	word_len(char **ptr_line, char *set)
{
	int	len_word;

	len_word = 0;
	while (**ptr_line != '\0' && ft_strchr(set, **ptr_line) != NULL)
		++(*ptr_line);
	while ((*ptr_line)[len_word] != '\0' && ft_strchr(set, (*ptr_line)[len_word]) == NULL)
		++len_word;
	return (len_word);
}

char	*fill_word(char **ptr_line, size_t len)
{
	char	*split_i;
	size_t	i;
	
	split_i = malloc(sizeof(char) * (len + 1));
	if (split_i == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		split_i[i] = **ptr_line;
		++(*ptr_line);
		++i;
	}
	split_i[i] = '\0';
	return (split_i);
}

void	free_split(char **split)
{
	int	i;

	if (split == NULL)
		return ;
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		++i;
	}
	free(split);
}
