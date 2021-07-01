/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:50:19 by skim              #+#    #+#             */
/*   Updated: 2021/07/01 20:19:51 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char *av[])
{
	int		i;
	int		j;
	char	c;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for(i = 1; i < ac; i++)
		{
			j = -1;
			while (av[i][++j])
			{
				c = toupper(av[i][j]);
				std::cout << c;
			}
		}
	}
	std::cout << std::endl;
	return EXIT_SUCCESS;
}