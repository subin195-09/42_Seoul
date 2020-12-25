/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:51:55 by skim              #+#    #+#             */
/*   Updated: 2020/12/26 00:09:38 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

int ft_move(t_ptr *ptr)
{
	if(ptr->left == 1 && ptr->x > 0)
		ptr->x -= 1;
	if (ptr-> right == 1 && ptr->x + TILE_SIZE < WIDTH)
		ptr->x += 1;
	if (ptr->up == 1 && ptr->y > 0)
		ptr->y -= 1;
	if (ptr->down == 1 && ptr->y + TILE_SIZE < HEIGHT)
		ptr->y += 1;
	return (0);
}

int ft_draw(t_ptr *ptr)
{
	for(int i = ptr->y; i < TILE_SIZE; i++)
	{
		for(int j = ptr->x; j < TILE_SIZE; j++)
			ptr->img.data[(i * WIDTH + j) * TILE_SIZE] = 0xffffff;
	}
	return (0);
}

int	main_loop(t_ptr *ptr)
{
	ft_draw(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img_ptr, 0, 0);
	ft_move(ptr);
	return (0);
}

int	press_event(int keycode, t_ptr *ptr)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		exit(0);
	}
	if (keycode == KEY_LEFT)
		ptr->left = 1;
	else if (keycode == KEY_LEFT)
		ptr->right = 1;
	else if (keycode == KEY_UP)
		ptr->up = 1;
	else if (keycode == KEY_DOWN)
		ptr->down = 1;
	return (0);
}

int release_event(int keycode, t_ptr *ptr)
{
	if (keycode == KEY_LEFT)
		ptr->left = 1;
	else if (keycode == KEY_LEFT)
		ptr->right = 1;
	else if (keycode == KEY_UP)
		ptr->up = 1;
	else if (keycode == KEY_DOWN)
		ptr->down = 1;
	return (0);
}

int main(void)
{
	t_ptr	ptr;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIDTH, HEIGHT, "move");
	ptr.img.img_ptr = mlx_new_image(ptr.mlx, WIDTH, HEIGHT);
	ptr.img.data = mlx_get_data_addr(ptr.img.img_ptr, &ptr.img.bpp, &ptr.img.height, &ptr.img.endian);

	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img.img_ptr, 0, 0);
	ptr.x = WIDTH / 2;
	ptr.y = HEIGHT / 2;
	mlx_hook(ptr.win, X_EVENT_KEY_PRESS, 0, press_event, &ptr);
	mlx_hook(ptr.win, X_EVENT_KEY_RELEASE, 0, release_event, &ptr);
	mlx_loop_hook(ptr.mlx, main_loop, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
