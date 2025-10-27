/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 08:19:58 by cviel             #+#    #+#             */
/*   Updated: 2025/10/27 21:00:05 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	**split_line(char *line, char *set)
{
	char	**split;	
	int 	count;
    int 	i;
    
    count = count_words(line, set);
    split = malloc(sizeof(char *) * (count + 1));
    if (split == NULL)
        return (NULL);
    i = 0;
    while (*line != '\0')
    {
		count = word_len(line, set);
        if (count == 0)
            break ;
        split[i] = malloc(sizeof(char) * (count + 1));
        if (split[i] == NULL)
		{
			free_split(split);
            return (NULL);
		}
		while (ft_strchr(set, *line) != NULL)
			++i;
        ft_strlcpy(split[i], line, count + 1);
		++i;
    }
	split[i] = NULL;
	return (split);
}

int count_words(char *line, char *set)
{
    int nb_words;
    int i;

    nb_words = 0;
    i = 0;
    while (line[i] != '\0')
    {
        while (ft_strchr(set, line[i]) != NULL)
            ++i;
        if (line[i] == '\0')
            break ;
		++nb_words;
		while (ft_strchr(set, line[i]) == NULL)
			++i;
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
