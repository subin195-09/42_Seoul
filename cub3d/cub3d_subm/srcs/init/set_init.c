/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:10:16 by skim              #+#    #+#             */
/*   Updated: 2021/03/04 17:17:22 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	set_init_key(t_set *set)
{
	set->key.key_up = 0;
	set->key.key_down = 0;
	set->key.key_right = 0;
	set->key.key_left = 0;
	set->key.key_sp = 0;
	set->key.key_look_up = 0;
	set->key.key_look_down = 0;
	set->key.key_look_right = 0;
	set->key.key_look_left = 0;
	set->key.key_q = 0;
}

void	set_init_bonus(t_set *set)
{
	set->life.life = 100;
	ft_memset(set->life.life_bar, 1, set->life.life);
	set->time_stamp = 0;
	set->jump = 0;
	set->s_door.is_hidden = 0;
	set->s_door.h_text = 0;
}

int		set_init(t_set *set)
{
	set->info.move_speed = 0.05;
	set->info.rot_speed = 0.03;
	set_init_key(set);
	set_init_bonus(set);
	if (!(set->info.z_buffer = malloc(sizeof(double) * set->minfo.s_width)))
		return (-1);
	set->win = \
	mlx_new_window(set->mlx, set->minfo.s_width, set->minfo.s_height, "cub3d");
	set->img.img_ptr = \
	mlx_new_image(set->mlx, set->minfo.s_width, set->minfo.s_height);
	set->img.data = \
	(int *)mlx_get_data_addr(set->img.img_ptr, \
	&set->img.bpp, &set->img.size_l, &set->img.endian);
	return (1);
}
