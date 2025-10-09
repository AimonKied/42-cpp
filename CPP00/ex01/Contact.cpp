/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:42:51 by swied             #+#    #+#             */
/*   Updated: 2025/10/09 16:48:30 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

void Contact::getInfo(){
	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);

	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
		std::cout << "Error: Fields cannot be empty" << std::endl;
		*this = Contact();
	}
}

void Contact::displayShort(int index) const {
	std::string displayFirstName, displayLastName, displayNickname;
	
	if (firstName.length() > 10)
		displayFirstName = firstName.substr(0, 9) + ".";
	else
		displayFirstName = firstName;
	if (lastName.length() > 10)
		displayLastName = lastName.substr(0, 9) + ".";
	else
		displayLastName = lastName;
	if (nickname.length() > 10)
		displayNickname = nickname.substr(0, 9) + ".";
	else
		displayNickname = nickname;
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << displayFirstName;
	std::cout << "|" << std::setw(10) << displayLastName;
	std::cout << "|" << std::setw(10) << displayNickname;
	std::cout << "|" << std::endl;
}

void Contact::displayFull() const {
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

bool Contact::isEmpty() const {
	return firstName.empty();
}