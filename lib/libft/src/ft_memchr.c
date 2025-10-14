/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:30:32 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/18 13:44:27 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sc;
	unsigned char	cc;

	sc = (unsigned char *) s;
	cc = (unsigned char) c;
	while (n--)
	{
		if (*sc == cc)
			return (sc);
		sc++;
	}
	return (NULL);
}
