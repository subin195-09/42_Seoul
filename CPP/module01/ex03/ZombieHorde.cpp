/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:50:10 by skim              #+#    #+#             */
/*   Updated: 2021/07/04 20:02:54 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

std::string	randomType(void)
{
	std::string	type[10];

	type[0] = "red";
	type[1] = "orange";
	type[2] = "yellow";
	type[3] = "green";
	type[4] = "blue";
	type[5] = "navy";
	type[6] = "purple";
	type[7] = "black";
	type[8] = "white";
	type[9] = "pink";
	return (type[rand() % 10]);
}

std::string	randomName(void)
{
	std::string	name;

	name += (char)(rand() % 26 + 'A');
	name += (char)(rand() % 10 + '0');
	
	return (name);
}

ZombieHorde::ZombieHorde(int _size)
{
	size = _size;
	for(int i = 0; i < size; i++)
	{
		horde[i] = new Zombie(randomName(), randomType());
		std::cout << i;
		horde[i]->announce();
	}
}

ZombieHorde::~ZombieHorde()
{
	for(int i = 0; i < size; i++)
		delete horde[i];
}