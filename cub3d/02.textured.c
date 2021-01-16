/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textured.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:21:56 by skim              #+#    #+#             */
/*   Updated: 2021/01/11 16:35:16 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fire.h"
#include "mlx.h"

int worldMap[mapWidth][mapHeight]=
{
  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
  {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
  {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};

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

		// 광선의 시작점 + 벽까지의 이동거리 계산 => 실제 거리가 아닌 직선 거리를 구해야함
		// 어안렌즈 효과 때문에
		if (side == 0)
			perpWallDist = (mapX - ptr->info.posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY -  ptr->info.posY + (1 - stepY) / 2) / rayDirY;

		//벽의 높이 결정
		int lineHeight = (int)(screenHeight / perpWallDist);
		//벽을 그릴 시작점과 끝점
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		drawStart = drawStart < 0 ? 0 : drawStart;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		drawEnd = drawEnd >= screenHeight ? screenHeight - 1 : drawEnd;

		//texture 입히기

		// 부딪히는 벽의 위치를 저장
		// -1을 빼는 이유를 알아둘 것! ***
		int textNum = worldMap[mapX][mapY] - 1;

		// 부딪히는 곳의 x좌표 이다.
		// 주의 : side가 0일 경우 y좌표가 된다.
		double wallX;
		if (!side)
			wallX = ptr->info.posY + perpWallDist * rayDirY;
		else
			wallX = ptr->info.posX + perpWallDist * rayDirX;
		// texture 상에서 상대적인 위치를 알기위해 int 부분을 날리고 소수 부분만 가진다.
		wallX -= floor(wallX);

		// texture맵 상에서의 x좌표
		int texX = (int)(wallX * (double)textWidth);
		// 이 부분을 좀 더 알아볼 것
		if (side == 0 && rayDirX > 0)
			texX = textWidth - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = textWidth - texX - 1;

		// texture맵 상에서 한 픽셀이 상대적으로 얼마만큼인가
		double step = 1.0 * textHeight / lineHeight;
		// ?
		double texPos = (drawStart - screenHeight / 2 + lineHeight / 2) * step;
		for(int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & (textHeight - 1);
			texPos += step;
			int color = ptr->info.texture[textNum][textHeight * texY + texX];
			if (side == 1)
				color /= 2;
			ptr->img.data[y * screenWidth + x] = color;
		}
	}
}

void	window_init(t_ptr *ptr)
{
	for(int i = 0; i <= screenHeight; i++)
		for(int j = 0; j <= screenWidth; j++)
			ptr->img.data[i * screenWidth + j] = 0;
}

int		main_loop(t_ptr *ptr)
{
	window_init(ptr);
	calc_ray(ptr);
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

void	make_texture(t_ptr *ptr)
{
	for(int x = 0; x < textWidth; x++)
	{
		for(int y = 0; y < textHeight; y++)
		{
			int xorColor = (x * 256 / textWidth) ^ (y * 256 / textHeight);
			int yColor = y * 256 / textHeight;
			int xyColor = y * 128 / textHeight + x * 128 / textWidth;

			ptr->info.texture[0][textWidth * y + x] = 65536 * 254 * (x != y && x != textWidth - y); // flat red texture with black cross
			ptr->info.texture[1][textWidth * y + x] = xyColor + 256 * xyColor + 65536 * xyColor; // sloped greyscale
			ptr->info.texture[2][textWidth * y + x] = 256 * xyColor + 65536 * xyColor; // sloped yellow gradient
			ptr->info.texture[3][textWidth * y + x] = xorColor + 256 * xorColor + 65536 * xorColor; // xor greyscale
			ptr->info.texture[4][textWidth * y + x] = 256 * xorColor; // xor green
			ptr->info.texture[5][textWidth * y + x] = 65536 * 192 * (x % 16  && y % 16); //red bricks
			ptr->info.texture[6][textWidth * y + x] = 65536 * yColor; // red gradient
			ptr->info.texture[7][textWidth * y + x] = 128 + 256 * 128 + 65536 * 128; // flat grey texture
		}
	}
}

int main(void)
{
	t_ptr	ptr;

	// player의 초기 위치 설정
	ptr.info.posX = 22.0;
	ptr.info.posY = 11.5;

	//방향벡터와 plane벡터 설정 (서로 수직이어야함)
	ptr.info.dirX = -1;
	ptr.info.dirY = 0;
	ptr.info.planeX = 0;
	// 슈팅게임의 최적화된 값 (0.66)
	ptr.info.planeY = 0.66;

	ptr.info.moveSpeed = 0.1;
	ptr.info.rotSpeed = 0.05;

	make_texture(&ptr);

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, screenWidth, screenHeight, "raycaster");
	ptr.img.img_ptr = mlx_new_image(ptr.mlx, screenWidth, screenHeight);
	ptr.img.data = (int *)mlx_get_data_addr(ptr.img.img_ptr, &ptr.img.bpp, &ptr.img.size_l, &ptr.img.endian);

	mlx_hook(ptr.win, X_EVENT_KEY_PRESS, 0, &event_key_press, &ptr);
	mlx_loop_hook(ptr.mlx, &main_loop, &ptr);
	mlx_loop(ptr.mlx);
}
