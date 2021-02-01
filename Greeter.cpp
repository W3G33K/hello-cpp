#include "constants.h"
#include "Greeter.h"

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>

using namespace W3Geek;
using namespace std;

void Greeter::greet() {
	string user = Constants::DEFAULT_USER;
	string *userptr = &user;
	greet(userptr);
}

void Greeter::greet(string *userptr) {
	if (userptr == nullptr) {
		greet();
		return;
	}

	const char* user = (*userptr).c_str();
	const char* format = "Hello, %s!";
	int length = (snprintf(nullptr, 0, format, user) + 1); // Extra space for '\0' (NULL Termination Character)
	if (length <= 0) {
		throw runtime_error("Error occured during formating.");
	}

	char* buffer = new char[length];
	snprintf(buffer, length, format, user);
	string message = string(buffer, (length - 1)); // Remove '\0'
	cout << message << endl;
}
