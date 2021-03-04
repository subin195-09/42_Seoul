/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 22:33:43 by skim              #+#    #+#             */
/*   Updated: 2021/03/05 01:08:25 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	make_secret_door(t_set *set)
{
	if (set->s_door.h_text < 32 && set->key.key_q)
		set->s_door.h_text++;
	if (set->s_door.h_text == 32 && set->key.key_q)
		set->map[set->s_door.h_x][set->s_door.h_y] = 0;
	if (set->s_door.h_text > 0 && !set->key.key_q)
		set->s_door.h_text--;
	if (set->s_door.h_text == 0 && !set->key.key_q)
		set->map[set->s_door.h_x][set->s_door.h_y] = 9;
}
