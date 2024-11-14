#include "pch.h"
#include "CppUnitTest.h"
#include "../орпав/Source.cpp"

struct Str {
	int math_mark;
	int phis_mark;
	int inf_mark;
};

Str s1{ 5, 4, 2 };
Str s2{ 3, 1, 4 };
Str s3{ 2, 2, 5 };

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n = 3;
			student* s = new student[n];
			int result = Ast_Phisics(s, n);
			int expected = 1;
			Assert::AreEqual(expected, result);
		}
	};
}
