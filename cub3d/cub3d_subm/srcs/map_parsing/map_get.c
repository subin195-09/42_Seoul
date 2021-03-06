/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:05:02 by skim              #+#    #+#             */
/*   Updated: 2021/03/04 15:43:44 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

int		get_color(char *line)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(line);
	while (*line != ',' && *line)
	{
		line++;
		if (!(*line))
			return (error_msg("wrong color") - 1);
	}
	g = ft_atoi(++line);
	while (*line != ',' && *line)
	{
		line++;
		if (!(*line))
			return (error_msg("wrong color") - 1);
	}
	if (!(*line))
		return (error_msg("wrong color") - 1);
	b = ft_atoi(++line);
	return ((r * 256 * 256) + (g * 256) + b);
}

int		get_ceiling(t_set *set, char *line)
{
	int	temp;

	if (ft_isdigit(*line))
	{
		set->minfo.ceiling_text = 0;
		set->minfo.ceiling = get_color(line);
		temp = set->minfo.ceiling;
		if (temp < 0)
			return (0);
	}
	else
	{
		set->minfo.ceiling_text = 1;
		set->minfo.ce_path = ft_strdup(line);
	}
	return (1);
}

int		get_floor(t_set *set, char *line)
{
	int	temp;

	if (ft_isdigit(*line))
	{
		set->minfo.floor_text = 0;
		set->minfo.floor = get_color(line);
		temp = set->minfo.floor;
		if (temp < 0)
			return (0);
	}
	else
	{
		set->minfo.floor_text = 1;
		set->minfo.fl_path = ft_strdup(line);
	}
	return (1);
}
