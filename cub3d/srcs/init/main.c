/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:54:23 by skim              #+#    #+#             */
/*   Updated: 2021/02/23 00:51:25 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	load_image(t_set *set, int tex_num, char *path)
{
	t_img	img;
	int		y;
	int		x;

	img.img_ptr = \
	mlx_xpm_file_to_image(set->mlx, path, &img.width, &img.height);
	img.data = \
	(int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	y = -1;
	while (++y < img.height)
	{
		x = -1;
		while (++x < img.width)
			set->info.texture[tex_num][img.width * y + x] = \
			img.data[img.width * y + x];
	}
	mlx_destroy_image(set->mlx, img.img_ptr);
}

void	make_texture(t_set *set)
{
	load_image(set, EA_TEXT_NUM, set->minfo.ea_path);
	load_image(set, WE_TEXT_NUM, set->minfo.we_path);
	load_image(set, SO_TEXT_NUM, set->minfo.so_path);
	load_image(set, NO_TEXT_NUM, set->minfo.no_path);
	if (set->minfo.floor_text)
		load_image(set, FL_TEXT_NUM, set->minfo.fl_path);
	if (set->minfo.ceiling_text)
		load_image(set, CE_TEXT_NUM, set->minfo.ce_path);
	load_image(set, SP_TEXT_NUM, set->minfo.sp_path);
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
	if (!(set->info.z_buffer = malloc(sizeof(double) * set->minfo.s_width)))
		return (-1);
	set->mlx = mlx_init();
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
	mlx_put_image_to_window(set->mlx, set->win, set->img.img_ptr, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	t_set	set;

	if (ac != 2 && ac != 3)
	{
		printf("Error\nNo map\n");
		return (-1);
	}
	if (!map_parse(&set, av[1]))
	{
		printf("Error\n");
		return (-1);
	}
	set_init(&set);
	make_texture(&set);
	mlx_hook(set.win, X_EVENT_KEY_PRESS, 0, &event_key_press, &set);
	mlx_hook(set.win, X_EVENT_KEY_RELEASE, 0, &event_key_release, &set);
	mlx_loop_hook(set.mlx, &main_loop, &set);
	mlx_loop(set.mlx);
}
