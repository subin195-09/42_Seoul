/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:57:51 by skim              #+#    #+#             */
/*   Updated: 2021/07/01 21:09:18 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void    Phonebook::getInfo()
{
	std::cout << "firstName : ";
	getline(std::cin, firstName);
	
	std::cout << "lastName : ";
	getline(std::cin, lastName);
	
	std::cout << "nickName : ";
	getline(std::cin, nickName);
	
	std::cout << "login : ";
	getline(std::cin, login);
	
	std::cout << "postalAddress : ";
	getline(std::cin, postalAddress);
	
	std::cout << "emailAddress : ";
	getline(std::cin, emailAddress);
	
	std::cout << "phoneNumber : ";
	getline(std::cin, phoneNumber);
	
	std::cout << "birthdayDate : ";
	getline(std::cin, birthdayDate);
	
	std::cout << "favoriteMeal : ";
	getline(std::cin, favoriteMeal);
	
	std::cout << "underwearColor : ";
	getline(std::cin, underwearColor);
	
	std::cout << "darkestSecret : ";
	getline(std::cin, darkestSecret);
}

void    Phonebook::showInfo()
{
	std::cout << "firstName : " + firstName << std::endl;
	std::cout << "lastName : " + lastName << std::endl;
	std::cout << "nickName : " + nickName << std::endl;
	std::cout << "login : " + login << std::endl;
	std::cout << "postalAddress : " + postalAddress << std::endl;
	std::cout << "emailAddress : " + emailAddress << std::endl;
	std::cout << "phoneNumber : " + phoneNumber << std::endl;
	std::cout << "birthdayDate : " + birthdayDate << std::endl;
	std::cout << "favoriteMeal : " + favoriteMeal << std::endl;
	std::cout << "underwearColor : " + underwearColor << std::endl;
	std::cout << "darkestSecret : " + darkestSecret << std::endl;
}

void	Phonebook::showShortInfo(int i)
{
	std::cout << "|" << std::setw(10) << std::right << i + 1;
	setString(firstName);
	setString(lastName);
	setString(nickName);
	std::cout << "|" << std::endl;
}