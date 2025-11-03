/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 08:19:58 by cviel             #+#    #+#             */
/*   Updated: 2025/11/03 23:28:14 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int count_words(char *line, char *set);
int	word_len(char *line, char *set);
void	free_split(char **split);

char	**split_line(char *line, char *set)
{
	char	**split;	
	int 	count;
    int 	i;
    
    count = count_words(line, set);
	#include <stdio.h>
	printf("line = %s\n", line);
	printf("count = %d", count);
    split = malloc(sizeof(char *) * (count + 1));
    if (split == NULL)
        return (NULL);
    i = 0;
    while (*line != '\0')
    {
		#include <stdio.h>
		printf("i = %d, line = '%c'\n", i, *line);
		while (ft_strchr(set, *line) != NULL)
			++line;
		count = word_len(line, set);
        if (count == 0)
            break ;
        split[i] = malloc(sizeof(char) * (count + 1));
        if (split[i] == NULL)
		{
			free_split(split);
            return (NULL);
		}
        ft_strlcpy(split[i], line, count + 1);
		while (*line != '\0' && ft_strchr(set, *line) == NULL)
			++line;
		++i;
    }
	split[i] = NULL;
	return (split);
}

int count_words(char *line, char *set)
{
    int nb_words;

    nb_words = 0;
    while (*line != '\0')
    {
        while (ft_strchr(set, *line) != NULL)
            ++line;
        if (*line == '\0')
            break ;
		printf("word_count : %d\n", *line);
		++nb_words;
		while (*line != '\0' && ft_strchr(set, *line) == NULL)
			++line;
    }
	return (nb_words);
}

int	word_len(char *line, char *set)
{
	int	len_word;

	len_word = 0;
	while (line[len_word] != '\0' && ft_strchr(set, line[len_word]) == NULL)
		++len_word;
	return (len_word);
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
