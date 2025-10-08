/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviel <cviel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:08:50 by cviel             #+#    #+#             */
/*   Updated: 2025/10/08 18:16:50 by cviel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef	struct s_cam
{
	t_pt	pos;
	t_vect	normal;
	float	fov;
}	t_cam;

typedef struct s_amb
{
	float			ratio;
	unsigned char	color[3];
}	t_amb;

typedef struct s_light
{
	t_pt			pos;
	float			ratio;
	unsigned char	color[3];
}	t_light;

#endif