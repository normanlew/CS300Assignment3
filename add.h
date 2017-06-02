// Norman Lew
// CS 300
// Spring 2017

// Assignment 3
// Question 4

// This function takes two numbers as string paramameters, adds them, and outputs the result.  The addition uses stacks.  One stack holds the
// first number.  The second stack holds the second number.  And the third stack holds the result of the addition.

#include "Stack.h"
using namespace std;

void add(string s, string t)
{
	Stack<int> a(1000);
	Stack<int> b(1000);
	Stack<int> c(1000);

	char x;
	int y, z;
	int sum;
	x = s[0];
	int i = 0;
	bool carryTheOne = false;

	// First, read in the first string character by character, converting each character to an integer and pushing it onto stack a
	while (x != '\0')
	{
		y = x - '0';
		a.push(y);
		i++;
		x = s[i];
	}

	x = t[0];
	i = 0;

	// Next, read in the second string character by character, converting each character to an integer and pushing it onto stack b
	while (x != '\0')
	{
		y = x - '0';
		b.push(y);
		i++;
		x = t[i];
	}

	// Pop from both stacks and add each pair of popped numbers and push the result onto the third stack.  Repeat this until both stack a and b
	// are empty
	while (!a.isEmpty() || !b.isEmpty())
	{
		if (!a.isEmpty())
		{
			if (!b.isEmpty())
			{
				sum = a.pop() + b.pop();
			}
			else
			{
				sum = a.pop();
			}
		}
		else
		{
			sum= b.pop();
		}

		if (carryTheOne)
		{
			sum++;
		}
		z = sum % 10;
		c.push(z);

		if (sum >= 10)
		{
			carryTheOne = true;
		}
		else
		{
			carryTheOne = false;
		}
	}

	if (carryTheOne)
	{
		z = 1;
		c.push(z);
	}


	// Finally, output the result to the screen
	while (!c.isEmpty())
	{
		cout << c.pop();
	}

}
