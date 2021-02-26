/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:37:07 by skim              #+#    #+#             */
/*   Updated: 2021/02/26 22:48:50 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	load_image(t_set *set, int tex_num, char *path)
{
	t_img	img;
	int		y;
	int		x;

	img.img_ptr = \
	mlx_xpm_file_to_image(set->mlx, path, &img.width, &img.height);
	img.data = \
	(int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	y = -1;
	while (++y < img.height)
	{
		x = -1;
		while (++x < img.width)
			set->info.texture[tex_num][img.width * y + x] = \
			img.data[img.width * y + x];
	}
	mlx_destroy_image(set->mlx, img.img_ptr);
}

void	make_texture(t_set *set)
{
	load_image(set, EA_TEXT_NUM, set->minfo.ea_path);
	load_image(set, WE_TEXT_NUM, set->minfo.we_path);
	load_image(set, SO_TEXT_NUM, set->minfo.so_path);
	load_image(set, NO_TEXT_NUM, set->minfo.no_path);
	if (set->minfo.floor_text)
		load_image(set, FL_TEXT_NUM, set->minfo.fl_path);
	if (set->minfo.ceiling_text)
		load_image(set, CE_TEXT_NUM, set->minfo.ce_path);
	load_image(set, SP_TEXT_NUM, set->minfo.sp_path);
	load_image(set, SP_TEXT_NUM2, set->minfo.)
}
