/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:45:51 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/18 12:56:18 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;

	ptr_d = (unsigned char *) dest;
	ptr_s = (unsigned char *) src;
	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	if (dest > src)
	{
		ptr_d += n - 1;
		ptr_s += n - 1;
		while (n--)
		{
			*ptr_d = *ptr_s;
			ptr_d--;
			ptr_s--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
