/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:33:41 by skim              #+#    #+#             */
/*   Updated: 2021/01/13 15:55:29 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fire.h"
#include "mlx.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	ver_line(t_ptr *ptr, double x1, double y1, double x2, double y2)
{
	double delta_x = cos(ptr->info.posX) * ptr->info.dirX - sin(ptr->info.posY) * ptr->info.dirY;
	// y 증가량
	double delta_y = sin(ptr->info.posX) * ptr->info.dirX + cos(ptr->info.posY) * ptr->info.dirY;

	// x의 증가량, y의 증가량 중 큰 것을 기준으로 잡는다.
	double step = fabs(delta_x) > fabs(delta_y) ? fabs(delta_x) : fabs(delta_y);

	// x의 증가량이 크다면 x는 1씩 증가하고, Y는 기울기만큼만 증가한다.
	// 반대로 y의 증가량이 크마녀 y는 1씩 증가하고, x는 1/기울기 만큼만 증가한다.
	delta_x /= step;
	delta_y /= step;
	while (x2 > x1 || y2 > y1)
	{
		ptr->img.data[(int)floor(y1) * screenWidth + (int)floor(x1)] = 0xb3b3b3;
		x1 += delta_x;
		y1 += delta_y;
	}
}

// DDA 알고리즘 방식
void	draw_line(t_ptr *ptr, double x1, double y1, double x2, double y2)
{
	double delta_x = ptr->info.dirX;
	// y 증가량
	double delta_y = ptr->info.dirY;

	// x의 증가량, y의 증가량 중 큰 것을 기준으로 잡는다.
	double step = fabs(delta_x) > fabs(delta_y) ? fabs(delta_x) : fabs(delta_y);

	// x의 증가량이 크다면 x는 1씩 증가하고, Y는 기울기만큼만 증가한다.
	// 반대로 y의 증가량이 크마녀 y는 1씩 증가하고, x는 1/기울기 만큼만 증가한다.
	delta_x /= step;
	delta_y /= step;
	while (x2 > x1 || y2 > y1)
	{
		ptr->img.data[(int)floor(y1) * screenWidth + (int)floor(x1)] = 0xb3b3b3;
		x1 += delta_x;
		y1 += delta_y;
	}
}

void	calc_ray(t_ptr *ptr)
{
	double w = screenWidth;
	for(int x = 0; x < (int)w; x++)
	{
		// pos + dir + k * plane 값이 내가 쏴야할 광선인데,
		// cameraX는 plane에 곱할 상수(k)를 의미한다
		// 범위는 -1 부터 1까지이다 (나중에 더 찾아볼것!!!!)
		double cameraX = 2 * x / w - 1;
		// 내가 쏴야하는 광선
		double rayDirX = ptr->info.dirX + ptr->info.planeX * cameraX;
		double rayDirY = ptr->info.dirY + ptr->info.planeY * cameraX;

		// pos의 단순 int값을 넣어준다
		int mapX = (int)ptr->info.posX;
		int mapY = (int)ptr->info.posY;

		// 시작 점(pos)에서 처음 x면, y면을 만날때 까지의 값
		double sideDistX;
		double sideDistY;

		// x면, y면에서 다음 x면, y면을 만날때 까지의 값
		// 공식유도 직접 계산해볼것!
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		// 나중에 광선의 거리 계산에 쓰일 변수
		double perpWallDist;

		// 광선의 방향을 결정
		int stepX;
		int stepY;

		int hit = 0;
		int side;

		// 방향별로 나누어서 sideDist값을 구해준다.
		// 왼쪽 방향일 경우 👈
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (ptr->info.posX - mapX) * deltaDistX;
		}
		// 오른쪽 방향일 경우 👉
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - ptr->info.posX) * deltaDistX;
		}
		// 위쪽 방향일 경우 🖕
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (ptr->info.posY - mapY) * deltaDistY;
		}
		// 밑에 방향일 경우 👇
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - ptr->info.posY) * deltaDistY;
		}

		// DDA 알고리즘!!!!
		while (!hit)
		{
			// 광선의 기울기가 1보다 작은 경우
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				// 세로 선과 먼저 닿았다
				side = 0;
			}
			// 광선의 기울기가 1보다 큰 경우
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				// 가로 선과 먼저 닿았다
				side = 1;
			}
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
		}
		draw_line(ptr, ptr->info.posX, ptr->info.posY, sideDistX, sideDistY);
	}
}

void	draw_all_line(t_ptr *ptr)
{
	int	i;
	int	j;

	// 세로 선 그리기
	i = 0;
	while (i < mapHeight)
	{
		draw_line(ptr, i * TILE_SIZE, 0, i * TILE_SIZE, screenHeight);
		i++;
	}

	// 가로 선 그리기
	j = 0;
	while (j < mapWidth)
	{
		draw_line(ptr, 0, j * TILE_SIZE, screenWidth, j * TILE_SIZE);
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
			ptr->img.data[(y + i) * screenWidth + x + j] = 0xFFFFFF;
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
	while (i < mapWidth)
	{
		j = 0;
		while (j < mapHeight)
		{
			if (worldMap[i][j] >= 1)
				draw_rect(ptr, i, j);
			j++;
		}
		i++;
	}
}

int		main_loop(t_ptr *ptr)
{
	for(int a = 0; a < screenWidth * screenHeight; a++)
		ptr->img.data[a] = 0;
	draw_all_rect(ptr);
	draw_all_line(ptr);
	calc_ray(ptr);
	int i = ptr->info.posX * TILE_SIZE;
	int j = ptr->info.posY * TILE_SIZE;
	for(int a = 0; a < 5; a++)
	{
		for(int b = 0; b < 5; b++)
			ptr->img.data[(j + a) * screenWidth + (i + b)] = 0xff0000;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img_ptr, 0, 0);
	return (0);
}

int		event_key_press(int keycode, t_ptr *ptr)
{
	if (keycode == KEY_UP)
	{
		if (!worldMap[(int)(ptr->info.posX + ptr->info.dirX * ptr->info.moveSpeed)][(int)(ptr->info.posY)])
			ptr->info.posX += ptr->info.dirX * ptr->info.moveSpeed;
		if (!worldMap[(int)(ptr->info.posX)][(int)(ptr->info.posY + ptr->info.dirY * ptr->info.moveSpeed)])
			ptr->info.posY += ptr->info.dirY * ptr->info.moveSpeed;
	}
	if (keycode == KEY_DOWN)
	{
		if (!worldMap[(int)(ptr->info.posX - ptr->info.dirX * ptr->info.moveSpeed)][(int)(ptr->info.posY)])
			ptr->info.posX -= ptr->info.dirX * ptr->info.moveSpeed;
		if (!worldMap[(int)(ptr->info.posX)][(int)(ptr->info.posY - ptr->info.dirY * ptr->info.moveSpeed)])
			ptr->info.posY -= ptr->info.dirY * ptr->info.moveSpeed;
	}
	if (keycode == KEY_RIGHT)
	{
		double oldDirX = ptr->info.dirX;
		ptr->info.dirX = ptr->info.dirX * cos(-ptr->info.rotSpeed) - ptr->info.dirY * sin(-ptr->info.rotSpeed);
		ptr->info.dirY = oldDirX * sin(-ptr->info.rotSpeed) + ptr->info.dirY * cos(-ptr->info.rotSpeed);
		double oldPlaneX = ptr->info.planeX;
		ptr->info.planeX = ptr->info.planeX * cos(-ptr->info.rotSpeed) - ptr->info.planeY * sin(-ptr->info.rotSpeed);
		ptr->info.planeY = oldPlaneX * sin(-ptr->info.rotSpeed) + ptr->info.planeY * cos(-ptr->info.rotSpeed);
	}
	if (keycode == KEY_LEFT)
	{
		double oldDirX = ptr->info.dirX;
		ptr->info.dirX = ptr->info.dirX * cos(ptr->info.rotSpeed) - ptr->info.dirY * sin(ptr->info.rotSpeed);
		ptr->info.dirY = oldDirX * sin(ptr->info.rotSpeed) + ptr->info.dirY * cos(ptr->info.rotSpeed);
		double oldPlaneX = ptr->info.planeX;
		ptr->info.planeX = ptr->info.planeX * cos(ptr->info.rotSpeed) - ptr->info.planeY * sin(ptr->info.rotSpeed);
		ptr->info.planeY = oldPlaneX * sin(ptr->info.rotSpeed) + ptr->info.planeY * cos(ptr->info.rotSpeed);
	}
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		exit(0);
	}
	return (0);
}

int main(void)
{
	t_ptr	ptr;

	// player의 초기 위치 설정
	ptr.info.posX = 12;
	ptr.info.posY = 5;

	//방향벡터와 plane벡터 설정 (서로 수직이어야함)
	ptr.info.dirX = -1;
	ptr.info.dirY = 0;
	ptr.info.planeX = 0;
	// 슈팅게임의 최적화된 값 (0.66)
	ptr.info.planeY = 0.66;

	ptr.info.moveSpeed = 0.1;
	ptr.info.rotSpeed = 0.05;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, screenWidth, screenHeight, "2d_map");
	ptr.img.img_ptr = mlx_new_image(ptr.mlx, screenWidth, screenHeight);
	ptr.img.data = (int *)mlx_get_data_addr(ptr.img.img_ptr, &ptr.img.bpp, &ptr.img.size_l, &ptr.img.endian);

	mlx_hook(ptr.win, X_EVENT_KEY_PRESS, 0, &event_key_press, &ptr);
	mlx_loop_hook(ptr.mlx, &main_loop, &ptr);
	mlx_loop(ptr.mlx);
}
