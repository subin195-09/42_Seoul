/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 18:52:40 by skim              #+#    #+#             */
/*   Updated: 2021/03/04 22:21:43 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	play_bgm(void)
{
	system("afplay -v 0.40 sounds/purple_bgm.mp3 &");
}

void	play_sound_effect(int i)
{
	if (i == 1)
		system("afplay -v 0.40 sounds/purple_start.mp3");
	if (i == 2)
		system("afplay -v 0.40 sounds/game_end.wav");
	if (i == 3)
		system("afplay -v 0.40 sounds/collision.wav &");
	if (i == 4)
		system("afplay -v 0.40 sounds/game_over.wav ");
}
