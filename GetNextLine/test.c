/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 02:05:13 by skim              #+#    #+#             */
/*   Updated: 2020/11/20 19:32:32 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	char	*line;
	int		fd = open("file.txt", O_RDONLY);
	int		n;

	while ((n = get_next_line(fd, &line)) > 0)
	{
		printf("line : %s\n", line);
		printf("n : %d\n", n);
	}
	printf("n : %d\n", n);
}
