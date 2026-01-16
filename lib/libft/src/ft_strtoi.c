/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:35:45 by cviel             #+#    #+#             */
/*   Updated: 2026/01/16 17:05:57 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strtoi(char *ptr_str, char **ptr_end, int *ptr_n)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*ptr_str == '-')
	{
		sign = -1;
		++ptr_str;
	}
	else if (*ptr_str == '+')
		++ptr_str;
	while (*ptr_str >= '0' && *ptr_str <= '9')
	{
		res = res * 10 + (*ptr_str - '0') * sign;
		if (res > __INT_MAX__ || res < -__INT_MAX__ - 1)
			return (1);
		++ptr_str;
	}
	*ptr_end = ptr_str;
	*ptr_n = res;
	return (0);
}
