#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Contact {
public:
    string firstName, lastName, address, city, state, zip, phoneNumber, email;


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

    void display() const {
        cout << "Name: " << firstName << " " << lastName << "\n"
             << "Address: " << address << ", " << city << ", " << state << " - " << zip << "\n"
             << "Phone: " << phoneNumber << "\n"
             << "Email: " << email << "\n";
    }

    // Method to edit the contact details
    void editContact(const string& addr, const string& cty, const string& st, const string& zp, 
                     const string& phone, const string& em) {
        address = addr;
        city = cty;
        state = st;
        zip = zp;
        phoneNumber = phone;
        email = em;
    }
};

class AddressBook {

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
        for (int i = 0; i < contacts.size(); ++i) {
            cout << "\nContact " << i + 1 << ":\n";
            contacts[i].display();
        }
    }

    // Method to edit a contact by their first or last name
    void editContactByName(const string& name) {
        for (int i = 0; i < contacts.size(); ++i) {
            if (contacts[i].firstName == name || contacts[i].lastName == name) {
                cout << "Editing Contact: " << name << "\n";
                string address, city, state, zip, phone, email;
                
                cout << "Enter new Address: ";
                cin >>  address;
                cout << "Enter new City: ";
                cin >>  city;
                cout << "Enter new State: ";
                cin >>  state;
                cout << "Enter new Zip Code: ";
                cin >>  zip;
                cout << "Enter new Phone Number: ";
                cin >>  phone;
                cout << "Enter new Email: ";
                cin >>  email;

                // Edit the contact with new details
                contacts[i].editContact(address, city, state, zip, phone, email);
                cout << "Contact updated successfully!\n";
                return;
            }
        }
        cout << "No contact found with the name: " << name << "\n";
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


    addressBook.displayContacts();

    string nameToEdit;
    cout << "\nEnter the first or last name of the contact to edit: ";
    cin >> nameToEdit;
    addressBook.editContactByName(nameToEdit);

    addressBook.displayContacts();

    return 0;
}
