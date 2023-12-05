// Trees.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <queue>
#include <string>
#include "Tree.h"
#include "TreeIterator.h"

using namespace std;
/*
	The indented parenthetic representation of a tree
*/
void displayTree(TreeIterator<string> iter, string indent)
{
	cout << indent << iter.node->data ;
	if (iter.childValid())
	{
		cout << "(" <<endl;
	
	while (iter.childValid())
	{
		TreeIterator<string> iter2(iter.childIter.currentNode->data);
		displayTree(iter2, "\t" + indent);
		iter.childForth();
	}
	cout <<indent<< ")" ;
	}
	cout << endl;
}
/*
	Print using a Depth First Search
*/
void printDFS(TreeIterator<string> iter)
{
	while (iter.childValid())
	{
		TreeIterator<string> iter2(iter.childIter.currentNode->data);
		printDFS(iter2);
		iter.childForth();
	}
	cout << iter.item() << ", ";
}
/*
	Print using a Breadth first Search
*/
void printBFS(Tree<string> tree)
{
	queue<Tree<string>> queue;
	queue.push(tree);
	while (!queue.empty())
	{
		DListIterator<Tree<string>*> iter = queue.front().children->getIterator();
		while (iter.isValid())
		{
			queue.push(*iter.item());
			iter.advance();
		}
		cout << queue.front().data << ", ";
		queue.pop();

	}


}