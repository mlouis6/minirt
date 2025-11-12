/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:35:45 by cviel             #+#    #+#             */
/*   Updated: 2025/11/12 14:50:15 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (*ptr_str >= '0' && *ptr_str <= '9')
	{
		res = res * 10 + *ptr_str - '0';
		++ptr_str;
	}
	*ptr_end = ptr_str;
	return (res * sign);
}
