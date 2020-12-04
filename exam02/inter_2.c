/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:09:33 by skim              #+#    #+#             */
/*   Updated: 2020/12/04 20:26:56 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_strchr(char c, char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int main(int ac, char *av[])
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	int size = ft_strlen(av[1]);
	int i = 0;
	while (av[1][i])
	{
		if (!ft_strchr(av[1][i], av[2]))
			av[1][i] = 0;
		i++;
	}
	int j;
	while (av[1][--i])
	{
		j = 0;
		while (j < i)
		{
			if (av[1][j] == av[1][i])
			{
				av[1][i] = 0;
				break;
			}
			j++;
		}
	}
	for (i = 0; i < size; i++)
	{
		if (av[1][i])
			write(1, &av[1][i], 1);
	}
	write(1, "\n", 1);
}
