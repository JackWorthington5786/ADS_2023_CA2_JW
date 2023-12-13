#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\jackw\Documents\AlgorithmsCA\ADS_2023_CA2_JW\ADS_CA2_JackW_XMLFileReader\Tree\Tree.h"
#include "C:\Users\jackw\Documents\AlgorithmsCA\ADS_2023_CA2_JW\ADS_CA2_JackW_XMLFileReader\Main.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTesting
{
	TEST_CLASS(UnitTesting)
	{
	public:
		
		TEST_METHOD(TestConstructor)
		{
			Tree<int> tree(1);
			Assert::AreEqual(1, tree.data);
			Assert::IsNull(tree.parent);
			Assert::IsNotNull(tree.children);
			Assert::AreEqual(0, tree.children->size());
		}
		TEST_METHOD(isBalanced)
		{
			string dataValid = "<root><a><b></b></a></root>";
			string dataInvalid = "<root><a><b></b></root>";
			Assert::IsTrue(isBalanced(dataValid));
			Assert::IsFalse(isBalanced(dataInvalid));
			
		}
	};
}
