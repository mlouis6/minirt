/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:40:25 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/18 12:27:40 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr_s;

	ptr_s = (unsigned char *) s;
	while (n--)
	{
		*ptr_s = (unsigned char) c;
		ptr_s++;
	}
	return (s);
}
