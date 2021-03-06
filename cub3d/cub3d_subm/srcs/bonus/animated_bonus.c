/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:22:22 by skim              #+#    #+#             */
/*   Updated: 2021/03/05 16:52:36 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"
#include <time.h>

void	animated_sprite(t_set *set)
{
	time_t	now;

	time(&now);
	if (now % 2)
		set->time_stamp = 3;
	else
		set->time_stamp = 0;
}
