/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:48:36 by mlouis            #+#    #+#             */
/*   Updated: 2026/01/12 11:49:55 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "scene.h"

void	print_scene(t_scene scene)
{
	printf("A= [%.1f] [%d,%d,%d]\n", scene.amb.lightning,
		scene.amb.color.r, scene.amb.color.g, scene.amb.color.b);
	printf("C= [%.1f,%.1f,%.1f] [%.0f,%.0f,%.0f] [%d]\n",
		scene.cam.pos.x, scene.cam.pos.y, scene.cam.pos.z,
		scene.cam.dir.x, scene.cam.dir.y, scene.cam.dir.z, scene.cam.fov);
	printf("L= [%.1f,%.1f,%.1f] [%.1f] [%d,%d,%d]\n", scene.light.pos.x,
		scene.light.pos.y, scene.light.pos.z, scene.light.brightness,
		scene.light.color.r, scene.light.color.g, scene.light.color.b);
}
