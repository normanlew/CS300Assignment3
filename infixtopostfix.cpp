// Norman Lew
// CS 300
// Spring 2017

// Assignment 3

// This is the solution to Question 5 from Assignment 3.  It reads in an infix expression as a string, converts the expression to postfix,
// outputs the postfix expression, and then calculates the result -- using stacks only.

#include "Stack.h"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	// The charStack holds all the operands typed in by the user
	Stack<char> charStack(1000);

	// The intStack holds all the integers entered in by the user
	Stack<int> intStack(1000);

	char c, d;
	int finalAnswer = 0;
	string expressionInfix;				// This will hold the entire expression as entered in by the user
	char expressionPostfix[1000];		// This will hold the converted, infix to postfix expression entered in by the user
	int postfixCounter = 0;

	cout << "Please enter an expression in infix format." << endl;
	cout << "Also, do not enter any spaces: ";
	cin >> expressionInfix;

	int i = 0;

	cout << "Postfix : ";

	// Perform operations to read the infix expression character by character.  Transform the infix expression into a postfix expression.
	// Output this postfix expression to the screen.  Also, put the postfix expression into an array of characters.
	while (expressionInfix[i] != '\0')
	{
		c = expressionInfix[i];

		switch (c) {
		case '(':
			charStack.push(c);
			i++;
			break;

		case '+':
		case '-':
			while (!charStack.isEmpty())
			{
				if (charStack.stop() != '(')
				{
					d = charStack.pop();
					cout << d << " ";
					expressionPostfix[postfixCounter] = d;
					postfixCounter++;
				}
				else
				{
					break;
				}
			}
			charStack.push(c);
			i++;
			break;

		case '/':
		case '*':
			while (!charStack.isEmpty())
			{
				if (charStack.stop() == '*' || charStack.stop() == '/')
				{
					d = charStack.pop();
					cout << d << " ";
					expressionPostfix[postfixCounter] = d;
					postfixCounter++;
				}
				else
				{
					break;
				}
			}

			charStack.push(c);
			i++;
			break;

			case ')':
				d = charStack.pop();
				while (d != '(')
				{
					cout << d << " ";
					expressionPostfix[postfixCounter] = d;
					postfixCounter++;
					d = charStack.pop();
				}	
				i++;
				break;

			default:
				while (!(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '\0'))
				{
					cout << c;
					expressionPostfix[postfixCounter] = c;
					postfixCounter++;
					i++;
					c = expressionInfix[i];
				}
				expressionPostfix[postfixCounter] = ' ';
				postfixCounter++;
				cout << " ";
		}
	}

	while (!charStack.isEmpty())
	{
		d = charStack.pop();
		expressionPostfix[postfixCounter] = d;
		postfixCounter++;
		cout << d << " ";
	}

	cout << endl;

	// At this point, the infix expression should now be stored in postfix form in the character array expressionPostfix.  
	// Now, we will use the postfix calculator algorithm to read the expressionPostfix array.
	int x, y, z;
	for (i = 0; i < postfixCounter; i++)
	{
		c = expressionPostfix[i];
		
		switch (c) {
		case '+' :
			x = intStack.pop();
			y = intStack.pop();
			z = y + x;
			intStack.push(z);
			break;

		case '-' :
			x = intStack.pop();
			y = intStack.pop();
			z = y - x;
			intStack.push(z);
			break;

		case '/':
			x = intStack.pop();
			y = intStack.pop();
			z = y / x;
			intStack.push(z);
			break;

		case '*':
			x = intStack.pop();
			y = intStack.pop();
			z = y * x;
			intStack.push(z);
			break;
		
		default:
			
			if (c != ' ')
			{
				z = c - '0';
			}
			else
			{
				break;
			}

			while ((i + 1) < postfixCounter)
			{
				c = expressionPostfix[i + 1];
				if (!(c == '+' || c == '/' || c == '*' || c == '-' || c == ' '))
				{
					z = (10 * z) + (c - '0');
					i++;
				}
				else
				{
					break;
				}
			}
			
			intStack.push(z);
		}		
	}

	

	cout << "Value: " << intStack.pop();

	cin.get();
	cin.get();
}