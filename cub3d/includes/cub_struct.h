/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:30:40 by skim              #+#    #+#             */
/*   Updated: 2021/02/02 17:42:04 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

#include "cub_var.h"

typedef struct	s_fcast
{
	double		rayDirX0;
	double		rayDirY0;
	double		rayDirX1;
	double		rayDirY1;
	int			p;
	double		posZ;
	double		rowDistance;
	double		floorX;
	double		floorY;
	double		floorStepX;
	double		floorStepY;
	int			texNum;
}				t_fcast;

typedef struct	s_wcast
{
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			dirSide;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	double		wallX;
}				t_wcast;

typedef struct	s_scast
{
	int			spriteOrder[numSprite];
	double		spriteDistance[numSprite];
	double		spriteX;
	double		spriteY;
	double		invDev;
	double		transformX;
	double		transformY;
	int			spriteScreenX;
	int			spriteHeight;
	int			drawStartY;
	int			drawEndY;
	int			spriteWidth;
	int			drawStartX;
	int			drawEndX;
}				t_scast;

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			texture;
}				t_sprite;

typedef struct	s_text
{
	double		t_pos;
	int			t_x;
	int			t_y;
	int			t_num;
	int			color;
}				t_text;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef struct  s_info
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		moveSpeed;
	double		rotSpeed;
	int			buf[screenWidth][screenHeight];
	int			texture[text][textHeight * textWidth];
	double		zBuffer[screenWidth];
}				t_info;

typedef struct	s_key
{
	int			key_up;
	int			key_down;
	int			key_right;
	int			key_left;
	int			key_sp;
}				t_key;

typedef struct	s_minfo
{
	int			s_width;
	int			s_height;
	int			m_width;
	int			m_height;
	int			num_sprite;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*sp_path;
	int			floor;
	int			ceiling;
}				t_minfo;

typedef struct	s_set
{
	void		*mlx;
	void		*win;
	int			**map;
	t_minfo		minfo;
	t_img		img;
	t_info		info;
	t_key		key;
	t_sprite	sprite[numSprite];
}				t_set;

#endif

