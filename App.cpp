#include "App.h"
#include "Greeter.h"

#include <string>

using namespace W3Geek;

void App::run(int argc, char* argv[]) {
	string *userptr = _processUser(argc, argv);
	Greeter greeter;
	greeter.greet(userptr);
}

string* App::_processUser(int argc, char* argv[]) {
	string *user = nullptr;
	if (argc > 1) {
		*user = argv[1];
	}

	return user;
}
