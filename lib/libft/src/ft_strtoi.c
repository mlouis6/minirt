/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:35:45 by cviel             #+#    #+#             */
/*   Updated: 2026/01/14 16:15:26 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strtoi(char *ptr_str, char **ptr_end)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (*ptr_str == '-')
	{
		sign = -1;
		++ptr_str;
	}
	else if (*ptr_str == '+')
		++ptr_str;
	while(*ptr_str == '0')
		ptr_str++;
	if (ft_strlen(ptr_str) > 12)
		return (-1);
	while (*ptr_str >= '0' && *ptr_str <= '9')
	{
		res = res * 10 + *ptr_str - '0';
		++ptr_str;
	}
	*ptr_end = ptr_str;
	return (res * sign);
}
