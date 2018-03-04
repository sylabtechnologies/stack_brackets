// brc_balance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

typedef map<char, char> Mypairs;

bool is_balanced(const string& expression, Mypairs& pairs)
{
	stack<char> mystack;

	if (expression.size() < 2) return false;

	// init
	mystack.push(expression[0]);

	for (auto iter = expression.begin() + 1; iter != expression.end(); ++iter)
	{
		char top_char = mystack.top();
		auto test = pairs.find(*iter);

		// seek matching bracket
		if (test != pairs.end())
		{
			if (test->second == top_char)
			{
				mystack.pop();
				continue;
			}
		}

		mystack.push(*iter);
	}

	return mystack.empty();
}

int main()
{
	Mypairs brackets;

	brackets[')'] = '(';
	brackets[']'] = '[';
	brackets['}'] = '{';

	string expression;
	expression = "{[()]}";

	bool answer = is_balanced(expression, brackets);
	if (answer)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}

