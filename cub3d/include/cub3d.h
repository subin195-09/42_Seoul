/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:17:31 by skim              #+#    #+#             */
/*   Updated: 2020/12/22 17:03:54 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

# define KEY_ESC	53
# define KEY_UP		126
# define key_DOWN	125

// mlx에 등록된 이벤트 번호
#define X_EVENT_KEY_EXIT		17 //Exit program key code

# define ROW	11
# define COL	15

# define TILE_SIZE	32
# define WIDTH		COL * TILE_SIZE
# define HEIGHT		ROW * TILE_SIZE

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

	int		map[ROW][COL];
}				t_ptr;

#endif
