/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:54:23 by skim              #+#    #+#             */
/*   Updated: 2021/03/05 19:28:43 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	is_save(t_set *set, char *av)
{
	if (!ft_strncmp("--save", av, 6))
		set->is_bmp = 1;
	else
	{
		printf("Error\nwrong second argument\n");
		cub3d_exit(set, 2);
	}
}

int		main_loop(t_set *set)
{
	key_action(set);
	floor_cast(set);
	wall_cast(set);
	sprite_cast(set);
	draw_map(set);
	life_bar(set);
	animated_sprite(set);
	make_secret_door(set);
	if (set->jump > 0 && set->jump < 15)
		set->jump += 3;
	if (set->is_bmp != 1)
		mlx_put_image_to_window(set->mlx, set->win, set->img.img_ptr, 0, 0);
	else
	{
		save_bmp_img(set);
		cub3d_exit(set, 2);
	}
	if (!set->life.life)
		cub3d_exit(set, 4);
	return (0);
}

void	mlx_add_event(t_set *set)
{
	mlx_hook(set->win, X_EVENT_KEY_PRESS, 0, &event_key_press, set);
	mlx_hook(set->win, X_EVENT_KEY_RELEASE, 0, &event_key_release, set);
	mlx_hook(set->win, X_EVENT_KEY_EXIT, 0, &event_exit, set);
	mlx_loop_hook(set->mlx, &main_loop, set);
}

void	set_start(t_set *set)
{
	set->map = 0;
	set->sprite = 0;
	set->minfo.no_path = 0;
	set->minfo.so_path = 0;
	set->minfo.we_path = 0;
	set->minfo.ea_path = 0;
	set->minfo.sp_path = 0;
	set->minfo.fl_path = 0;
	set->minfo.ce_path = 0;
	set->info.z_buffer = 0;
}

int		main(int ac, char **av)
{
	t_set	set;

	ft_memset(&set, 0, sizeof(t_set));
	if (ac != 2 && ac != 3)
	{
		printf("Error\nargument error\n");
		cub3d_exit(&set, 0);
	}
	set.mlx = mlx_init();
	if (ac == 3)
		is_save(&set, av[2]);
	else
		set.is_bmp = 0;
	if (!map_parse(&set, av[1]))
		return (cub3d_exit(&set, 2));
	if (!set_init(&set))
		return (cub3d_exit(&set, 2));
	make_texture(&set);
	if (set.is_bmp != 1)
	{
		play_sound_effect(1);
		play_bgm();
	}
	mlx_add_event(&set);
	mlx_loop(set.mlx);
	return (0);
}
