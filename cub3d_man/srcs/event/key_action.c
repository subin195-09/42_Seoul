/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:29:02 by skim              #+#    #+#             */
/*   Updated: 2021/02/28 17:09:59 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	key_up(t_set *set)
{
	if (set->map\
	[(int)(set->info.pos_x + set->info.dir_x * set->info.move_speed)]\
	[(int)(set->info.pos_y)] == 0)
		set->info.pos_x += \
		set->info.dir_x * set->info.move_speed;
	if (set->map[(int)(set->info.pos_x)]\
	[(int)(set->info.pos_y + set->info.dir_y * set->info.move_speed)] == 0)
		set->info.pos_y += set->info.dir_y * set->info.move_speed;
}

void	key_down(t_set *set)
{
	if (set->map\
	[(int)(set->info.pos_x - set->info.dir_x * set->info.move_speed)]\
	[(int)(set->info.pos_y)] == 0)
		set->info.pos_x -= \
		set->info.dir_x * set->info.move_speed;
	if (set->map[(int)(set->info.pos_x)]\
	[(int)(set->info.pos_y - set->info.dir_y * set->info.move_speed)] == 0)
		set->info.pos_y -= set->info.dir_y * set->info.move_speed;
}

void	key_right(t_set *set)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = set->info.dir_x;
	set->info.dir_x = \
	set->info.dir_x * \
	cos(-set->info.rot_speed) - set->info.dir_y * sin(-set->info.rot_speed);
	set->info.dir_y = \
	old_dir_x * \
	sin(-set->info.rot_speed) + set->info.dir_y * cos(-set->info.rot_speed);
	old_plane_x = set->info.plane_x;
	set->info.plane_x = \
	set->info.plane_x * cos(-set->info.rot_speed) - \
	set->info.plane_y * sin(-set->info.rot_speed);
	set->info.plane_y = \
	old_plane_x * sin(-set->info.rot_speed) + \
	set->info.plane_y * cos(-set->info.rot_speed);
}

void	key_left(t_set *set)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = set->info.dir_x;
	set->info.dir_x = \
	set->info.dir_x * \
	cos(set->info.rot_speed) - set->info.dir_y * sin(set->info.rot_speed);
	set->info.dir_y = \
	old_dir_x * \
	sin(set->info.rot_speed) + set->info.dir_y * cos(set->info.rot_speed);
	old_plane_x = set->info.plane_x;
	set->info.plane_x = \
	set->info.plane_x * \
	cos(set->info.rot_speed) - set->info.plane_y * sin(set->info.rot_speed);
	set->info.plane_y = \
	old_plane_x * \
	sin(set->info.rot_speed) + set->info.plane_y * cos(set->info.rot_speed);
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
}
