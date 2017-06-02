#include <iostream>
#include <assert.h>
using namespace std;

#ifndef STACK_H_
#define STACK_H_

template <class T>
class Stack {
private:
	T *arr;
	int size;
	int top;
public:
	Stack(int);
	bool isEmpty();
	bool isFull();
	void push(T&);
	T pop();
	T stop();
	void destroy();
	void copy(Stack<T>&);
	~Stack();
};

template <class T>
Stack<T>::Stack(int _size) {
	size = _size;
	arr = new T[size];
	top = 0;
}

template <class T>
bool Stack<T>::isEmpty() {
	return top == 0;
}

template <class T>
bool Stack<T>::isFull() {
	return size == top;
}
template <class T>
void Stack<T>::push(T& item) {
	if (!isFull())
		arr[top++] = item;
	else
		cout << "Stack overflow!" << endl;
}
template <class T>
T Stack<T>::pop() {
	assert(!isEmpty());
	return arr[--top];
}
template <class T>
T Stack<T>::stop() {
	assert(!isEmpty());
	return arr[top - 1];
}

template <class T>
void Stack<T>::destroy() {
	top = 0;
}

template <class T>
void Stack<T>::copy(Stack<T>& anotherSt) {
	delete[] arr;
	size = anotherSt.size;
	top = anotherSt.top;
	arr = new T[size];
	for (int i = 0; i<top; i++)
		arr[i] = anotherSt.arr[i];

}
template <class T>
Stack<T>::~Stack() {
	delete[] arr;
}


#endif /* STACK_H_ */

