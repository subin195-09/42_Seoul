/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:29:02 by skim              #+#    #+#             */
/*   Updated: 2021/03/02 23:48:10 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	key_up(t_set *set)
{
	int		flag;

	flag = -1;
	if (set->map\
	[(int)(set->info.pos_x + set->info.dir_x * set->info.move_speed)]\
	[(int)(set->info.pos_y)] == 0)
		set->info.pos_x += \
		set->info.dir_x * set->info.move_speed;
	else
		flag++;
	if (set->map[(int)(set->info.pos_x)]\
	[(int)(set->info.pos_y + set->info.dir_y * set->info.move_speed)] == 0)
		set->info.pos_y += set->info.dir_y * set->info.move_speed;
	else
		flag++;
	if (flag >= 0)
	{
		set->life.life = set->life.life == 0 ? 0 : set->life.life - 1;
		play_sound_effect(3);
	}
}

void	key_down(t_set *set)
{
	int		flag;

	flag = -1;
	if (set->map\
	[(int)(set->info.pos_x - set->info.dir_x * set->info.move_speed)]\
	[(int)(set->info.pos_y)] == 0)
		set->info.pos_x -= \
		set->info.dir_x * set->info.move_speed;
	else
		flag++;
	if (set->map[(int)(set->info.pos_x)]\
	[(int)(set->info.pos_y - set->info.dir_y * set->info.move_speed)] == 0)
		set->info.pos_y -= set->info.dir_y * set->info.move_speed;
	else
		flag++;
	if (flag >= 0)
	{
		set->life.life = set->life.life == 0 ? 0 : set->life.life - 1;
		play_sound_effect(3);
	}
}

void	key_left(t_set *set)
{
	double	old_dir_x;
	double	old_dir_y;
	int		flag;

	flag = -1;
	old_dir_x = \
	set->info.dir_x * cos(M_PI_2) - set->info.dir_y * sin(M_PI_2);
	old_dir_y = \
	set->info.dir_x * sin(M_PI_2) + set->info.dir_y * cos(M_PI_2);
	if (set->map\
	[(int)(set->info.pos_x + old_dir_x * set->info.move_speed)]\
	[(int)(set->info.pos_y)] == 0)
		set->info.pos_x += old_dir_x * set->info.move_speed;
	else
		flag++;
	if (set->map[(int)(set->info.pos_x)]\
	[(int)(set->info.pos_y + old_dir_y * set->info.move_speed)] == 0)
		set->info.pos_y += old_dir_y * set->info.move_speed;
	else
		flag++;
	if (flag >= 0)
	{
		set->life.life = set->life.life == 0 ? 0 : set->life.life - 1;
		play_sound_effect(3);
	}
}

void	key_right(t_set *set)
{
	double old_dir_x;
	double old_dir_y;
	int		flag;

	flag = -1;
	old_dir_x = \
	set->info.dir_x * cos(M_PI_2) - set->info.dir_y * sin(M_PI_2);
	old_dir_y = \
	set->info.dir_x * sin(M_PI_2) + set->info.dir_y * cos(M_PI_2);
	if (set->map\
	[(int)(set->info.pos_x - old_dir_x * set->info.move_speed)]\
	[(int)(set->info.pos_y)] == 0)
		set->info.pos_x -= old_dir_x * set->info.move_speed;
	else
		flag++;
	if (set->map[(int)(set->info.pos_x)]\
	[(int)(set->info.pos_y - old_dir_y * set->info.move_speed)] == 0)
		set->info.pos_y -= old_dir_y * set->info.move_speed;
	else
		flag++;
	if (flag >= 0)
	{
		set->life.life = set->life.life == 0 ? 0 : set->life.life - 1;
		play_sound_effect(3);
	}
}

void	key_action(t_set *set)
{
	if (set->key.key_up)
		key_up(set);
	if (set->key.key_down)
		key_down(set);
	if (set->key.key_right)
		key_right(set);
	if (set->key.key_left)
		key_left(set);
	if (set->key.key_look_up)
		set->up += 2;
	if (set->key.key_look_down)
		set->up -= 2;
	if (set->key.key_look_left)
		key_look_left(set);
	if (set->key.key_look_right)
		key_look_right(set);
}
