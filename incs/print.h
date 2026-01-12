/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:53:15 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/12 19:22:32 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "scene.h"
# include "ft_vector.h"

void	print_scene(t_scene scene);
void	print_obj(t_vector *obj);
void	print_error(int err);

#endif
