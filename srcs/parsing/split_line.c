/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 08:19:58 by cviel             #+#    #+#             */
/*   Updated: 2025/10/25 08:53:51 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ret_val.h"

int	split_line(char *line, char *set, char ***ptr_split)
{
    int nb_words;
    int len_word;
    int i;
    int j;
    
    *ptr_split = NULL;
    nb_words = count_words(line, set);
    if (nb_words == 0)
        return (SUCCESS);
    *ptr_split = malloc(sizeof(char *) * (nb_words + 1));
    if (*ptr_split == NULL)
        return (ERROR_MALLOC);
    i = 0;
    j = 0;
    while (line[i] != '\0')
    {
		len_word = word_len(line + i, set);
        if (len_word == 0)
            break ;
        *ptr_split[j] = malloc(sizeof(char) * (len_word + 1));
        if (*ptr_split[j] == NULL)
            return (ERROR_MALLOC);
        ft_strlcpy(*ptr_split[j], line, len_word + 1);
        ++j;
    }
	*ptr_split[j] = NULL;
    return (SUCCESS);
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
