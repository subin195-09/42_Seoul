/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:20:48 by skim              #+#    #+#             */
/*   Updated: 2021/02/22 22:48:37 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	draw_bmp_img(t_set *set)
{
	set->bmp.bf_type1 = 'B';
	set->bmp.bf_type2 = 'M';
	set->bmp.bf_size = (4 * (set->minfo.s_width * set->minfo.s_height)) + 54;
	set->bmp.bf_reser1 = 0;
	set->bmp.bf_reser2 = 0;
	set->bmp.bf_off = 54;
	set->bmp.bi_size = 40;
	set->bmp.bi_width = set->minfo.s_width;
	set->bmp.bi_height = -set->minfo.s_height;
	set->bmp.bi_planes = 1;
	set->bmp.bi_count = 32;
	set->bmp.bi_compre = 0;
	set->bmp.bi_img_size = (4 * (set->minfo.s_width * set->minfo.s_height));
	set->bmp.bi_x_ppm = set->minfo.s_width;
	set->bmp.bi_y_ppm = set->minfo.s_height;
	set->bmp.bi_c_used = 0;
	set->bmp.bi_c_import = 0;
}

void	save_bmp_img(t_set *set)
{
	int		fd;

	fd = open("cub3d_save.bmp", O_RDWR | O_TRUNC | O_CREAT, 0666);
	draw_bmp_img(set);
	write(fd, &set->bmp, 54);
	write(fd, set->img.data, set->bmp.bi_img_size);
	close(fd);
}
