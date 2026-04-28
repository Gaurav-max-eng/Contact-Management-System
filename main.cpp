#include <iostream>
#include <string>
#include "Contact.h" // Include your custom library header

int main() {
    ContactManager manager;
    int choice;
    std::string name, phone, email;

    do {
        std::cout << "\n=== Contact Management System ===\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. View All Contacts\n";
        std::cout << "3. Search Contact\n";
        std::cout << "4. Delete Contact\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        
        // Handle invalid input
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            choice = 0;
        }
        std::cin.ignore(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                std::cout << "Enter Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Phone: ";
                std::getline(std::cin, phone);
                std::cout << "Enter Email: ";
                std::getline(std::cin, email);
                manager.addContact(name, phone, email);
                break;
            case 2:
                manager.viewContacts();
                break;
            case 3:
                std::cout << "Enter Name to Search: ";
                std::getline(std::cin, name);
                manager.searchContact(name);
                break;
            case 4:
                std::cout << "Enter Name to Delete: ";
                std::getline(std::cin, name);
                manager.deleteContact(name);
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number from 1 to 5.\n";
        }
    } while (choice != 5);

    return 0;
}