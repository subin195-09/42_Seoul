/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:44:25 by skim              #+#    #+#             */
/*   Updated: 2021/07/04 18:23:40 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <cstring>
#include <iostream>

class Zombie{
    private:
        std::string name;
    public:
		std::string type;
		Zombie(std::string _name);
        void	announce();
		~Zombie();
};

#endif
