/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:34:37 by skim              #+#    #+#             */
/*   Updated: 2021/07/02 16:30:40 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_H
# define PONY_H

#include <cstring>
#include <iostream>

class Pony {
	private:
		std::string name;
	public:
		Pony(std::string _name);
		~Pony();
		std::string getName();
};

#endif