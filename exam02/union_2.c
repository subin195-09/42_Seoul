/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:49:28 by skim              #+#    #+#             */
/*   Updated: 2020/12/04 21:05:23 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	int size_one = ft_strlen(av[1]);
	int size_two = ft_strlen(av[2]);
	char result[size_one + size_two];
	int	i = 0;
	while (i < size_one)
		result[i++] = *av[1]++;
	while (i < size_one + size_two)
		result[i++] = *av[2]++;
	i = 0;
	int j;
	while (i < size_one + size_two - 1)
	{
		j = i + 1;
		while (result[i] && j < size_one + size_two)
		{
			if (result[j] == result[i])
				result[j] = 0;
			j++;
		}
		i++;
	}
	for (i = 0; i < size_one + size_two; i++)
	{
		if (result[i])
			write(1, &result[i], 1);
	}
	write(1, "\n", 1);
}		
