/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 00:28:38 by skim              #+#    #+#             */
/*   Updated: 2020/12/14 01:00:59 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

void	map_init(t_ptr *ptr)
{
	int map[ROW][COL] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(ptr->map, map, sizeof(int) * ROW * COL);
}

void	window_init(t_ptr *ptr)
{
	ptr->mlx = mlx_init();
	ptr->mlx = mlx_new_window(ptr->mlx, WIDTH, HEIGHT, "draw_map");
}

void	img_init(t_ptr *ptr)
{
	ptr->img.img_ptr = mlx_new_image(ptr->mlx, WIDTH, HEIGHT);
	ptr->img.data = (int *)mlx_get_data_arrd(ptr->img.img_ptr, &ptr->img.bpp, &ptr->img.size_l, &ptr->img.endian);
}

int		press_esc_key(int key_code, t_ptr *ptr)
{
	if (key_code == KEY_ESC && ptr)
		exit(0);
	return (0);
}

int		event_key_exit(t_ptr *ptr)
{
	exit(0);
}

int		main(void)
{
	t_ptr	ptr;

	map_init(&ptr);
	window_init(&ptr);
	img_init(&ptr);

	mlx_key_hook(ptr.win, press_esc_key, &ptr);
	mlx_hook(ptr.win, X_EVENT_KEY_EXIT, 0, &event_key_exit, &ptr);
	
}
