#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <vector>

// Structure to hold individual contact details
struct Contact {
    std::string name;
    std::string phoneNumber;
    std::string email;
};

// Class to manage the collection of contacts
class ContactManager {
private:
    std::vector<Contact> contacts; // Using a Vector as our core Data Structure

public:
    void addContact(const std::string& name, const std::string& phone, const std::string& email);
    void viewContacts() const;
    void searchContact(const std::string& name) const;
    void deleteContact(const std::string& name);
};

#endif // CONTACT_H