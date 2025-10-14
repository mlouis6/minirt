/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:07:33 by mlouis            #+#    #+#             */
/*   Updated: 2024/11/18 13:17:40 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	offset;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	offset = 0;
	if (size == 0 || size <= len_dst)
		return (size + len_src);
	size--;
	while (size - len_dst > offset && src[offset])
	{
		dst[len_dst + offset] = src[offset];
		offset++;
	}
	dst[len_dst + offset] = '\0';
	return (len_dst + len_src);
}
