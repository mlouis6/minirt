/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:40:26 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/18 13:36:18 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	c1 = (unsigned char) *s1;
	c2 = (unsigned char) *s2;
	while ((c1 != '\0' || c2 != '\0') && n > 0)
	{
		if (c1 != c2)
			return (c1 - c2);
		s1++;
		s2++;
		c1 = (unsigned char) *s1;
		c2 = (unsigned char) *s2;
		n--;
	}
	return (0);
}
