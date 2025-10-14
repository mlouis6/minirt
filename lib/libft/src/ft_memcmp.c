/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:55:12 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/18 13:45:41 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*sc1;
	unsigned char	*sc2;

	sc1 = (unsigned char *) s1;
	sc2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (n > 1)
	{
		if (*sc1 != *sc2)
			break ;
		sc1++;
		sc2++;
		n--;
	}
	return (*sc1 - *sc2);
}
