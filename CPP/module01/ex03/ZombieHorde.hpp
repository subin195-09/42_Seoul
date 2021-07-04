/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:32:09 by skim              #+#    #+#             */
/*   Updated: 2021/07/04 19:56:56 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_H
#define ZOMBIEHORDE_H

#include "Zombie.hpp"

class	ZombieHorde{
	private:
		Zombie	**horde;
		int		size;
	public:
		ZombieHorde(int _size);
		~ZombieHorde();
};

#endif