#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string username, password;

    cout << "Welcome to the Login System!" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;
    cout << "Please select an option: ";

    int option;
    cin >> option;

    if (option == 1) {
        cout << "Enter a username: ";
        cin >> username;

        cout << "Enter a password: ";
        cin >> password;

        while (true) {
            if (password.length() < 8) {
                cout << "Password must be at least 8 characters long. Please try again: ";
                cin >> password;
                continue;
            }

            bool hasSpace = false;
            for (int i = 0; i < password.length(); i++) {
                if (password[i] == ' ') {
                    hasSpace = true;
                    break;
                }
            }

            if (hasSpace) {
                cout << "Password cannot contain spaces. Please try again: ";
                cin >> password;
                continue;
            }

            bool hasUpper = false;
            bool hasLower = false;
            bool hasDigit = false;

            for (int i = 0; i < password.length(); i++) {
                char c = password[i];

                if (c >= 'A' && c <= 'Z')
                    hasUpper = true;

                if (c >= 'a' && c <= 'z')
                    hasLower = true;

                if (c >= '0' && c <= '9')
                    hasDigit = true;
            }

            if (!hasUpper) {
                cout << "Password must contain at least one uppercase letter. Please try again: ";
                cin >> password;
                continue;
            }

            if (!hasLower) {
                cout << "Password must contain at least one lowercase letter. Please try again: ";
                cin >> password;
                continue;
            }

            if (!hasDigit) {
                cout << "Password must contain at least one digit. Please try again: ";
                cin >> password;
                continue;
            }

            break;
        }

        ofstream outFile("users.txt", ios::app);

        if (outFile.is_open()) {
            outFile << username << " " << password << endl;
            outFile.close();
            cout << "Registration successful!" << endl;
        }

    }
    else if (option == 2) {

        cout << "Enter your username: ";
        cin >> username;

        cout << "Enter your password: ";
        cin >> password;

        ifstream inFile("users.txt");
        bool loginSuccess = false;

        if (inFile.is_open()) {
            string fileUsername, filePassword;

            while (inFile >> fileUsername >> filePassword) {
                if (fileUsername == username && filePassword == password) {
                    loginSuccess = true;
                    break;
                }
            }

            inFile.close();
        }

        if (loginSuccess)
            cout << "Login successful!" << endl;
        else
            cout << "Invalid username or password." << endl;
    }
    else if (option == 3) {
        cout << "Exiting the system. Goodbye!" << endl;
    }
    else {
        cout << "Invalid option selected." << endl;
    }

    return 0;
}