#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Contact {
public:
    string firstName, lastName, address, city, state, zip, phoneNumber, email;

    Contact(string fn, string ln, string addr, string cty, string st, string zp, string phone, string em) {
        this->firstName = fn;
        this->lastName = ln;
        this->address = addr;
        this->city = cty;
        this->state = st;
        this->zip = zp;
        this->phoneNumber = phone;
        this->email = em;
    }
    // for displaying the contact
    void display() const {
        cout << "Name: " << firstName << " " << lastName << "\n"
             << "Address: " << address << ", " << city << ", " << state << " - " << zip << "\n"
             << "Phone: " << phoneNumber << "\n"
             << "Email: " << email << "\n";
    }
      // for editing the contacts 
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
    vector<Contact> contacts;    // for storing the list of contacts

public:
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
        cout << "Contact added successfully!\n";
    }

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

    void editContactByName(const string& name) {
        for (int i = 0; i < contacts.size(); ++i) {
            if (contacts[i].firstName == name || contacts[i].lastName == name) {
                cout << "Editing Contact: " << name << "\n";
                string address, city, state, zip, phone, email;

                cout << "Enter new Address: ";
                cin >> address;
                cout << "Enter new City: ";
                cin >> city;
                cout << "Enter new State: ";
                cin >> state;
                cout << "Enter new Zip Code: ";
                cin >> zip;
                cout << "Enter new Phone Number: ";
                cin >> phone;
                cout << "Enter new Email: ";
                cin >> email;

                contacts[i].editContact(address, city, state, zip, phone, email);
                cout << "Contact updated successfully!\n";
                return;
            }
        }
        cout << "No contact found with the name: " << name << "\n";
    }

    void deleteContactByName(const string& name) {
        for (int i = 0; i < contacts.size(); ++i) {
            if (contacts[i].firstName == name || contacts[i].lastName == name) {
                contacts.erase(contacts.begin() + i);
                cout << "Contact deleted successfully!\n";
                return;
            }
        }
        cout << "No contact found with the name: " << name << "\n";
    }
};

int main() {
    map<string, AddressBook> addressBooks;
    string bookName;

    while (true) {
        cout << "\nAddress Book System Menu:\n";
        cout << "1. Add a new Address Book\n";
        cout << "2. Manage an existing Address Book\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the name of the new Address Book: ";
            cin >> bookName;
            if (addressBooks.find(bookName) == addressBooks.end()) {
                addressBooks[bookName] = AddressBook();
                cout << "Address Book \"" << bookName << "\" created successfully!\n";
            } else {
                cout << "Address Book \"" << bookName << "\" already exists!\n";
            }
        } else if (choice == 2) {
            cout << "Enter the name of the Address Book to manage: ";
            cin >> bookName;
            if (addressBooks.find(bookName) == addressBooks.end()) {
                cout << "Address Book \"" << bookName << "\" does not exist!\n";
                continue;
            }

            AddressBook& selectedBook = addressBooks[bookName];
            while (true) {
                cout << "\nManage Address Book: \"" << bookName << "\"\n";
                cout << "1. Add Contact\n";
                cout << "2. Display Contacts\n";
                cout << "3. Edit Contact\n";
                cout << "4. Delete Contact\n";
                cout << "5. Back to Main Menu\n";
                cout << "Choose an option: ";
                int subChoice;
                cin >> subChoice;

                if (subChoice == 1) {
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
                    selectedBook.addContact(newContact);

                } else if (subChoice == 2) {
                    selectedBook.displayContacts();
                } else if (subChoice == 3) {
                    string nameToEdit;
                    cout << "Enter the first or last name of the contact to edit: ";
                    cin >> nameToEdit;
                    selectedBook.editContactByName(nameToEdit);
                } else if (subChoice == 4) {
                    string nameToDelete;
                    cout << "Enter the first or last name of the contact to delete: ";
                    cin >> nameToDelete;
                    selectedBook.deleteContactByName(nameToDelete);
                } else if (subChoice == 5) {
                    break;
                } else {
                    cout << "Invalid option!\n";
                }
            }
        } else if (choice == 3) {
            cout << "Exiting Address Book System. Goodbye!\n";
            break;
        } else {
            cout << "Invalid option!\n";
        }
    }

    return 0;
}
