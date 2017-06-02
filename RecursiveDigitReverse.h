// Norman Lew
// CS 300
// Spring 2017

// Assignment 3, Question 7

// This function displays the digits of an integer in reverse order

#include <iostream>
using namespace std;

void reverse(int c)
{
	cout << c % 10;
	if (c > 10)
	{
		reverse(c / 10);
	}
	
	
}
