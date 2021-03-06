/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darker_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:33:42 by skim              #+#    #+#             */
/*   Updated: 2021/03/03 19:11:25 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

int		make_darker(int color, int size)
{
	int	r;
	int	g;
	int	b;

	b = color & 0X0000FF;
	g = (color >> 8) & 0X0000FF;
	r = (color >> 16) & 0X0000FF;
	size = size < 0 ? 0 : size;
	b -= size;
	g -= size;
	r -= size;
	b = b > 0 ? b : 0;
	g = g > 0 ? g : 0;
	r = r > 0 ? r : 0;
	return ((r * 256 * 256) + (g * 256) + b);
}
