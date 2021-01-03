/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:35:25 by skim              #+#    #+#             */
/*   Updated: 2021/01/03 18:47:14 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_H
# define FIRE_H

#define mapWidth		24
#define mapHeight		24
#define screenWidth		640
#define screenHeight	480

# define KEY_ESC	53
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124

// mlx에 등록된 이벤트 번호
#define X_EVENT_KEY_EXIT		17 //Exit program key code
#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_RELEASE		3

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

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
	double	time;
	double	oldTime;
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
}				t_ptr;

#endif
