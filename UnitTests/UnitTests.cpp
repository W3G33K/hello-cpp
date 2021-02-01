#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <sstream>
#include <string>

#include "..\Greeter.h"

using namespace W3Geek;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTests {
	TEST_CLASS(UnitTests) {
		public:
			TEST_METHOD_INITIALIZE(SetUp) {
				m_prevOutputBuffer = cout.rdbuf(m_testOutputBuffer.rdbuf());
			}

			TEST_METHOD_CLEANUP(TearDown) {
				cout.rdbuf(m_prevOutputBuffer);
			}

			TEST_METHOD(TestGreet) {
				Greeter greeter;
				greeter.greet();

				string expectedOutput = "Hello, world!\n";
				string actualOutput = m_testOutputBuffer.str();

				Assert::AreEqual(expectedOutput, actualOutput);
			}

			TEST_METHOD(TestGreetTodd) {
				string user = "Todd Howard";
				string *userptr = &user;

				Greeter greeter;
				greeter.greet(userptr);

				string expectedOutput = "Hello, Todd Howard!\n";
				string actualOutput = m_testOutputBuffer.str();

				Assert::AreEqual(expectedOutput, actualOutput);
			}

			TEST_METHOD(TestGreetNull) {
				Greeter greeter;
				greeter.greet(nullptr);

				string expectedOutput = "Hello, world!\n";
				string actualOutput = m_testOutputBuffer.str();

				Assert::AreEqual(expectedOutput, actualOutput);
			}
		private:
			stringstream m_testOutputBuffer;
			streambuf* m_prevOutputBuffer;
	};
}
