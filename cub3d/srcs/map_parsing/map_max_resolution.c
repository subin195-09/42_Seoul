/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_max_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:55:12 by skim              #+#    #+#             */
/*   Updated: 2021/02/26 18:42:26 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"
#include "../../mlx_beta/mlx.h"

void	max_min_resolution(t_set *set)
{
	mlx_get_screen_size(set->mlx, &set->minfo.w_max, &set->minfo.h_max);
	set->minfo.s_width = set->minfo.s_width > set->minfo.w_max \
	? set->minfo.w_max : set->minfo.s_width;
	set->minfo.s_height = set->minfo.s_height > set->minfo.h_max \
	? set->minfo.h_max : set->minfo.s_height;
	set->minfo.s_width = set->minfo.s_width < 600 \
	? 600 : set->minfo.s_width;
	set->minfo.s_height = set->minfo.s_height < 500 \
	? 500 : set->minfo.s_height;
}
