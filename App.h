#pragma once

#include <string>

using namespace std;

namespace W3Geek {
	class App {
		public:
			static const string DEFAULT_USER;

			void sayHello(string user = DEFAULT_USER);
	};
}
