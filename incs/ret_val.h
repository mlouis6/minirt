/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_val.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:45:55 by cviel             #+#    #+#             */
/*   Updated: 2025/10/27 21:52:50 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RET_VAL_H
# define RET_VAL_H

# define TRUE 1
# define FALSE 0

# define WHITE_SPACES "\t\n\v\f\r "

enum e_ret_val
{
	SUCCESS = 0,
	ERROR_ARGUMENT,
	ERROR_SYSCALL,
	ERROR_MALLOC,
	ERROR_FILENAME,
	INVALID_FILE
};

#endif