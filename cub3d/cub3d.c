/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:02:23 by skim              #+#    #+#             */
/*   Updated: 2021/02/12 19:43:30 by skim             ###   ########.fr       */
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
	while (++x < set->minfo.s_width)
	{
		t.t_x = (int)(textWidth * (f.floorX - (int)f.floorX)) & (textWidth - 1);
		t.t_y = (int)(textHeight * (f.floorY - (int)f.floorY)) & (textHeight - 1);
		f.floorX += f.floorStepX;
		f.floorY += f.floorStepY;
		t.color = set->info.texture[textCeil][textWidth * t.t_y + t.t_x];
		set->img.data[y * set->minfo.s_width + x] = t.color;
		t.color = set->info.texture[textFloor][textWidth * t.t_y + t.t_x];
		set->img.data[(set->minfo.s_height - y - 1) * set->minfo.s_width + x] = t.color;
	}
}

void	floor_cast(t_set *set)
{
	t_fcast	f;
	int		y;

	y = -1;
	while (++y < set->minfo.s_height)
	{
		f.rayDirX0 = set->info.dirX - set->info.planeX;
		f.rayDirY0 = set->info.dirY - set->info.planeY;
		f.rayDirX1 = set->info.dirX + set->info.planeX;
		f.rayDirY1 = set->info.dirY + set->info.planeY;
		f.p = y - set->minfo.s_height / 2;
		f.posZ = 0.5 * set->minfo.s_height;
		f.rowDistance = f.posZ / f.p;
		f.floorX = set->info.posX + f.rowDistance * f.rayDirX0;
		f.floorY = set->info.posY + f.rowDistance * f.rayDirY0;
		f.floorStepX = f.rowDistance * (f.rayDirX1 - f.rayDirX0) / set->minfo.s_width;
		f.floorStepY = f.rowDistance * (f.rayDirY1 - f.rayDirY0) / set->minfo.s_width;
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
	}
	else
	{
		w->stepX = 1;
		w->sideDistX = (w->mapX + 1.0 - set->info.posX) * w->deltaDistX;
	}
	if (w->rayDirY < 0)
	{
		w->stepY = -1;
		w->sideDistY = (set->info.posY - w->mapY) * w->deltaDistY;
	}
	else
	{
		w->stepY = 1;
		w->sideDistY = (w->mapY + 1.0 - set->info.posY) * w->deltaDistY;
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
			w->dirSide = 0;
		}
		else
		{
			w->sideDistY += w->deltaDistY;
			w->mapY += w->stepY;
			w->dirSide = 1;
		}
		if (set->map[w->mapY][w->mapX] > 0)
			return ;
	}
}

void	wall_text(t_set *set, t_wcast *w, int x)
{
	t_text	t;
	double	wallX;
	double	step;
	int		y;

	if (w->dirSide == 0)
		wallX = set->info.posY + w->perpWallDist * w->rayDirY;
	else
		wallX = set->info.posX + w->perpWallDist * w->rayDirX;
	wallX -= floor(wallX);
	t.t_x = (int)(wallX * (double)textWidth);
	// 서쪽일 경우 반전
	if (w->dirSide == 0 && w->rayDirX < 0)
		t.t_x = textWidth - t.t_x - 1;
	// 남쪽인 경우 반전
	if (w->dirSide == 1 && w->rayDirY > 0)
		t.t_x = textWidth - t.t_x - 1;
	if (w->dirSide == 0)
		t.t_num = w->rayDirX < 0 ? 1 : 0;
	else
		t.t_num = w->rayDirY < 0 ? 3 : 2;
	step = 1.0 * textHeight / w->lineHeight;
	t.t_pos = (w->drawStart - set->minfo.s_height / 2 + w->lineHeight / 2) * step;
	y = w->drawStart - 1;
	while (++y < w->drawEnd)
	{
		t.t_y = (int)t.t_pos & (textHeight - 1);
		t.t_pos += step;
		t.color = set->info.texture[t.t_num][textHeight * t.t_y + t.t_x];
		set->img.data[y * set->minfo.s_width + x] = t.color;
	}
}

void	wall_cast(t_set *set)
{
	t_wcast	w;
	int		x;

	x = -1;
	while (++x < set->minfo.s_width)
	{
		w.cameraX = 2 * x / (1.0 * set->minfo.s_width) - 1;
		w.rayDirX = set->info.dirX + set->info.planeX * w.cameraX;
		w.rayDirY = set->info.dirY + set->info.planeY * w.cameraX;
		w.mapX = (int)set->info.posX;
		w.mapY = (int)set->info.posY;
		w.deltaDistX = fabs(1 / w.rayDirX);
		w.deltaDistY = fabs(1 / w.rayDirY);
		wall_side(set, &w);
		wall_hit(set, &w);
		if (w.dirSide == 0)
			w.perpWallDist = (w.mapX - set->info.posX + (1 - w.stepX) / 2) / w.rayDirX;
		else
			w.perpWallDist = (w.mapY - set->info.posY + (1 - w.stepY) / 2) / w.rayDirY;
		w.lineHeight = (int)(set->minfo.s_height / w.perpWallDist);
		w.drawStart = set->minfo.s_height / 2 - w.lineHeight / 2;
		w.drawStart = w.drawStart < 0 ? 0 : w.drawStart;
		w.drawEnd = set->minfo.s_height / 2 + w.lineHeight / 2;
		w.drawEnd = w.drawEnd >= set->minfo.s_height ? set->minfo.s_height - 1 : w.drawEnd;
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
		if (s->transformY > 0 && x > 0 && x < set->minfo.s_width && s->transformY < set->info.zBuffer[x])
		{
			y = s->drawStartY - 1;
			while (++y < s->drawEndY)
			{
				d = y * 256 - set->minfo.s_height * 128 + s->spriteHeight * 128;
				t.t_y = ((d * textHeight) / s->spriteHeight) / 256;
				t.color = set->info.texture[set->sprite[i].texture][t.t_y * textWidth + t.t_x];
				if ((t.color & 0X00FFFFFF) != 0)
					set->img.data[y * set->minfo.s_width + x] = t.color;
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
		s.spriteScreenX = (int)((set->minfo.s_width / 2) * (1 + s.transformX / s.transformY));
		s.spriteHeight = (int)fabs(set->minfo.s_height / s.transformY);
		s.drawStartY = (set->minfo.s_height / 2) - s.spriteHeight / 2;
		s.drawEndY = (set->minfo.s_height / 2) + s.spriteHeight;
		s.drawEndY = s.drawEndY >= set->minfo.s_height ? set->minfo.s_height - 1 : s.drawEndY;
		s.spriteWidth = (int)fabs(set->minfo.s_height / s.transformY);
		s.drawStartX = s.spriteScreenX - s.spriteWidth / 2;
		s.drawEndX = s.spriteScreenX + s.spriteWidth / 2;
		s.drawStartX = s.drawStartX < 0 ? 0 : s.drawStartX;
		s.drawEndX = s.drawEndX >= set->minfo.s_width ? set->minfo.s_width - 1 : s.drawEndX;
		sprite_text(set, &s, i);
	}
}

// // 2d_map
void	draw_rect(t_set *set, int x, int y)
{
	int i;
	int j;

	x *= map_tile;
	y *= map_tile;
	i = 0;
	while (i < map_tile)
	{
		j = 0;
		while (j < map_tile)
		{
			set->img.data[(y + i) * set->minfo.s_width + x + j] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}

void	draw_all_rect(t_set *set)
{

	int i;
	int j;

	i = 0;
	while (i < set->minfo.m_height)
	{
		j = 0;
		while (j < set->minfo.m_width)
		{
			if (set->map[i][j] > 0)
				draw_rect(set, j, i);
			j++;
		}
		i++;
	}
}

void	draw_map(t_set *set)
{
	int	i;
	int j;
	int	a;
	int	b;

	if (!set->key.key_sp)
		return	;
	draw_all_rect(set);
	i = set->info.posX * map_tile;
	j = set->info.posY * map_tile;
	a = -1;
	while (++a < 2)
	{
		b = -1;
		for(int b = 0; b < 3; b++)
			set->img.data[(j + a) * set->minfo.s_width + (i + b)] = 0xff0000;
	}
}

void	key_event(t_set *set)
{
	if (set->key.key_up)
	{
		if (set->map[(int)(set->info.posX + set->info.dirX * set->info.moveSpeed)][(int)(set->info.posY)] == 0)
			set->info.posX += set->info.dirX * set->info.moveSpeed;
		if (set->map[(int)(set->info.posX)][(int)(set->info.posY + set->info.dirY * set->info.moveSpeed)] == 0)
			set->info.posY += set->info.dirY * set->info.moveSpeed;
	}
	if (set->key.key_down)
	{
		if (set->map[(int)(set->info.posX - set->info.dirX * set->info.moveSpeed)][(int)(set->info.posY)] == 0)
			set->info.posX -= set->info.dirX * set->info.moveSpeed;
		if (set->map[(int)(set->info.posX)][(int)(set->info.posY - set->info.dirY * set->info.moveSpeed)] == 0)
			set->info.posY -= set->info.dirY * set->info.moveSpeed;
	}
	if (set->key.key_left)
	{
		double oldDirX = set->info.dirX;
		set->info.dirX = set->info.dirX * cos(-set->info.rotSpeed) - set->info.dirY * sin(-set->info.rotSpeed);
		set->info.dirY = oldDirX * sin(-set->info.rotSpeed) + set->info.dirY * cos(-set->info.rotSpeed);
		double oldPlaneX = set->info.planeX;
		set->info.planeX = set->info.planeX * cos(-set->info.rotSpeed) - set->info.planeY * sin(-set->info.rotSpeed);
		set->info.planeY = oldPlaneX * sin(-set->info.rotSpeed) + set->info.planeY * cos(-set->info.rotSpeed);
	}
	if (set->key.key_right)
	{
		double oldDirX = set->info.dirX;
		set->info.dirX = set->info.dirX * cos(set->info.rotSpeed) - set->info.dirY * sin(set->info.rotSpeed);
		set->info.dirY = oldDirX * sin(set->info.rotSpeed) + set->info.dirY * cos(set->info.rotSpeed);
		double oldPlaneX = set->info.planeX;
		set->info.planeX = set->info.planeX * cos(set->info.rotSpeed) - set->info.planeY * sin(set->info.rotSpeed);
		set->info.planeY = oldPlaneX * sin(set->info.rotSpeed) + set->info.planeY * cos(set->info.rotSpeed);
	}
}

int		main_loop(t_set *set)
{
	key_event(set);
	floor_cast(set);
	wall_cast(set);
	//sprite_cast(set);
	draw_map(set);
	mlx_put_image_to_window(set->mlx, set->win, set->img.img_ptr, 0, 0);
	return (0);
}

int		event_key_press(int keycode, t_set *set)
{
	if (keycode == KEY_UP)
		set->key.key_up = 1;
	if (keycode == KEY_DOWN)
		set->key.key_down = 1;
	if (keycode == KEY_RIGHT)
		set->key.key_right = 1;
	if (keycode == KEY_LEFT)
		set->key.key_left = 1;
	if (keycode == KEY_SP)
		set->key.key_sp = set->key.key_sp == 0 ? 1 : 0;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(set->mlx, set->win);
		exit(0);
	}
	return (0);
}

int		event_key_release(int keycode, t_set *set)
{
	if (keycode == KEY_UP)
		set->key.key_up = 0;
	if (keycode == KEY_DOWN)
		set->key.key_down = 0;
	if (keycode == KEY_RIGHT)
		set->key.key_right = 0;
	if (keycode == KEY_LEFT)
		set->key.key_left = 0;
	return (0);
}

void	load_image(t_set *set, int texNum, char *path)
{
	t_img	img;

	img.img_ptr = mlx_xpm_file_to_image(set->mlx, path, &img.width, &img.height);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	for(int y = 0; y < img.height; y++)
	{
		for(int x = 0; x < img.width; x++)
			set->info.texture[texNum][img.width * y + x] = img.data[img.width * y + x];
	}
	mlx_destroy_image(set->mlx, img.img_ptr);
}

void	make_texture(t_set *set)
{
	load_image(set, 0, set->minfo.ea_path);
	load_image(set, 1, set->minfo.we_path);
	load_image(set, 2, set->minfo.so_path);
	load_image(set, 3, set->minfo.no_path);

	// 천장, 바닥 texture
	load_image(set, 4, "img/wood.xpm");
	load_image(set, 5, "img/wood.xpm");

	// sprite texture
	load_image(set, 6, "img/barrel.xpm");
}

// map parsing
int		check_str(char *chk, char **line, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (chk[i] != **line)
			return (0);
		(*line)++;
	}
	return (1);
}

int		get_resolution(int fd, char **line, t_set *set)
{
	get_next_line(fd, line);
	if (!check_str("R ", line, 2))
		return (0);
	if ((set->minfo.s_width = ft_atoi(*line)) < 0)
		return (0);
	(*line) += count_num(set->minfo.s_width);
	if (!check_str(" ", line, 1))
		return (0);
	if ((set->minfo.s_height = ft_atoi(*line)) < 0)
		return (0);
	return (1);
}

int		get_path(int fd, char **line, t_set *set)
{
	get_next_line(fd, line);
	if (!check_str("NO ", line, 3))
		return (0);
	set->minfo.no_path = ft_strdup(*line);
	get_next_line(fd, line);
	if (!check_str("SO ", line, 3))
		return (0);
	set->minfo.so_path = ft_strdup(*line);
	get_next_line(fd, line);
	if (!check_str("WE ", line, 3))
		return (0);
	set->minfo.we_path = ft_strdup(*line);
	get_next_line(fd, line);
	if (!check_str("EA ", line, 3))
		return (0);
	set->minfo.ea_path = ft_strdup(*line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	if (!check_str("S ", line, 2))
		return (0);
	set->minfo.sp_path = ft_strdup(*line);
	return (1);
}

int		get_color(char *line)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(line);
	while (*line != ',' && *line)
	{
		line++;
		if (!(*line))
			return (-1);
	}
	g = ft_atoi(++line);
	while (*line != ',' && *line)
	{
		line++;
		if (!(*line))
			return (0);
	}
	b = ft_atoi(++line);
	return ((r * 256 * 256) + (g * 256) + b);
}

int		get_fc(int fd, char **line,  t_set *set)
{
	get_next_line(fd, line);
	if (!check_str("F ", line, 2))
		return (0);
	if (!ft_isdigit(**line))
		return (0);
	if ((set->minfo.floor = get_color(*line)) < 0)
		return (0);
	get_next_line(fd, line);
	if (!check_str("C ", line, 2))
		return (0);
	if (!ft_isdigit(**line))
		return (0);
	if ((set->minfo.ceiling = get_color(*line)) < 0)
		return (0);
	return (1);
}

void	set_pos(t_set *set, char pos)
{
	if (pos == 'E')
		{
			set->info.dirX = 1;
			set->info.dirY = 0;
			set->info.planeX = 0;
			set->info.planeY = 0.66;

		}
		if (pos == 'W')
		{
			set->info.dirX = -1;
			set->info.dirY = 0;
			set->info.planeX = 0;
			set->info.planeY = 0.66;
		}
		if (pos == 'S')
		{
			set->info.dirX = 0;
			set->info.dirY = 1;
			set->info.planeX = 0.66;
			set->info.planeY = 0;
		}
		if (pos == 'N')
		{
			set->info.dirX = 0;
			set->info.dirY = -1;
			set->info.planeX = 0.66;
			set->info.planeY = 0;
		}
}

void	change_map(t_set *set, int **map, char *temp_map, int i)
{
	int		j;

	j = -1;
	while (++j < set->minfo.m_width)
		(*map)[j] = -1;
	j = -1;
	while (temp_map[++j] != 0)
	{
		if (temp_map[j] == 'E' || temp_map[j] == 'W' || temp_map[j] == 'S' || temp_map[j] == 'N')
		{
			set_pos(set, temp_map[j]);
			set->info.posX = i;
			set->info.posY = j;
			temp_map[j] = '0';
		}
		(*map)[j] = temp_map[j] == ' ' ? -1 : temp_map[j] - '0';
		if ((*map)[j] == 2)
			set->minfo.num_sprite++;
	}
}

void	get_map_size(t_set *set, int fd, int fd_2, char **line)
{
	int		temp_size;

	get_next_line(fd, line);
	set->minfo.m_height = 0;
	set->minfo.m_width = 0;
	while ((get_next_line(fd, line)) > 0)
	{
		temp_size = ft_strlen(*line);
		if (set->minfo.m_width < temp_size)
			set->minfo.m_width = temp_size;
		set->minfo.m_height++;
		write(fd_2, *line, temp_size);
		write(fd_2, "\n", 1);
	}
}

int		get_map(int fd, char **line, t_set *set)
{
	int		i;
	int		fd_2;
	char	*temp_map;

	i = -1;
	fd_2 = open("tmp_map", O_CREAT | O_RDWR, 0777);
	get_map_size(set, fd, fd_2, line);
	set->minfo.num_sprite = 0;
	set->map = (int **)malloc(sizeof(int *) * set->minfo.m_height);
	while (++i < set->minfo.m_height)
		set->map[i] = (int *)malloc(sizeof(int) * set->minfo.m_width);
	close(fd);
	close(fd_2);
	fd_2 = open("tmp_map", O_RDONLY);
	i = 0;
	while ((get_next_line(fd_2, &temp_map) > 0))
	{
		change_map(set, &(set->map[i]), temp_map, i);
		i++;
		free(temp_map);
	}
	free(temp_map);
	close(fd_2);
	return (1);
}

void	init_ck_map(t_set *set, int ***ck_map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < set->minfo.m_height + 2)
	{
		j = -1;
		while (++j < set->minfo.m_width + 2)
		{
			if (i * j == 0 || i == set->minfo.m_height + 1 || j == set->minfo.m_width + 1)
				(*ck_map)[i][j] = -1;
			else
				(*ck_map)[i][j] = set->map[i - 1][j - 1];
		}
	}
}

int		is_road(t_set *set, int ***ck_map, int x, int y)
{
	int		dir_x[4];
	int		dir_y[4];
	int		i;

	dir_x[0] = -1;
	dir_x[1] = 0;
	dir_x[2] = 1;
	dir_x[3] = 0;
	i = -1;
	while (++i < 4)
		dir_y[3 - i] = dir_x[i];
	i = -1;
	if ((*ck_map)[x][y] == 1 || (*ck_map)[x][y] == -2)
		return (1);
	if ((*ck_map)[x][y] == -1)
		return (0);
	(*ck_map)[x][y] = -2;
	i = -1;
	while (++i < 4)
		if (!is_road(set, ck_map, x + dir_x[i], y + dir_y[i]))
			return (0);
	return (1);
}

int		is_map(t_set *set, int **ck_map)
{
	int		is_zero;
	int		i;
	int		j;

	is_zero = 0;
	i = -1;
	while (++i < set->minfo.m_height)
	{
		j = -1;
		while (++j < set->minfo.m_width)
		{
			if (ck_map[i][j] == 0)
			{
				is_zero = 1;
				if (is_road(set, &ck_map, i, j) == 0)
					return (0);
			}
		}
	}
	if (!is_zero)
		return (0);
	else
		return (1);
}

int		check_map(t_set *set)
{
	int		**ck_map;
	int		i;

	ck_map = (int **)malloc(sizeof(int *) * (set->minfo.m_height + 2));
	i = -1;
	while (++i < set->minfo.m_width + 2)
		ck_map[i] = (int *)malloc(sizeof(int) * (set->minfo.m_width + 2));
	init_ck_map(set, &ck_map);
	return (is_map(set, ck_map));
}

void	map_parse(t_set *set)
{
	char	*line;
	int		fd = open("map.cub", O_RDONLY);

	if (!get_resolution(fd, &line, set))
		printf("Error\n");
	if (!get_path(fd, &line, set))
		printf("Error\n");
	// texture로 주어지는 상황 2개 모두 고려할 것인가?
	if (!get_fc(fd, &line, set))
		printf("Error\n");
	get_map(fd, &line, set);
	if (!check_map(set))
		printf("Error\n");
}

int		main(void)
{
	t_set	set;

	map_parse(&set);
	// map 파싱에 추가하기!!!
	for(int i = 0 ; i < set.minfo.m_height; i++)
	{
		for(int j = 0; j < set.minfo.m_width; j++)
			printf("%3d", set.map[i][j]);
		printf("\n");
	}

	set.info.moveSpeed = 0.05;
	set.info.rotSpeed = 0.03;
	set.key.key_up = 0;
	set.key.key_down = 0;
	set.key.key_right = 0;
	set.key.key_left = 0;
	set.key.key_sp = 0;

	if (!(set.info.zBuffer = malloc(sizeof(double) * set.minfo.s_width)))
		return (-1);
	set.mlx = mlx_init();
	make_texture(&set);
	set.win = mlx_new_window(set.mlx, set.minfo.s_width, set.minfo.s_height, "cub3d");
	set.img.img_ptr = mlx_new_image(set.mlx, set.minfo.s_width, set.minfo.s_height);
	set.img.data = (int *)mlx_get_data_addr(set.img.img_ptr, &set.img.bpp, &set.img.size_l, &set.img.endian);
	mlx_hook(set.win, X_EVENT_KEY_PRESS, 0, &event_key_press, &set);
	mlx_hook(set.win, X_EVENT_KEY_RELEASE, 0, &event_key_release, &set);
	mlx_loop_hook(set.mlx, &main_loop, &set);
	mlx_loop(set.mlx);
}
