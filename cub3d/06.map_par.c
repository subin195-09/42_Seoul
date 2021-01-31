/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06.map_par.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:17:04 by skim              #+#    #+#             */
/*   Updated: 2021/01/31 19:15:42 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

int		check_str(char *chk, char **line, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (chk[i] != **line)
			return (0);
		(*line)++;
	}
	return (1);
}

int		get_resolution(int fd, char **line, t_set *set)
{
	get_next_line(fd, line);
	if (!check_str("R ", line, 2))
		return (0);
	if ((set->minfo.s_width = ft_atoi(*line)) < 0)
		return (0);
	(*line) += count_num(set->minfo.s_width);
	if (!check_str(" ", line, 1))
		return (0);
	if ((set->minfo.s_height = ft_atoi(*line)) < 0)
		return (0);
	return (1);
}

int		get_path(int fd, char **line, t_set *set)
{
	get_next_line(fd, line);
	if (!check_str("NO ", line, 3))
		return (0);
	set->minfo.no_path = ft_strdup(*line);
	get_next_line(fd, line);
	if (!check_str("SO ", line, 3))
		return (0);
	set->minfo.so_path = ft_strdup(*line);
	get_next_line(fd, line);
	if (!check_str("WE ", line, 3))
		return (0);
	set->minfo.we_path = ft_strdup(*line);
	get_next_line(fd, line);
	if (!check_str("EA ", line, 3))
		return (0);
	set->minfo.ea_path = ft_strdup(*line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	if (!check_str("S ", line, 2))
		return (0);
	set->minfo.sp_path = ft_strdup(*line);
	return (1);
}

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
			return (-1);
	}
	g = ft_atoi(++line);
	while (*line != ',' && *line)
	{
		line++;
		if (!(*line))
			return (0);
	}
	b = ft_atoi(++line);
	printf("%d, %d, %d\n", r,g,b);
	return ((r * 256 * 256) + (g * 256) + b);
}


int		get_fc(int fd, char **line,  t_set *set)
{
	get_next_line(fd, line);
	if (!check_str("F ", line, 2))
		return (0);
	if (!ft_isdigit(**line))
		return (0);
	if ((set->minfo.floor = get_color(*line)) < 0)
		return (0);
	get_next_line(fd, line);
	if (!check_str("C ", line, 2))
		return (0);
	if (!ft_isdigit(**line))
		return (0);
	if ((set->minfo.ceiling = get_color(*line)) < 0)
		return (0);
	return (1);
}

void	map_parse(t_set *set)
{
	char	*line;
	int		fd = open("map.cub", O_RDONLY);
	int		n;

	if (!get_resolution(fd, &line, set))
		printf("Error\n");
	if (!get_path(fd, &line, set))
		printf("Error\n");
	// texture로 주어지는 상황 2개 모두 고려할 것인가?
	if (!get_fc(fd, &line, set))
		printf("Error\n");
	get_map_size(fd, &line);
}

int main(void)
{
	t_set set;
	map_parse(&set);

	printf("s_width : %d\n", set.minfo.s_width);
	printf("s_height : %d\n", set.minfo.s_height);
	printf("no_path : %s\n", set.minfo.no_path);
	printf("so_path : %s\n", set.minfo.so_path);
	printf("we_path : %s\n", set.minfo.we_path);
	printf("ea_path : %s\n", set.minfo.ea_path);
	printf("s_path : %s\n", set.minfo.sp_path);
	printf("floor : %d\n", set.minfo.floor);
	printf("ceiling : %d\n", set.minfo.ceiling);
}
