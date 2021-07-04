/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:03:07 by skim              #+#    #+#             */
/*   Updated: 2021/07/04 17:32:51 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string _name)
{
    name = _name;
}

void    Zombie::announce(void)
{
    std::cout << "<" + name + " (" + type + ")> Braiiiiiinnss..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "<" + name + " (" + type + ")> die!!!" << std::endl;
}