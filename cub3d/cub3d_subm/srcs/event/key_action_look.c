/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action_look.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 22:55:48 by skim              #+#    #+#             */
/*   Updated: 2021/03/02 22:56:49 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	key_look_right(t_set *set)
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

void	key_look_left(t_set *set)
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
