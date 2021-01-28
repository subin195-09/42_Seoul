/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06.map_par.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:17:04 by skim              #+#    #+#             */
/*   Updated: 2021/01/28 13:02:41 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub_main.h"
#include "get_next_line.h"

void	map_parse(void)
{
	char	*line;
	int		fd = open("map.cub", O_RDONLY);
	int		n;

	while ((n = get_next_line(fd, &line)) > 0)
	{
		printf("line : %s\n", line);
		free(line);
	}
	printf("line : %s\n", line);
	free(line);
}

int main(void)
{
	t_set set;
	map_parse();
}
