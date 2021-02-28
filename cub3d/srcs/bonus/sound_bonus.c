/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 18:52:40 by skim              #+#    #+#             */
/*   Updated: 2021/02/28 20:13:27 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	play_bgm(void)
{
	system("afplay -v 0.40 sounds/pack_bgm.mp3 &");
}

void	play_sound_effect(int i)
{
	if (i == 1)
		system("afplay -v 0.40 sounds/game_start.wav");
	if (i == 2)
		system("afplay -v 0.40 sounds/game_end.wav");
}
