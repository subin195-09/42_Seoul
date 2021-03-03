/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:17:31 by skim              #+#    #+#             */
/*   Updated: 2021/03/03 22:34:50 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MAIN_H
# define CUB_MAIN_H

# include "cub_struct.h"
# include "cub_var.h"
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# define _USE_MATH_DEFINES

int		event_key_press(int keycode, t_set *set);
int		event_key_release(int keycode, t_set *set);
void	key_action(t_set *set);
void	key_look_right(t_set *set);
void	key_look_left(t_set *set);
void	cub3d_exit(t_set *set, int sound);

void	floor_cast(t_set *set);
void	wall_cast(t_set *set);
void	sprite_cast(t_set *set);
int		make_re_y(t_set *set, int y);

void	draw_map(t_set *set);

void	save_bmp_img(t_set *set);

int		map_parse(t_set *set, char *map_name);
void	max_min_resolution(t_set *set);
int		map_check(t_set *set, int fd, char **line);
int		get_color(char *line);
int		get_ceiling(t_set *set, char *line);
int		get_floor(t_set *set, char *line);
int		get_map(int fd, char **line, t_set *set);
void	set_pos(t_set *set, char pos);
int		error_msg(char *kind);
int		check_map(t_set *set);

int		main(int ac, char **av);
void	make_texture(t_set *set);

void	play_bgm(void);
void	play_sound_effect(int i);
void	life_bar(t_set *set);
void	animated_sprite(t_set *set);
int		make_darker(int color, int size);
void	make_secret_door(t_set *set);

#endif
