/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:17:31 by skim              #+#    #+#             */
/*   Updated: 2021/02/22 23:40:58 by skim             ###   ########.fr       */
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

int		event_key_press(int keycode, t_set *set);
int		event_key_release(int keycode, t_set *set);
void	key_action(t_set *set);

void	floor_cast(t_set *set);
void	wall_cast(t_set *set);
void	sprite_cast(t_set *set);

void	draw_map(t_set *set);

void	save_bmp_img(t_set *set);

void	map_parse(t_set *set, char *map_name);
int		get_color(char *line);
int		get_ceiling(t_set *set, char *line);
int		get_floor(t_set *set, int kind, char *line);
int		get_map(int fd, char **line, t_set *set);
void	set_pos(t_set *set, char pos);
int		error_msg(char *kind);
int		check_map(t_set *set);

#endif
