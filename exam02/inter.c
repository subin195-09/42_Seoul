/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:58:09 by skim              #+#    #+#             */
/*   Updated: 2020/12/04 20:09:23 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_strchr(int c, char *s)
{
	int i = -1;

	while (s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

int		main(int argc, char *argv[])
{
	int		size;
	int		i;
	int		j;

	if (argc == 3)
	{
		size = ft_strlen(argv[1]);
		i = 0;
		while(argv[1][i])
		{
			if (!(ft_strchr(argv[1][i], argv[2])))
				argv[1][i] = 0;
			i++;
		}
		i = 0;
		while (i < size - 1)
		{
			j = i + 1;
			while (j < size)
			{
				if (argv[1][j] == argv[1][i])
				{
					argv[1][j] = 0;
					break;
				}
				j++;
			}
			i++;
		}
		i = 0;
		while (i < size)
		{
			if (argv[1][i])
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
