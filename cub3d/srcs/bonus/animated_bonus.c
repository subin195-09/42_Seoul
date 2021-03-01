/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:22:22 by skim              #+#    #+#             */
/*   Updated: 2021/03/01 16:39:52 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"
#include <time.h>

void	animated_sprite(t_set *set)
{
	time_t	now;
	int		now_i;

	time(&now);
	now_i = now;
	if (now_i % 2)
		set->time_stamp = 2;
	else
		set->time_stamp = 0;
}
