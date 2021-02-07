/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06.map_par.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:17:04 by skim              #+#    #+#             */
/*   Updated: 2021/02/07 18:33:26 by skim             ###   ########.fr       */
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

// 해상도
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

// texture 경로
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

// floor, ceiling color 받아오기
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

// map 읽어서 저장
void	change_map(t_set *set, int **map, char *temp_map)
{
	int		j;

	j = -1;
	while (++j < set->minfo.m_width)
		(*map)[j] = -1;
	j = -1;
	while (temp_map[++j] != 0)
	{
		(*map)[j] = temp_map[j] == ' ' ? -1 : temp_map[j] - '0';
		if ((*map)[j] == 2)
			set->minfo.num_sprite++;
	}
}

void	get_map_size(t_set *set, int fd, int fd_2, char **line)
{
	int		temp_size;

	get_next_line(fd, line);
	set->minfo.m_height = 0;
	set->minfo.m_width = 0;
	while ((get_next_line(fd, line)) > 0)
	{
		temp_size = ft_strlen(*line);
		if (set->minfo.m_width < temp_size)
			set->minfo.m_width = temp_size;
		set->minfo.m_height++;
		write(fd_2, *line, temp_size);
		write(fd_2, "\n", 1);
	}
}

int		get_map(int fd, char **line, t_set *set)
{
	int		i;
	int		fd_2;
	char	*temp_map;

	i = -1;
	fd_2 = open("tmp_map", O_CREAT | O_RDWR, 0777);
	get_map_size(set, fd, fd_2, line);
	set->minfo.num_sprite = 0;
	set->map = (int **)malloc(sizeof(int *) * set->minfo.m_height);
	while (++i < set->minfo.m_height)
		set->map[i] = (int *)malloc(sizeof(int) * set->minfo.m_width);
	close(fd);
	close(fd_2);
	fd_2 = open("tmp_map", O_RDONLY);
	i = 0;
	while ((get_next_line(fd_2, &temp_map) > 0))
	{
		change_map(set, &(set->map[i++]), temp_map);
		free(temp_map);
	}
	free(temp_map);
	close(fd_2);
	return (1);
}

// map 유효성 검사
void	init_ck_map(t_set *set, int ***ck_map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < set->minfo.m_height + 2)
	{
		j = -1;
		while (++j < set->minfo.m_width + 2)
		{
			if (i * j == 0 || i == set->minfo.m_height + 1 || j == set->minfo.m_width + 1)
				(*ck_map)[i][j] = -1;
			else
				(*ck_map)[i][j] = set->map[i - 1][j - 1];
		}
	}
}

int		is_road(t_set *set, int ***ck_map, int x, int y)
{
	int		dir_x[4];
	int		dir_y[4];
	int		i;

	dir_x[0] = -1;
	dir_x[1] = 0;
	dir_x[2] = 1;
	dir_x[3] = 0;
	i = -1;
	while (++i < 4)
		dir_y[3 - i] = dir_x[i];
	i = -1;
	if ((*ck_map)[x][y] == 1 || (*ck_map)[x][y] == -2)
		return (1);
	if ((*ck_map)[x][y] == -1)
		return (0);
	(*ck_map)[x][y] = -2;
	i = -1;
	while (++i < 4)
		if (!is_road(set, ck_map, x + dir_x[i], y + dir_y[i]))
			return (0);
	return (1);
}

int		is_map(t_set *set, int **ck_map)
{
	int		is_zero;
	int		i;
	int		j;

	is_zero = 0;
	i = -1;
	while (++i < set->minfo.m_height)
	{
		j = -1;
		while (++j < set->minfo.m_width)
		{
			if (ck_map[i][j] == 0)
			{
				is_zero = 1;
				if (is_road(set, &ck_map, i, j) == 0)
					return (0);
			}

		}
	}
	if (!is_zero)
		return (0);
	else
		return (1);
}

int		check_map(t_set *set)
{
	int		**ck_map;
	int		i;

	ck_map = (int **)malloc(sizeof(int *) * (set->minfo.m_height + 2));
	i = -1;
	while (++i < set->minfo.m_width)
		ck_map[i] = (int *)malloc(sizeof(int) * (set->minfo.m_width + 2));
	init_ck_map(set, &ck_map);
	return (1);
}

void	map_parse(t_set *set)
{
	char	*line;
	int		fd = open("map.cub", O_RDONLY);

	if (!get_resolution(fd, &line, set))
		printf("Error\n");
	if (!get_path(fd, &line, set))
		printf("Error\n");
	// texture로 주어지는 상황 2개 모두 고려할 것인가?
	if (!get_fc(fd, &line, set))
		printf("Error\n");
	get_map(fd, &line, set);
	if (!check_map(set))
		printf("Error\n");
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
	printf("m_height : %d\n", set.minfo.m_height);
	printf("m_width : %d\n", set.minfo.m_width);
	printf("num_sprite : %d\n", set.minfo.num_sprite);
	for(int i = 0; i < set.minfo.m_height; i++)
	{
		for(int j = 0; j < set.minfo.m_width; j++)
			printf("%3d", set.map[i][j]);
		printf("\n");
	}
}
