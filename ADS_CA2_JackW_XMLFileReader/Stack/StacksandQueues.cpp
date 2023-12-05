// StacksandQueues.cpp : Defines the entry point for the console application.
//
#include "MyStack.h"
#include <iostream>
#include <queue>
#include <string>
using namespace std;

void reverse(int *data, int size)
{
	MyStack<int> nums;
	for (int i = 0; i < size; i++)
	{
		nums.push(data[i]);
	}
	int i = 0;
	while(!nums.isEmpty())
	{
		data[i] = nums.top();
		nums.pop();
		i++;
	}
}

bool isPresent(MyStack<int> &s, int item)
{
	bool found = false;
	queue<int> q;
	for (int i = 0; i < 2; i++)
	{
		while (!s.isEmpty())
		{
			if (s.top() == item)
				found = true;
			q.push(s.top());
			s.pop();
		}
		while (!q.empty())
		{
			s.push(q.front());
			q.pop();
		}
	}
	return found;
}

bool isBalanced(string s)
{
	MyStack<char> stk;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '{' || s[i] == '(' || s[i] == '[')
		{
			stk.push(s[i]);
		}
		else if (s[i] == '}' && stk.top() != '{')
		{
				return false;
		}
		else if (s[i] == ')' && stk.top() != '(')
		{
			return false;
		}
		else if (s[i] == ']' && stk.top() != '[')
		{
			return false;
		}
		else if (s[i] == '}' || s[i] == ']' || s[i] == ')')
		{
			stk.pop();
		}
	}
	return stk.isEmpty();
}

void question4()
{
	string s = "EAS*Y*QUE***ST***IO*N***";
	queue<char> q;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '*')
		{
			cout << q.front();
			q.pop();
		}
		else
		{
			q.push(s[i]);
		}

		
	}
}

struct Shares
{
	int qty;
	double price;
};

void question5()
{
	queue<Shares> q;
	int qty;
	double price;
	string cmd;

	while (true)
	{
		cout << ">";
		cin >> cmd >> qty >> price;
		if (cmd == "buy")
		{
			Shares s;
			s.qty = qty;
			s.price = price;
			q.emplace(s);
		}
		else if (cmd == "sell")
		{
			double profit = 0;
			while (qty > 0)
			{
				if (q.front().qty > qty)
				{
					double profitPerShare = price - q.front().price;
					profit += profitPerShare * qty;
					qty = 0;
					q.front().qty -= qty;
				}
				else
				{
					double profitPerShare = price - q.front().price;
					profit += profitPerShare * q.front().qty;
					qty -= q.front().qty;
					q.pop();
				}
			}
			cout << "Profit Earned " << profit << endl;
		}
	}
}
int main()
{
	/*int *data = new int[10]{1,2,3,4,5,6,7,8,9,10};
	MyStack<int> s;
	reverse(data, 10);
	for (int i = 0; i < 10; i++)
	{
		if (i != 0)
		{
			cout << ", ";
		}
		cout << data[i];
		s.push(data[i]);
	}
	cout << endl;

	s.print();
	cout << isPresent(s, 9)<<endl;
	s.print();


	cout << isBalanced("[({()})]") << endl;
	question4();*/


	question5();
    return 0;
}

