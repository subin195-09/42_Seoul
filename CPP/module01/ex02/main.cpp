/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:35:31 by skim              #+#    #+#             */
/*   Updated: 2021/07/04 19:39:11 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

std::string	randomName()
{
	std::string	name;

	name += (char)(rand() % 26 + 'A');
	name += (char)(rand() % 10 + '0');
	
	return (name);
}

Zombie	*randomChump()
{
	Zombie *zombie = ZombieEvent::newZombie(randomName());
	zombie->announce();
	return (zombie);
}

int		main(void)
{
	srand((unsigned int)time(NULL));
	Zombie s_zombie = Zombie("stack_zombie", "stack_type");
	s_zombie.announce();

	Zombie *h_zombie;
	for(int i = 0; i < 10; i++)
	{
		h_zombie = randomChump();
		delete h_zombie;
	}
	return (0);
}
