/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:35:31 by skim              #+#    #+#             */
/*   Updated: 2021/07/04 18:34:30 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

std::string	randomName()
{
	std::string	name;
	int		i;

	name += (char)(rand() % 26 + 'A');
	name += (char)(rand() % 10 + '0');
	
	return (name);
}

Zombie	*randomChump()
{
	Zombie *zombie = ZombieEvent::newZombie(randomName());
	ZombieEvent::setZombieType(zombie);
	zombie->announce();
	return (zombie);
}

int		main(void)
{
	srand((unsigned int)time(NULL));
	Zombie s_zombie = Zombie("stack_zombie");
	s_zombie.type = "stack_type";
	s_zombie.announce();

	Zombie *h_zombie[10];
	for(int i = 0; i < 10; i++)
		h_zombie[i] = randomChump();
	for (int i = 0; i < 10; i++)
		delete h_zombie[i];
	return (0);
}
