/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:29:08 by skim              #+#    #+#             */
/*   Updated: 2021/02/22 18:29:18 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

int		event_key_press(int keycode, t_set *set)
{
	if (keycode == KEY_UP)
		set->key.key_up = 1;
	if (keycode == KEY_DOWN)
		set->key.key_down = 1;
	if (keycode == KEY_RIGHT)
		set->key.key_right = 1;
	if (keycode == KEY_LEFT)
		set->key.key_left = 1;
	if (keycode == KEY_SP)
		set->key.key_sp = set->key.key_sp == 0 ? 1 : 0;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(set->mlx, set->win);
		exit(0);
	}
	if (keycode == 11)
	{
		save_bmp_img(set);
		mlx_destroy_image(set->mlx, set->img.img_ptr);
		mlx_destroy_window(set->mlx, set->win);
		exit(0);
	}
	return (0);
}

int		event_key_release(int keycode, t_set *set)
{
	if (keycode == KEY_UP)
		set->key.key_up = 0;
	if (keycode == KEY_DOWN)
		set->key.key_down = 0;
	if (keycode == KEY_RIGHT)
		set->key.key_right = 0;
	if (keycode == KEY_LEFT)
		set->key.key_left = 0;
	return (0);
}
