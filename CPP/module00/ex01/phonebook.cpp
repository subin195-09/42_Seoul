/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:01:42 by skim              #+#    #+#             */
/*   Updated: 2021/07/01 21:32:18 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	setString(std::string info)
{
	if (info.length() > 10)
		std::cout << "|" << std::setw(10) << std::right << info.substr(0, 9) + ".";
	else
		std::cout << "|" << std::setw(10) << std::right << info;
}

int		getIndex(int size)
{
	int	i;
	
	std::cout << "Enter index to get full page : ";
	std::cin >> i;
	if (std::cin.fail() || i < 1 || i >= size + 1)
	{
		std::cout << "Wrong Index" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n'); 
		return getIndex(size);
	}
	else
		return i;
}

void    searchInfo(Phonebook pb[8], int size)
{
	int			i;
	
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|" << std::setw(10) << std::right << "index";
	std::cout << "|" << std::setw(10) << std::right << "firstName";
	std::cout << "|" << std::setw(10) << std::right << "lastName";
	std::cout << "|" << std::setw(11) << std::right << "nickName|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (i = 0; i < size; i++)
	{
		pb[i].showShortInfo(i);
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}
	if (size > 0)
	{
		i = getIndex(size);
		pb[i - 1].showInfo();
		std::cin.ignore();
	}
}

int     main(void)
{
	Phonebook	pb[8];
	std::string	com;
	int         i;
	int			j;
	
	i = 0;
	j = 0;
	while (1)
	{
		std::cout << "Enter a command : ";
		getline(std::cin, com);
		if (com == "ADD")
		{
			if (i == 8)
				std::cout << "Phonebook Full!" << std::endl;
			else
				pb[i++].getInfo();
		}   
		else if (com == "SEARCH")
			searchInfo(pb, i);
		else if (com == "EXIT")
			break ;
		else
			std::cout << "Wrong Command" << std::endl;
	}
	return (0);
}