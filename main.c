/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:42:42 by cviel             #+#    #+#             */
/*   Updated: 2025/10/13 17:42:26 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ret_val.h"

int main(int ac, char **av)
{
    int	ret;

	if (ac == 1)
	{
		printf("Error\n");
		printf("You must specify a path to a .rt file\n");
		return (ERROR_ARGUMENT);
	}
	ret = parsing(av[1]);
	if (ret != 0)
		return (ret);
	return (0);
}