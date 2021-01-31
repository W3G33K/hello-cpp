#include "App.h"

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>

using namespace W3Geek;
using namespace std;

void App::sayHello(string user) {
	const char *name = user.c_str();
	const char *format = "Hello, %s!";
	int length = (snprintf(nullptr, 0, format, name) + 1); // Extra space for '\0' (NULL Termination Character)
	if (length <= 0) {
		throw runtime_error("Error occured during formating.");
	}

	char *buffer = new char[length];
	snprintf(buffer, length, format, name);
	string message = string(buffer, (length - 1)); // Remove '\0'
	cout << message << endl;
}
