/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:42:45 by swied             #+#    #+#             */
/*   Updated: 2025/10/08 12:43:14 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
    PhoneBook phonebook;
    std::string command;
    
    std::cout << "Welcome to your PhoneBook!" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
    
    while (true) {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);
        
        if (command == "ADD") {
            phonebook.addContact();
        }
        else if (command == "SEARCH") {
            phonebook.searchContact();
        }
        else if (command == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else {
            std::cout << "Unknown command. Available commands: ADD, SEARCH, EXIT" << std::endl;
        }
    }
    
    return 0;
}

