/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:48:32 by skim              #+#    #+#             */
/*   Updated: 2020/12/03 18:05:50 by skim             ###   ########.fr       */
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

void	ft_strchr(int i, int stop, char c, char **s)
{
	int j = i + 1;

	while (j < stop)
	{
		if ((*s)[j] == c)
			(*s)[j] = 0;
		j++;
	}
}

void	ft_putstr_n(char *s, int stop)
{
	int i;

	i = 0;
	while (i < stop)
	{
		if (s[i])
			write(1, &s[i], 1);
		i++;
	}
}

int 	main(int argc, char *argv[])
{
	int i;
	int size_one;
	int size_two;

	if (argc == 3)
	{
		size_one = ft_strlen(argv[1]);
		size_two = ft_strlen(argv[2]);
		i = 0;
		while (i < size_one)
		{
			if (argv[1][i])
			{
				ft_strchr(i, size_one, argv[1][i], &argv[1]);
				ft_strchr(-1, size_two, argv[1][i], &argv[2]);
			}
			i++;
		}
		i = 0;
		while (i < size_two)
		{
			if (argv[2][i])
				ft_strchr(i, size_two, argv[2][i], &argv[2]);
			i++;
		}
		ft_putstr_n(argv[1], size_one);
		ft_putstr_n(argv[2], size_two);
	}
	write(1, "\n", 1);
	return (0);
}

