/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:02:23 by skim              #+#    #+#             */
/*   Updated: 2021/01/28 13:21:55 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub_main.h"
#include "get_next_line.h"

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
