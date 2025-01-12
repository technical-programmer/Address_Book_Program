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
        this -> email = em;
    }

    void display() {
        cout << "Name: " << firstName << " " << lastName << "\n"
             << "Address: " << address << ", " << city << ", " << state << " - " << zip << "\n"
             << "Phone: " << phoneNumber << "\n"
             << "Email: " << email << "\n";
    }
};

int main() {
    vector<Contact> contacts;

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

    // Create a Contact object and add it to the vector
    contacts.push_back(Contact(firstName, lastName, address, city, state, zip, phoneNumber, email));

    cout << "Displaying Contact:\n";
    contacts[0].display();

    return 0;
}
