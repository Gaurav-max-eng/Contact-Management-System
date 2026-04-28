#include "Contact.h"
#include <iostream>
#include <algorithm> // For std::find_if

// Adds a new contact to the vector
void ContactManager::addContact(const std::string& name, const std::string& phone, const std::string& email) {
    contacts.push_back({name, phone, email});
    std::cout << "Contact added successfully!\n";
}

// Iterates through the vector to display all contacts
void ContactManager::viewContacts() const {
    if (contacts.empty()) {
        std::cout << "No contacts found.\n";
        return;
    }
    std::cout << "\n--- Contact List ---\n";
    for (const auto& contact : contacts) {
        std::cout << "Name: " << contact.name
                  << " | Phone: " << contact.phoneNumber
                  << " | Email: " << contact.email << "\n";
    }
    std::cout << "--------------------\n";
}

// Searches for a contact by name
void ContactManager::searchContact(const std::string& name) const {
    auto it = std::find_if(contacts.begin(), contacts.end(),
                           [&name](const Contact& c) { return c.name == name; });

    if (it != contacts.end()) {
        std::cout << "\nContact found: \nName: " << it->name 
                  << "\nPhone: " << it->phoneNumber 
                  << "\nEmail: " << it->email << "\n";
    } else {
        std::cout << "Contact not found.\n";
    }
}

// Finds and removes a contact from the vector
void ContactManager::deleteContact(const std::string& name) {
    auto it = std::find_if(contacts.begin(), contacts.end(),
                           [&name](const Contact& c) { return c.name == name; });

    if (it != contacts.end()) {
        contacts.erase(it);
        std::cout << "Contact deleted successfully!\n";
    } else {
        std::cout << "Contact not found. Deletion failed.\n";
    }
}
