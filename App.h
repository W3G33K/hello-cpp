#pragma once

#include <string>

using namespace std;

namespace W3Geek {
	class App {
		public:
			void run(int argc = 0, char *argv[] = {});
		private:
			string* _processUser(int argc = 0, char* argv[] = {});
	};
}
