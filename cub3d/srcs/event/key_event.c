/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:29:08 by skim              #+#    #+#             */
/*   Updated: 2021/03/02 17:40:20 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	cub3d_exit(t_set *set, int sound)
{
	play_sound_effect(sound);
	system("killall find; killall afplay");
	mlx_destroy_window(set->mlx, set->win);
	exit(0);
}

int		event_key_press(int keycode, t_set *set)
{
	if (keycode == KEY_W)
		set->key.key_up = 1;
	if (keycode == KEY_S)
		set->key.key_down = 1;
	if (keycode == KEY_D)
		set->key.key_right = 1;
	if (keycode == KEY_A)
		set->key.key_left = 1;
	if (keycode == KEY_SP)
		set->key.key_sp = set->key.key_sp == 0 ? 1 : 0;
	if (keycode == KEY_UP)
		set->key.key_look_up = 1;
	if (keycode == KEY_DOWN)
		set->key.key_look_down = 1;
	if (keycode == KEY_ESC)
		cub3d_exit(set, 2);
	if (keycode == KEY_J)
		set->jump += 15;
	return (0);
}

int		event_key_release(int keycode, t_set *set)
{
	if (keycode == KEY_W)
		set->key.key_up = 0;
	if (keycode == KEY_S)
		set->key.key_down = 0;
	if (keycode == KEY_D)
		set->key.key_right = 0;
	if (keycode == KEY_A)
		set->key.key_left = 0;
	if (keycode == KEY_UP)
		set->key.key_look_up = 0;
	if (keycode == KEY_DOWN)
		set->key.key_look_down = 0;
	if (keycode == KEY_J)
		set->jump = 0;
	return (0);
}
