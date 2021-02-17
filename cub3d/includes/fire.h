/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:35:25 by skim              #+#    #+#             */
/*   Updated: 2021/02/17 22:43:19 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_H
# define FIRE_H

#define mapWidth		15
#define mapHeight		10
#define TILE_SIZE		32
#define screenWidth		(640)
#define screenHeight	(480)

#define	map_tile		5
#define map_size		(mapWidth * map_tile)

// textured에서 사용
#define text			11
#define textWidth		64
#define textHeight		64

// sprite에서 사용
#define numSprite		19

# define KEY_ESC	53
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_SP		49

# define RGB_Red	0xff0000;
# define RGB_Green	0x00ff00;
# define RGB_Blue	0x0000ff;
# define RGB_White	0xffffff;
# define RGB_Yellow	0xffff00;

// mlx에 등록된 이벤트 번호
#define X_EVENT_KEY_EXIT		17 //Exit program key code
#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_RELEASE		3

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct	s_sprite
{
	double	x;
	double	y;
	int		texture;
}				t_sprite;


typedef struct	s_key
{
	int		key_up;
	int		key_down;
	int		key_right;
	int		key_left;
	int		key_sp;
}				t_key;

typedef struct  s_info
{
	// player의 위치
	double	posX;
	double	posY;
	// 방향벡터 (plane과 수직이 되어야함)
	double	dirX;
	double	dirY;
	// plane벡터
	double	planeX;
	double	planeY;
	double	moveSpeed;
	double	rotSpeed;
	// textured 에서 사용
	int		buf[screenWidth][screenHeight];
	int		texture[text][textHeight * textWidth];

	// sprite 에서 사용
	double	zBuffer[screenWidth];
	t_key	key;
}				t_info;

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;

	int		height;
	int		width;
}				t_img;

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_info	info;
}				t_ptr;

#endif
