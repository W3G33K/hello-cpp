#include "App.h"

#include <string>

using namespace W3Geek;
using namespace std;

int main(int argc, char *argv[]) {
	string user = App::DEFAULT_USER;
	if (argc > 1) {
		user = argv[1];
	}

	App app;
	app.sayHello(user);

	return 0;
}
