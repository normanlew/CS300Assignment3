// Norman Lew
// CS 300
// Spring 2017

// Assignment 3

// Question 3

// This question asks to complete the partial implementation of the QueueStack class.  It is a queue using two internal stacks.


#include <iostream>
#include "Stack.h"
using namespace std;
template <class T>
class QueueStack {
	Stack<T> s1;
	Stack<T> s2;
public:
	void enqueue(T& item);
	T dequeue();
};

// This function performs enqueue.  Stack s1 is the official "queue".  Everytime an element is added to the queue, all elements in s1
// will be popped temporarily to s2.  Then, the new element will be popped into s1.  Finally, all elements in s2 will be moved back over to s1.
template <class T>
void QueueStack<T>::enqueue(T& item) {
	while (!s1.isEmpty())
	{
		s2.push(s1.pop());
	}
	s1.push(item);

	while (!s2.isEmpty())
	{
		s1.push(s2.pop());
	}
}

// This function performs dequeue.  It is simply the top element of stack s1
template <class T>
T QueueStack<T>::dequeue() {
	return s1.pop();
}

