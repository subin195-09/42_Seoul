/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:01:42 by skim              #+#    #+#             */
/*   Updated: 2021/07/01 18:43:24 by skim             ###   ########.fr       */
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

int		checkIndex(std::string index, int size)
{
	int	i;
	
	for (i = 0; index[i]; i++)
	{
		if (!isdigit(index[i]))
			return (0);
	}
	std::stringstream(index) >> i;
	if (i < 1 || i >= size + 1)
		return (0);
	return (1);
}

void    searchInfo(Phonebook pb[8], int size)
{
	std::string	index;
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
	std::cout << "Enter index to get full page : ";
	std::cin >> index;
	if (!checkIndex(index, size))
		std::cout << "Wrong Index" << std::endl;
	else
		pb[i - 1].showInfo();
}

int     main(void)
{
	Phonebook	pb[8];
	std::string	com;
	int         i;
	
	i = 0;
	while (1)
	{
		std::cout << "Enter a command : ";
		std::cin >> com;
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