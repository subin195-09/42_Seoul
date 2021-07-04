/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:11:40 by skim              #+#    #+#             */
/*   Updated: 2021/07/04 19:38:49 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_EVENT_H
# define ZOMBIE_EVENT_H

#include <cstring>
#include <iostream>
#include <cstdlib>
#include "Zombie.hpp"

class	ZombieEvent{
	public:
		static Zombie		*newZombie(std::string name);
		static std::string	setZombieType(void);
};

#endif