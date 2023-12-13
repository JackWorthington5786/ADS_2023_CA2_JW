#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\jackw\Documents\AlgorithmsCA\ADS_2023_CA2_JW\ADS_CA2_JackW_XMLFileReader\Tree\Tree.h"
#include "C:\Users\jackw\Documents\AlgorithmsCA\ADS_2023_CA2_JW\ADS_CA2_JackW_XMLFileReader\Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTesting
{
	TEST_CLASS(UnitTesting)
	{
	public:

		TEST_METHOD(TestFileToString)
		{
			string result = fileToString("C:/Users/jackw/Documents/AlgorithmsCA/ADS_2023_CA2_JW/ADS_CA2_JackW_XMLFileReader/Files/test.xml");
			string expected = "<dir>  <name>ADS_Single_LinkedList_Exercises</name> <dir>     <name>.git</name>             <file>            <name>config</name>             <length>353 b</length>                  <type>config</type>           </file>         <file>   <name>description</name>                 <length>73 b</length>           <type>description</type>              </file><file>             <name>HEAD</name>               <length>23 b</length>           <type>HEAD</type>             </file></dir>           <dir>     <name>.vs</name>              <dir>             <name>ADS_Single_LinkedList_Exercises</name> <dir>                      <name>v17</name>                                                      </dir>          </dir> </dir>   <dir>     <name>Debug</name>            <file>            <name>SinglyLinkedList.pdb</name>               <length>978944 b</length>               <type>pdb</type>              </file>         <file>            <name>TestSinglyLinkedList.exp</name>           <length>41528 b</length>                <type>exp</type>              </file>         <file>   <name>TestSinglyLinkedList.pdb</name>            <length>1945600 b</length>              <type>pdb</type>             </file>  </dir>  </dir>";
			Assert::AreEqual(expected, result);
		}
		
		TEST_METHOD(TestIsBalance) 
		{
			string xml = "<xml><a><b><c></c></b><d></d></a></xml>";
			bool result = isBalanced(xml);
			bool expected = true;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestDisplayTree)
		{
			// Create a tree
			file* f = new file("A", 1, "C");

			Tree<file*>* root = new Tree<file*>();
			TreeIterator<string> iter = TreeIterator<string>(root);
			iter.appendChild("A");
			iter.appendChild("B");
			iter.childForth(); 
			iter.down(); 
			iter.appendChild("A1");
			iter.appendChild("A2");
			iter.appendChild("A3");
			iter.childForth(); 
			iter.childForth(); 
			iter.down();
			iter.appendChild("B1");
			iter.appendChild("B2");
			iter.appendChild("B3");
			iter.appendChild("B4");
			iter.root();

			bool result = displayTree(iter,"");
			bool expected = true;
			Assert::AreEqual(expected, result);
		}
	};
}
