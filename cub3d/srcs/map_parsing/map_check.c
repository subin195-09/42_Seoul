/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 22:01:45 by skim              #+#    #+#             */
/*   Updated: 2021/03/05 18:49:17 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

int		flag_check(int start, int kind, unsigned char *flag, char *line)
{
	if (((*flag) >> kind & 1) == 1)
		return (-1);
	while (line[start] == ' ')
		start++;
	(*flag) |= 1 << kind;
	return (start);
}

int		map_side_check(t_set *set, char *line, unsigned char *flag, int i)
{
	if (ft_strnstr(line, "EA ", 3))
	{
		if ((i = flag_check(3, EA_TEXT_NUM, flag, line)) < 0)
			return (error_msg("east overlap"));
		set->minfo.ea_path = ft_strdup(line + i);
	}
	if (ft_strnstr(line, "WE ", 3))
	{
		if ((i = flag_check(3, WE_TEXT_NUM, flag, line)) < 0)
			return (error_msg("west overlap"));
		set->minfo.we_path = ft_strdup(line + i);
	}
	if (ft_strnstr(line, "SO ", 3))
	{
		if ((i = flag_check(3, SO_TEXT_NUM, flag, line)) < 0)
			return (error_msg("south overlap"));
		set->minfo.so_path = ft_strdup(line + i);
	}
	if (ft_strnstr(line, "NO ", 3))
	{
		if ((i = flag_check(3, NO_TEXT_NUM, flag, line)) < 0)
			return (error_msg("north overlap"));
		set->minfo.no_path = ft_strdup(line + i);
	}
	return (1);
}

int		map_fc_check(t_set *set, char *line, unsigned char *flag, int i)
{
	if (ft_strnstr(line, "F ", 2))
	{
		if ((i = flag_check(2, FL_TEXT_NUM, flag, line)) < 0)
			return (error_msg("floor overlap"));
		if (!get_floor(set, line + i))
			return (0);
	}
	if (ft_strnstr(line, "C ", 2))
	{
		if ((i = flag_check(2, CE_TEXT_NUM, flag, line)) < 0)
			return (error_msg("ceiling overlap"));
		if (!get_ceiling(set, line + i))
			return (0);
	}
	return (1);
}

int		map_etc_check(t_set *set, char *line, unsigned char *flag, int i)
{
	if (ft_strnstr(line, "S ", 2))
	{
		if ((i = flag_check(2, SP_TEXT_NUM, flag, line)) < 0)
			return (error_msg("sprite overlap"));
		set->minfo.sp_path = ft_strdup(line + i);
	}
	if (ft_strnstr(line, "R ", 2))
	{
		if ((i = flag_check(2, RE_NUM, flag, line)) < 0)
			return (error_msg("resolution overlap"));
		if ((set->minfo.s_width = ft_atoi(line + i)) < 0)
			return (error_msg("resolution width error"));
		i += count_num(set->minfo.s_width);
		if ((set->minfo.s_height = ft_atoi(line + i + 1)) < 0)
			return (error_msg("resolution height error"));
		max_min_resolution(set);
	}
	return (1);
}

int		map_check(t_set *set, int fd, char **line)
{
	unsigned char	flag;
	int				i;
	int				rt;

	flag = 0;
	i = 0;
	while (flag != 255 && (rt = get_next_line(fd, line)) > 0)
	{
		if (!map_side_check(set, *line, &flag, i))
			return (0);
		else if (!map_fc_check(set, *line, &flag, i))
			return (0);
		else if (!map_etc_check(set, *line, &flag, i))
			return (0);
		if (*line)
			free(*line);
	}
	if (rt <= 0)
		return (0);
	return (1);
}
