#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <sstream>
#include <string>

#include "..\App.h"

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

			TEST_METHOD(TestItJustWorks) {
				Assert::AreNotEqual(true, false);
			}

			TEST_METHOD(TestHello) {
				App app;
				app.sayHello();

				string expectedOutput = "Hello, world!\n";
				string actualOutput = m_testOutputBuffer.str();

				Assert::AreEqual(expectedOutput, actualOutput);
			}

			TEST_METHOD(TestHelloTodd) {
				App app;
				app.sayHello("Todd Howard");

				string expectedOutput = "Hello, Todd Howard!\n";
				string actualOutput = m_testOutputBuffer.str();

				Assert::AreEqual(expectedOutput, actualOutput);
			}
		private:
			stringstream m_testOutputBuffer;
			streambuf* m_prevOutputBuffer;
	};
}
