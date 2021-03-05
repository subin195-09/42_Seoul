/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:52:56 by skim              #+#    #+#             */
/*   Updated: 2021/03/05 18:05:15 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	free_set(t_set *set)
{
	int		i;

	i = -1;
	while (++i < set->minfo.m_height)
		ft_frees(1, set->map[i]);
	ft_frees(2, set->map, set->sprite);
	ft_frees(2, set->minfo.no_path, set->minfo.so_path);
	ft_frees(2, set->minfo.we_path, set->minfo.ea_path);
	ft_frees(3, set->minfo.sp_path, set->minfo.fl_path, set->minfo.ce_path);
	ft_frees(1, set->info.z_buffer);
}

int		cub3d_exit(t_set *set, int sound)
{
	play_sound_effect(sound);
	system("killall find; killall afplay");
	free_set(set);
	mlx_destroy_window(set->mlx, set->win);
	mlx_destroy_image(set->mlx, set->img.img_ptr);
	system("leaks cub3D");
	exit(0);
}

int		event_exit(t_set *set)
{
	cub3d_exit(set, 2);
	return (0);
}
