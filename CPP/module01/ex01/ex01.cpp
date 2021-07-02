/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:00:14 by skim              #+#    #+#             */
/*   Updated: 2021/07/02 17:11:58 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>

void	memoryLeak()
{
	std::string* panther = new std::string("String panther");
	std::cout << *panther << std::endl;
	delete  panther;
	panther = 0;
}

int		main(void)
{
	memoryLeak();
	system("leaks a.out");
}