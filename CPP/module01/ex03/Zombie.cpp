/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:03:07 by skim              #+#    #+#             */
/*   Updated: 2021/07/04 19:38:23 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string _name, std::string _type)
{
    name = _name;
    type = _type;
}

void    Zombie::announce(void)
{
    std::cout << "<" + name + " (" + type + ")> Braiiiiiinnss..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "<" + name + " (" + type + ")> die!!!" << std::endl;
}