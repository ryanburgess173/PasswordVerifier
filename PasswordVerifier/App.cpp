/*
	Johnathan R. Burgess
	Advanced C++ Programming
	3/2/2019, Problem #10 from page 850 of the book.
*/

// pre-processor directive
#include <cstring>
#include <iostream>

using namespace std;

// function declarations
bool lengthCheck(char password[30], int minLength);
bool digitCheck(char password[30]);
bool upperLowerCheck(char password[30]);
void testAll(bool pL, bool pD, bool pUL);

int main() {
	// the password can store a maximum of 30 characters
	const int MAX_PWD_LENGTH = 30;

	// password variable
	char *password = nullptr;
	password = new char[MAX_PWD_LENGTH];

	// the minimum password length is set here:
	int minLength = 6;

	// user input
	cout << "Please enter a new password: ";
	cin.getline(password, MAX_PWD_LENGTH);

	// function calls and assignments
	bool passedLength = lengthCheck(password, minLength);
	bool passedDigit = digitCheck(password);
	bool passedUL = upperLowerCheck(password);

	// tests our three variables above ^
	testAll(passedLength, passedDigit, passedUL);

	// clears memory
	delete[] password;
	// pauses the program
	system("pause");
	return 0;
}

bool lengthCheck(char password[30], int minLength) {
	// tests to see if the length of password is greater than or equal to the minLength
	if ((strlen(password))>=minLength) {
		// returns that it is true that the password meets the minimum length requirements
		return true;
	}
	else {
		// otherwise just return that it is false that the password meets the length requirement
		return false;
	}
}

bool digitCheck(char password[30]) {
	// by default we assume that the password doesn't contain a digit
	bool hasDigit = false;

	// loops through each member of our c-string
	for (int i = 0; i < strlen(password); i++) {
		// if the character at this index of our c-string is numerical
		if (isdigit(password[i])) {
			// we say that it is true that the password contains a digit
			hasDigit = true;
			// and there is no need to search further so:
			i = strlen(password);
		}
	}
	return hasDigit;
}
bool upperLowerCheck(char password[30]) {
	// stores whether or not lowercase and uppercase letter exist within our c-string
	bool hasUpper = false;
	bool hasLower = false;

	// loops through each key in password
	for (int i = 0; i < strlen(password); i++) {
		// if the character at that key of password is a letter:
		if (isalpha(password[i])) {
			// if it's uppercase
			if (isupper(password[i])) {
				hasUpper = true;
			}
			// if it's lowercase
			if (islower(password[i])) {
				hasLower = true;
			}
		}
		// if hasUpper and hasLower are true
		if (hasUpper && hasLower) {
			// no reason to continue searching
			i = strlen(password);
		}
	}
	if (hasUpper && hasLower) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(bool pL, bool pD, bool pUL) {
	if (pL) {
		if (pD) {
			if (pUL) {
				cout << "Your password works! Thanks! :)" << endl;
			}
			else {
				cout << "Sorry, your password must contain an uppercase and a lowercase letter." << endl;
			}
		}
		else {
			cout << "Sorry, your password doesn't contain a numerical digit. Try again." << endl;
		}
	}
	else {
		cout << "Sorry, your password doesn't meet the minimum length requirements." << endl;
	}
}