/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:37:50 by skim              #+#    #+#             */
/*   Updated: 2021/07/02 16:46:51 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheStack(void)
{
	Pony	sPony("stack");

	std::cout << sPony.getName() << std::endl;
}

void	ponyOnTheHeap(void)
{
	Pony	*hPony = new Pony("heap");

	std::cout << hPony->getName() << std::endl;
	delete hPony;
	hPony = 0;
}

int		main(void)
{
	std::cout << "pony on the stack" << std::endl;
	ponyOnTheStack();
	std::cout << "pony on the heap" << std::endl;
	ponyOnTheHeap();
	return (0);
}