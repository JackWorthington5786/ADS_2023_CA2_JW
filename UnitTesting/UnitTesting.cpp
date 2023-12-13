#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTesting
{
	TEST_CLASS(Main)
	{
	public:
		
		TEST_METHOD(isBalanced)
		{
			string ValidXMLString = "<root><child1></child1><child2></child2></root>";
			Assert::IsEqual(true, isBalanced(ValidXMLString));

		}
	};
}
