/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_val.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:45:55 by cviel             #+#    #+#             */
/*   Updated: 2025/10/22 16:55:25 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RET_VAL_H
# define RET_VAL_H

enum e_ret_val
{
	SUCCESS = 0,
	ERROR_ARGUMENT,
	ERROR_FILENAME,
	ERROR_SYSCALL,
	ERROR_MALLOC
};

#endif