/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:30:40 by skim              #+#    #+#             */
/*   Updated: 2021/02/20 00:11:30 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

# include "cub_var.h"

# pragma pack(push, 1)

typedef struct	s_bmp
{
	unsigned char	bf_type1;
	unsigned char	bf_type2;
	unsigned int	bf_size;
	unsigned short	bf_reser1;
	unsigned short	bf_reser2;
	unsigned int	bf_off;
	unsigned int	bi_size;
	int				bi_width;
	int				bi_height;
	unsigned short	bi_planes;
	unsigned short	bi_count;
	unsigned int	bi_compre;
	unsigned int	bi_img_size;
	int				bi_x_ppm;
	int				bi_y_ppm;
	unsigned int	bi_c_used;
	unsigned int	bi_c_import;
}				t_bmp;

# pragma pack(pop)

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
	int			*spriteOrder;
	double		*spriteDistance;
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

typedef struct	s_info
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		moveSpeed;
	double		rotSpeed;
	int			texture[TEXT][textHeight * textWidth];
	double		*zBuffer;
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
	int			floor_text;
	int			ceiling_text;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*sp_path;
	char		*fl_path;
	char		*ce_path;
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
	t_sprite	*sprite;
	t_bmp		bmp;
}				t_set;

#endif
