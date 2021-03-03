/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:30:40 by skim              #+#    #+#             */
/*   Updated: 2021/03/03 21:13:40 by skim             ###   ########.fr       */
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

typedef struct	s_hid
{
	int			h_x;
	int			h_y;
	int			is_hidden;
	int			h_text;
}				t_hid;

typedef struct	s_life
{
	int			life;
	int			life_bar[100];
}				t_life;

typedef struct	s_fcast
{
	double		ray_dir_x0;
	double		ray_dir_y0;
	double		ray_dir_x1;
	double		ray_dir_y1;
	int			p;
	double		pos_z;
	double		row_distance;
	double		floor_x;
	double		floor_y;
	double		floor_step_x;
	double		floor_step_y;
	int			tex_num;
}				t_fcast;

typedef struct	s_wcast
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			dir_side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
}				t_wcast;

typedef struct	s_scast
{
	int			*sprite_order;
	double		*sprite_distance;
	double		sprite_x;
	double		sprite_y;
	double		inv_dev;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			sprite_height;
	int			draw_start_y;
	int			draw_end_y;
	int			sprite_width;
	int			draw_start_x;
	int			draw_end_x;
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
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
	int			texture[TEXT][TEXTHEIGHT * TEXTWIDTH];
	double		*z_buffer;
}				t_info;

typedef struct	s_key
{
	int			key_up;
	int			key_down;
	int			key_right;
	int			key_left;
	int			key_look_up;
	int			key_look_down;
	int			key_look_left;
	int			key_look_right;
	int			key_sp;
	int			key_q;
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
	int			is_bmp;
	int			up;
	int			jump;
	int			time_stamp;
	t_minfo		minfo;
	t_img		img;
	t_info		info;
	t_key		key;
	t_sprite	*sprite;
	t_bmp		bmp;
	t_life		life;
	t_hid		s_door;
}				t_set;

#endif
