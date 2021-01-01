/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 00:28:38 by skim              #+#    #+#             */
/*   Updated: 2021/01/01 18:55:54 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

void	swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

//Bresenham 알고리즘 방식
void	draw_line(t_ptr *ptr, int x1, int y1, int x2, int y2)
{
	int flag = 0;
	if (x2 == x1)
	{
		swap(&x1, &y1);
		swap(&x2, &y2);
		flag = 1;
	}
	int x = x1;
	int y = y2;

	int w = x2 - x1;
	int h = y2 - y1;

	int f = 2 * h - w;

	int delta_f1 = 2 * h;
	int delta_f2 = 2 * (h - w);

	for(x = x1; x < x2; x++)
	{
		if (flag)
			ptr->img.data[x * WIDTH + y] = 0xb3b3b3;
		else
			ptr->img.data[y * WIDTH + x] = 0xb3b3b3;
		if (f < 0)
			f += delta_f1;
		else
		{
			y++;
			f += delta_f2;
		}
	}
}

//DDA 알고리즘 방식
// void	draw_line(t_ptr *ptr, double x1, double y1, double x2, double y2)
// {
// 	// x 증가량
// 	double delta_x = x2 - x1;
// 	// y 증가량
// 	double delta_y = y2 - y1;

// 	// x의 증가량, y의 증가량 중 큰 것을 기준으로 잡는다.
// 	double step = fabs(delta_x) > fabs(delta_y) ? fabs(delta_x) : fabs(delta_y);

// 	// x의 증가량이 크다면 x는 1씩 증가하고, Y는 기울기만큼만 증가한다.
// 	// 반대로 y의 증가량이 크마녀 y는 1씩 증가하고, x는 1/기울기 만큼만 증가한다.
// 	delta_x /= step;
// 	delta_y /= step;
// 	while (x2 > x1 || y2 > y1)
// 	{
// 		ptr->img.data[(int)floor(y1) * WIDTH + (int)floor(x1)] = 0xb3b3b3;
// 		x1 += delta_x;
// 		y1 += delta_y;
// 	}
// }

void	draw_all_line(t_ptr *ptr)
{
	int	i;
	int	j;

	// 세로 선 그리기
	i = 0;
	while (i < COL)
	{
		draw_line(ptr, i * TILE_SIZE, 0, i * TILE_SIZE, HEIGHT);
		i++;
	}

	// 가로 선 그리기
	j = 0;
	while (j < ROW)
	{
		draw_line(ptr, 0, j * TILE_SIZE, WIDTH, j * TILE_SIZE);
		j++;
	}
}

void	draw_rect(t_ptr *ptr, int x, int y)
{
	int i;
	int j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			ptr->img.data[(y + i) * WIDTH + x + j] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}

void	draw_all_rect(t_ptr *ptr)
{
	int i;
	int j;

	i = 0;
	while (i < ROW)
	{
		j = 0;
		while (j < COL)
		{
			if (ptr->map[i][j] == 1)
				draw_rect(ptr, j, i);
			j++;
		}
		i++;
	}
}

int		move_player(t_ptr *ptr)
{
	if(ptr->left == 1 && ptr->x >= 3)
		ptr->x -= 3;
	if (ptr-> right == 1 && ptr->x + TILE_SIZE < WIDTH)
		ptr->x += 3;
	if (ptr->up == 1 && ptr->y >= 3)
		ptr->y -= 3;
	if (ptr->down == 1 && ptr->y + TILE_SIZE < HEIGHT)
		ptr->y += 3;
	return (0);
}

int		draw_player(t_ptr *ptr)
{
	for(int i = 0; i < HEIGHT; i++)
		for(int j = 0; j < WIDTH; j++)
			ptr->img.data[i * WIDTH + j] = 0;
	for(int i = ptr->y; i < ptr->y + TILE_SIZE; i++)
	{
		for(int j = ptr->x; j < ptr->x + TILE_SIZE; j++)
			ptr->img.data[(i * WIDTH + j)] = 0xff0000;
	}
	return (0);
}

int		main_loop(t_ptr *ptr)
{
	draw_player(ptr);
	move_player(ptr);
	draw_all_rect(ptr);
	draw_all_line(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img_ptr, 0, 0);
	return (0);
}

int		event_key_press(int keycode, t_ptr *ptr)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		exit(0);
	}
	if (keycode == KEY_LEFT)
		ptr->left = 1;
	else if (keycode == KEY_RIGHT)
		ptr->right = 1;
	else if (keycode == KEY_UP)
		ptr->up = 1;
	else if (keycode == KEY_DOWN)
		ptr->down = 1;
	return (0);
}

int		event_key_release(int keycode, t_ptr *ptr)
{
	if (keycode == KEY_LEFT)
		ptr->left = 0;
	else if (keycode == KEY_RIGHT)
		ptr->right = 0;
	else if (keycode == KEY_UP)
		ptr->up = 0;
	else if (keycode == KEY_DOWN)
		ptr->down = 0;
	return (0);
}

int		event_key_exit(t_ptr *ptr)
{
	if (ptr)
		exit(0);
	return (0);
}

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
	ptr->win = mlx_new_window(ptr->mlx, WIDTH, HEIGHT, "draw_map");
}

void	img_init(t_ptr *ptr)
{
	ptr->img.img_ptr = mlx_new_image(ptr->mlx, WIDTH, HEIGHT);
	ptr->img.data = (int *)mlx_get_data_addr(ptr->img.img_ptr, &ptr->img.bpp, &ptr->img.size_l, &ptr->img.endian);
}

int		main(void)
{
	t_ptr	ptr;

	map_init(&ptr);
	window_init(&ptr);
	img_init(&ptr);

	ptr.x = TILE_SIZE;
	ptr.y = TILE_SIZE;
	ptr.up = 0;
	ptr.down = 0;
	ptr.right = 0;
	ptr.left = 0;

	// key_hook : 키를 눌렀을때 발생
	// mlx_hook 에서 두번째 인자를 2(키가 눌렸다는 신호)를 넣어주면 key_hook와 같은 동작을 하게 할 수 있다.
	//mlx_hook(ptr.win, 2, 0, &press_esc_key, &ptr);
	// mlx_hook : 종료 키코드가 들어왔을때 발생
	//mlx_key_hook(ptr.win, press_esc_key, &ptr);

	// player와 관련된 key event 추가하기
	mlx_hook(ptr.win, X_EVENT_KEY_PRESS, 0, &event_key_press, &ptr);
	mlx_hook(ptr.win, X_EVENT_KEY_RELEASE, 0, &event_key_release, &ptr);

	mlx_hook(ptr.win, X_EVENT_KEY_EXIT, 0, &event_key_exit, &ptr);

	// // 아무런 이벤트가 발생하지 않았을 때 인자로 받은 함수 (main_loop)를 호출한다.
	mlx_loop_hook(ptr.mlx, &main_loop, &ptr);

	// 입력이벤트를 받기위해 사용하는 함수
	mlx_loop(ptr.mlx);
}
