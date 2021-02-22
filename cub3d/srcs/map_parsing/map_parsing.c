/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:53:43 by skim              #+#    #+#             */
/*   Updated: 2021/02/23 00:37:20 by skim             ###   ########.fr       */
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

void	map_side_check(t_set *set, char *line, unsigned char *flag, int i)
{
	if (ft_strnstr(line, "EA ", 3))
	{
		i = flag_check(3, EA_TEXT_NUM, flag, line);
		i < 0 ? exit(error_msg("EA")) : 0;
		set->minfo.ea_path = ft_strdup(line + i);
	}
	if (ft_strnstr(line, "WE ", 3))
	{
		i = flag_check(3, WE_TEXT_NUM, flag, line);
		i < 0 ? exit(error_msg("WE")) : 0;
		set->minfo.we_path = ft_strdup(line + i);
	}
	if (ft_strnstr(line, "SO ", 3))
	{
		i = flag_check(3, SO_TEXT_NUM, flag, line);
		i < 0 ? exit(error_msg("SO")) : 0;
		set->minfo.so_path = ft_strdup(line + i);
	}
	if (ft_strnstr(line, "NO ", 3))
	{
		i = flag_check(3, NO_TEXT_NUM, flag, line);
		i < 0 ? exit(error_msg("NO")) : 0;
		set->minfo.no_path = ft_strdup(line + i);
	}
}

void	map_fc_check(t_set *set, char *line, unsigned char *flag, int i)
{
	if (ft_strnstr(line, "F ", 2))
	{
		i = flag_check(2, FL_TEXT_NUM, flag, line);
		i < 0 ? exit(error_msg("FL")) : 0;
		get_floor(set, line + i);
	}
	if (ft_strnstr(line, "C ", 2))
	{
		i = flag_check(2, CE_TEXT_NUM, flag, line);
		i < 0 ? exit(error_msg("CE")) : 0;
		get_ceiling(set, line + i);
	}
}

void	map_etc_check(t_set *set, char *line, unsigned char *flag, int i)
{
	if (ft_strnstr(line, "S ", 2))
	{
		i = flag_check(2, SP_TEXT_NUM, flag, line);
		i < 0 ? exit(error_msg("SP")) : 0;
		set->minfo.sp_path = ft_strdup(line + i);
	}
	if (ft_strnstr(line, "R ", 2))
	{
		i = flag_check(2, RE_NUM, flag, line);
		i < 0 ? exit(error_msg("R")) : 0;
		if ((set->minfo.s_width = ft_atoi(line + i)) < 0)
			return ;
		i += count_num(set->minfo.s_width);
		if ((set->minfo.s_height = ft_atoi(line + i)) < 0)
			return ;
	}
}

int		map_parse(t_set *set, char *map_name)
{
	char			*line;
	int				fd;
	unsigned char	flag;
	int				i;

	fd = open(map_name, O_RDONLY);
	flag = 0;
	i = 0;
	while (flag != 255 && (i = get_next_line(fd, &line)) > 0)
	{
		map_side_check(set, line, &flag, i);
		map_fc_check(set, line, &flag, i);
		map_etc_check(set, line, &flag, i);
	}
	if (i <= 0)
		return (0);
	while (line[0] != ' ' && !ft_isdigit(line[0]))
		get_next_line(fd, &line);
	get_map(fd, &line, set);
	if (!check_map(set))
	{
		printf("Map Error\n");
		return (0);
	}
	return (1);
}
