/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:57:51 by skim              #+#    #+#             */
/*   Updated: 2021/07/01 17:58:28 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void    Phonebook::getInfo()
{
	std::cout << "firstName : ";
	std::cin >> firstName;
	std::cout << "lastName : ";
	std::cin >> lastName;
	std::cout << "nickName : ";
	std::cin >> nickName;
	std::cout << "login : ";
	std::cin >> login;
	std::cout << "postalAddress : ";
	std::cin >> postalAddress;
	std::cout << "emailAddress : ";
	std::cin >> emailAddress;
	std::cout << "phoneNumber : ";
	std::cin >> phoneNumber;
	std::cout << "birthdayDate : ";
	std::cin >> birthdayDate;
	std::cout << "favoriteMeal : ";
	std::cin >> favoriteMeal;
	std::cout << "underwearColor : ";
	std::cin >> underwearColor;
	std::cout << "darkestSecret : ";
	std::cin >> darkestSecret;
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