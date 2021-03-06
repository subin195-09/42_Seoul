/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:52:56 by skim              #+#    #+#             */
/*   Updated: 2021/03/06 16:41:06 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

int		cub3d_exit(t_set *set, int sound)
{
	if (sound != 0)
	{
		play_sound_effect(sound);
		system("killall find; killall afplay");
		if (set->win)
			mlx_destroy_window(set->mlx, set->win);
		if (set->img.img_ptr)
			mlx_destroy_image(set->mlx, set->img.img_ptr);
	}
	system("leaks cub3D");
	exit(0);
}

int		event_exit(t_set *set)
{
	cub3d_exit(set, 2);
	return (0);
}
