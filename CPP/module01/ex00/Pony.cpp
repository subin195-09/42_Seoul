/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 16:28:23 by skim              #+#    #+#             */
/*   Updated: 2021/07/02 16:49:14 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string _name)
{
    name = _name;
}

Pony::~Pony(void)
{
    std::cout << name + " delete!" << std::endl;
}

std::string Pony::getName(void)
{
    return name;
}