#pragma once

#include "constants.h"

#include <string>

using namespace std;

namespace W3Geek {
	class Greeter {
		public:
			void greet();
			void greet(string *user);
	};
}
