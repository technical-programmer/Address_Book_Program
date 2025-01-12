#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Contact class to represent each contact's details
class Contact {
public:
    string firstName, lastName, address, city, state, zip, phoneNumber, email;

    // Constructor to initialize a new contact
    Contact(string fn, string ln, string addr, string cty, string st, string zp, string phone, string em) {
        this -> firstName = fn;
        this -> lastName = ln;
        this -> address = addr;
        this -> city = cty;
        this -> state = st;
        this -> zip = zp;
        this -> phoneNumber = phone;
        this ->email = em;
    }

    // Method to display the contact details
    void display() const {
        cout << "Name: " << firstName << " " << lastName << "\n"
             << "Address: " << address << ", " << city << ", " << state << " - " << zip << "\n"
             << "Phone: " << phoneNumber << "\n"
             << "Email: " << email << "\n";
    }
};

class AddressBook {
private:
    vector<Contact> contacts;  // List of contacts

public:
    // Method to add a new contact
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
        cout << "Contact added successfully!\n";
    }

    // Method to display all contacts in the address book
    void displayContacts() const {
        if (contacts.empty()) {
            cout << "No contacts available.\n";
            return;
        }
        for (int  i = 0; i < contacts.size(); ++i) {
            cout << "\nContact " << i + 1 << ":\n";
            contacts[i].display();
        }
    }
};

int main() {
    AddressBook addressBook;

    string firstName, lastName, address, city, state, zip, phoneNumber, email;

    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter Address: ";
    cin >> address;
    cout << "Enter City: ";
    cin >> city;
    cout << "Enter State: ";
    cin >> state;
    cout << "Enter Zip Code: ";
    cin >> zip;
    cout << "Enter Phone Number: ";
    cin >> phoneNumber;
    cout << "Enter Email: ";
    cin >> email;

    Contact newContact(firstName, lastName, address, city, state, zip, phoneNumber, email);
    addressBook.addContact(newContact);

    // Displaying the contact
    addressBook.displayContacts();

    return 0;
}
