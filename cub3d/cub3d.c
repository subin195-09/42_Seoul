/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:02:23 by skim              #+#    #+#             */
/*   Updated: 2021/01/30 15:44:27 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub_main.h"
#include "get_next_line.h"

// floor cast
void	floor_text(t_set *set, t_fcast f, int y)
{
	t_text	t;
	int		x;

	x = -1;
	while (++x < screenWidth)
	{
		t.t_x = (int)(textWidth * (f.floorX - (int)f.floorX)) & (textWidth - 1);
		t.t_y = (int)(textHeight * (f.floorY - (int)f.floorY)) & (textHeight - 1);
		f.floorX += f.floorStepX;
		f.floorY += f.floorStepY;
		t.color = set->info.texture[textFloor][textWidth * t.t_y + t.t_x];
		t.color = (t.color >> 1) & 8355711;
		set->img.data[y * screenWidth + x] = t.color;
		t.color = set->info.texture[textCeil][textWidth * t.t_y + t.t_x];
		t.color = (t.color >> 1) & 8355711;
		set->img.data[(screenHeight - y - 1) * screenWidth + x] = t.color;
	}
}

void	floor_cast(t_set *set)
{
	t_fcast	f;
	int		y;

	y = -1;
	while (++y < screenHeight)
	{
		f.rayDirX0 = set->info.dirX - set->info.planeX;
		f.rayDirY0 = set->info.dirY - set->info.planeY;
		f.rayDirX1 = set->info.dirX + set->info.planeX;
		f.rayDirY1 = set->info.dirY + set->info.planeY;
		f.p = y - screenHeight / 2;
		f.posZ = 0.5 * screenHeight;
		f.rowDistance = f.posZ / f.p;
		f.floorX = set->info.posX + f.rowDistance * f.rayDirX0;
		f.floorY = set->info.posY + f.rowDistance * f.rayDirY0;
		f.floorStepX = f.rowDistance * (f.rayDirX1 - f.rayDirX0) / screenWidth;
		f.floorStepY = f.rowDistance * (f.rayDirY1 - f.rayDirY0) / screenWidth;
		floor_text(set, f, y);
	}
}

// wall cast
void	wall_side(t_set *set, t_wcast *w)
{
	if (w->rayDirX < 0)
	{
		w->stepX = -1;
		w->sideDistX = (set->info.posX - w->mapX) * w->deltaDistX;
		w->dirSide = 1;
	}
	else
	{
		w->stepX = 1;
		w->sideDistX = (w->mapX + 1.0 - set->info.posX) * w->deltaDistX;
		w->dirSide = 2;
	}
	if (w->rayDirY < 0)
	{
		w->stepY = -1;
		w->sideDistY = (set->info.posY - w->mapY) * w->deltaDistY;
		w->dirSide *= 1;
	}
	else
	{
		w->stepY = 1;
		w->sideDistY = (w->mapY + 1.0 - set->info.posY) * w->deltaDistY;
		w->dirSide *= -1;
	}


}

void	wall_hit(t_set *set, t_wcast *w)
{
	while (1)
	{
		if (w->sideDistX < w->sideDistY)
		{
			w->sideDistX += w->deltaDistX;
			w->mapX += w->stepX;
			w->dirSide = w->dirSide > 0 ? 3 : 4;
		}
		else
		{
			w->sideDistY += w->deltaDistY;
			w->mapY += w->stepY;
			w->dirSide = abs(w->dirSide) == 1 ? 2 : 1;
		}
		if (set->map[w->mapX][w->mapY] > 0)
			return ;
	}
}

void	wall_text(t_set *set, t_wcast *w, int x)
{
	t_text	t;
	double	wallX;
	double	step;
	int		y;

	if (w->dirSide > 2)
		wallX = set->info.posY + w->perpWallDist * w->rayDirY;
	else
		wallX = set->info.posX + w->perpWallDist * w->rayDirX;
	wallX -= (int)wallX;
	t.t_x = (int)(wallX * (double)textWidth);
	if (w->dirSide > 2 && w->rayDirX > 0)
		t.t_x - textWidth - t.t_x - 1;
	if (w->dirSide <= 2 && w->rayDirY < 0)
		t.t_x = textWidth - t.t_x - 1;
	step = 1.0 * textHeight / w->lineHeight;
	t.t_pos = (w->drawStart - screenHeight / 2 + w->lineHeight / 2) * step;
	y = w->drawStart - 1;
	while (++y < w->drawEnd)
	{
		t.t_y = (int)t.t_pos & (textHeight - 1);
		t.t_pos += step;
		t.color = set->info.texture[w->dirSide][textHeight * t.t_y + t.t_x];
		set->img.data[y * screenWidth + x] = t.color;
	}
}

void	wall_cast(t_set *set)
{
	t_wcast	w;
	int		x;

	x = -1;
	while (++x < screenWidth)
	{
		w.cameraX = 2 * x / (1.0 * screenWidth) - 1;
		w.rayDirX = set->info.dirX + set->info.planeX * w.cameraX;
		w.rayDirY = set->info.dirY + set->info.planeY * w.cameraX;
		w.mapX = (int)set->info.posX;
		w.mapY = (int)set->info.posY;
		w.deltaDistX = fabs(1 / w.rayDirX);
		w.deltaDistY = fabs(1 / w.rayDirY);
		wall_side(set, &w);
		wall_hit(set, &w);
		if (w.dirSide > 2)
			w.perpWallDist = (w.mapX - set->info.posX + (1 - w.stepX) / 2) / w.rayDirY;
		else
			w.perpWallDist = (w.mapY - set->info.posY + (1 - w.stepY) / 2) / w.rayDirY;
		w.lineHeight = (int)(screenHeight / w.perpWallDist);
		w.drawStart = screenHeight / 2 - w.lineHeight / 2;
		w.drawStart = w.drawStart < 0 ? 0 : w.drawStart;
		w.drawEnd = screenHeight / 2 + w.lineHeight / 2;
		w.drawEnd = w.drawEnd >= screenHeight ? screenHeight - 1 : w.drawEnd;
		wall_text(set, &w, x);
		set->info.zBuffer[x] = w.perpWallDist;
	}
}

// sprite cast
void	sprite_sort(t_scast *s)
{
	int		i;
	int		j;
	int		tmp;
	double	dis_tmp;
	double	max;

	max = 0;
	i = -1;
	while (++i < numSprite - 1)
	{
		max = s->spriteDistance[i];
		j = i;
		while (++j < numSprite)
		{
			if (max <= s->spriteDistance[j])
			{
				max = s->spriteDistance[j];
				tmp = s->spriteOrder[i];
				s->spriteOrder[i] = s->spriteOrder[j];
				s->spriteOrder[j] = tmp;
				dis_tmp = s->spriteDistance[i];
				s->spriteDistance[i] = s->spriteDistance[j];
				s->spriteDistance[j] = dis_tmp;
			}
		}
	}
}

void	sprite_text(t_set *set, t_scast *s, int i)
{
	int		x;
	int		y;
	int		d;
	t_text	t;

	x = s->drawStartX - 1;
	while (++x < s->drawEndX)
	{
		t.t_x = (int)((256 * (x - (-s->spriteWidth / 2 + s->spriteScreenX)) * textWidth / s->spriteWidth) / 256);
		if (s->transformY > 0 && x > 0 && x < screenWidth && s->transformY < set->info.zBuffer[x])
		{
			y = s->drawStartY - 1;
			while (++y < s->drawEndY)
			{
				d = y * 256 - screenHeight * 128 + s->spriteHeight * 128;
				t.t_y = ((d * textHeight) / s->spriteHeight) / 256;
				t.color = set->info.texture[set->sprite[i].texture][t.t_y * textWidth + t.t_x];
				if ((t.color & 0X00FFFFFF) != 0)
					set->img.data[y * screenWidth + x] = t.color;
			}
		}
	}
}

void	sprite_cast(t_set *set)
{
	t_scast	s;
	int		i;

	i = -1;
	while (++i < numSprite)
	{
		s.spriteOrder[i] = i;
		s.spriteDistance[i] = ((set->info.posX - set->sprite[i].x) * (set->info.posX - set->sprite[i].x)) + ((set->info.posY - set->sprite[i].y) * (set->info.posY - set->sprite[i].y));
	}
	sprite_sort(&s);
	i = -1;
	while (++i < numSprite)
	{
		s.spriteX = set->sprite[s.spriteOrder[i]].x - set->info.posX;
		s.spriteY = set->sprite[s.spriteOrder[i]].y - set->info.posY;
		s.invDev = 1.0 / (set->info.planeX * set->info.dirY - set->info.dirX * set->info.planeY);
		s.transformX = s.invDev * (set->info.dirY * s.spriteX - set->info.dirX * s.spriteY);
		s.transformY = s.invDev * (-set->info.planeY * s.spriteX + set->info.planeX * s.spriteY);
		s.spriteScreenX = (int)((screenWidth / 2) * (1 + s.transformX / s.transformY));
		s.spriteHeight = (int)fabs(screenHeight / s.transformY);
		s.drawStartY = (screenHeight / 2) - s.spriteHeight / 2;
		s.drawEndY = (screenHeight / 2) + s.spriteHeight;
		s.drawEndY = s.drawEndY >= screenHeight ? screenHeight - 1 : s.drawEndY;
		s.spriteWidth = (int)fabs(screenHeight / s.transformY);
		s.drawStartX = s.spriteScreenX - s.spriteWidth / 2;
		s.drawEndX = s.spriteScreenX + s.spriteWidth / 2;
		s.drawStartX = s.drawStartX < 0 ? 0 : s.drawStartX;
		s.drawEndX = s.drawEndX >= screenWidth ? screenWidth - 1 : s.drawEndX;
		sprite_text(set, &s, i);
	}
}

// 2d_map
void	draw_map(t_set *set)
{
	
}
