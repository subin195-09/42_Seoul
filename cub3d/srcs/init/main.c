/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:54:23 by skim              #+#    #+#             */
/*   Updated: 2021/03/03 22:35:19 by skim             ###   ########.fr       */
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
		exit(0);
	}
}

int		set_init(t_set *set)
{
	set->info.move_speed = 0.05;
	set->info.rot_speed = 0.03;
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
	set->life.life = 100;
	set->time_stamp = 0;
	set->jump = 0;
	set->s_door.is_hidden = 0;
	set->s_door.h_text = 0;
	ft_memset(set->life.life_bar, 1, set->life.life);
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
	if (!set->is_bmp)
		mlx_put_image_to_window(set->mlx, set->win, set->img.img_ptr, 0, 0);
	else
	{
		save_bmp_img(set);
		mlx_destroy_image(set->mlx, set->img.img_ptr);
		mlx_destroy_window(set->mlx, set->win);
		exit(0);
	}
	if (!set->life.life)
		cub3d_exit(set, 4);
	return (0);
}

int		main(int ac, char **av)
{
	t_set	set;

	if (ac != 2 && ac != 3)
	{
		printf("Error\nargument error\n");
		return (-1);
	}
	set.mlx = mlx_init();
	if (ac == 3)
		is_save(&set, av[2]);
	else
		set.is_bmp = 0;
	if (!map_parse(&set, av[1]))
		return (0);
	set_init(&set);
	make_texture(&set);
	play_sound_effect(1);
	play_bgm();
	mlx_hook(set.win, X_EVENT_KEY_PRESS, 0, &event_key_press, &set);
	mlx_hook(set.win, X_EVENT_KEY_RELEASE, 0, &event_key_release, &set);
	mlx_loop_hook(set.mlx, &main_loop, &set);
	mlx_loop(set.mlx);
}
