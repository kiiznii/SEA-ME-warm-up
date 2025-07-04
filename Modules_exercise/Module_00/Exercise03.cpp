#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
public:
    string name;
    string phone;
    string nickname;
    bool bookmarked = false;
};

vector<Contact> phonebook;

void add() {
    Contact c;
    cin >> ws;
    cout << "Enter name: ";
    getline(cin, c.name);
    cout << "Enter phone (unique): ";
    getline(cin, c.phone);
    cout << "Enter nickname: ";
    getline(cin, c.nickname);

    for (auto& p : phonebook) {
        if (p.phone == c.phone) {
            cout << "Phone number already exists.\n";
            return;
        }
    }

    phonebook.push_back(c);
    cout << "Contact added.\n";
}

void search() {
    if (phonebook.empty()) {
        cout << "No contacts available.\n";
        return;
    }

    for (int i = 0; i < phonebook.size(); ++i) {
        cout << i << ": " << phonebook[i].name << endl;
    }

    cout << "Enter index to view: ";
    int index;
    cin >> index;
    cin.ignore();
    if (index >= 0 && index < phonebook.size()) {
        auto& c = phonebook[index];
        cout << "Name: " << c.name << "\n";
        cout << "Phone: " << c.phone << "\n";
        cout << "Nickname: " << c.nickname << "\n";
        cout << "Bookmark this contact? (yes/no): ";
        string ans;
        getline(cin, ans);
        if (ans == "yes") {
            c.bookmarked = true;
            cout << "Contact bookmarked.\n";
        }
    } else {
        cout << "Invalid index.\n";
    }
}

void remove() {
    cout << "Enter index or phone number to remove: ";
    string input;
    getline(cin, input);

    if (isdigit(input[0])) {
        int idx = stoi(input);
        if (idx >= 0 && idx < phonebook.size()) {
            phonebook.erase(phonebook.begin() + idx);
            cout << "Contact removed.\n";
        } else {
            cout << "Invalid index.\n";
        }
    } else {
        for (int i = 0; i < phonebook.size(); ++i) {
            if (phonebook[i].phone == input) {
                phonebook.erase(phonebook.begin() + i);
                cout << "🗑 Contact removed.\n";
                return;
            }
        }
        cout << "Phone number not found.\n";
    }
}

void bookmark() {
    bool found = false;
    for (auto& c : phonebook) {
        if (c.bookmarked) {
            cout << "Name: " << c.name << ", Phone: " << c.phone << ", Nickname: " << c.nickname << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << " No bookmarked contacts.\n";
    }
}

int main() {
    string cmd;
    cout << "Phonebook started. Type a command: ADD, SEARCH, REMOVE, BOOKMARK, EXIT\n";
    while (true) {
        cout << "\n> ";
        getline(cin, cmd);
        if (cmd == "ADD") add();
        else if (cmd == "SEARCH") search();
        else if (cmd == "REMOVE") remove();
        else if (cmd == "BOOKMARK") bookmark();
        else if (cmd == "EXIT") break;
        else cout << "Unknown command.\n";
    }

    cout << "Program ended.\n";
    return 0;
}
