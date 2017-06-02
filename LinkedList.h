// Norman Lew
// CS 300
// Spring 2017

// Assignment 3
// Questions 1, 2, 6

// The LinkedList.h file was developed in class.  For this assignment, we are making further functionality to it.


#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

template <class T>
struct node{
    T data;
    node<T>* next;
};

template <class T>
class LinkedList{
      protected:
      		node<T> *head, *last;
      		int count;
	  private:
		  void reverseHelper(node<T> *);
      public:
            LinkedList();
            bool is_empty();
            int length();
            void insert_first(T&);
            void insert_last(T&);
			void print();
			T middle();

			T findNth(int);

            template <class U>
            friend ostream& operator<< (ostream& os, LinkedList<U>& list);

			template <class U>
			friend void printLinkedList(LinkedList<U> &c);

			void reverse();

            node<T>* search(T&);
            void delete_node(T&);

            T back();
            T front();
            void destroy_list();
            virtual ~LinkedList();
     private:
     	    void copy_list(LinkedList<T> otherlist);

};

//initializing the list: constructor
template <class T>
LinkedList<T>::LinkedList(){
    //cout<<"Initializing list..."<<endl;
     head = NULL;
     last = NULL;
     count = 0;

}
//check if list is empty
template <class T>
bool LinkedList<T>::is_empty(){
     return head==NULL;
}

//get the number of nodes in the list
template <class T>
int LinkedList<T>::length(){
	return count;
}

//insert a new element to the front
template <class T>
void LinkedList<T>::insert_first(T& item){
     node<T>* current = new node<T>;
     current->data = item;
     current->next = NULL;
     if(head != NULL){
    	 current->next = head;
    	 head = current;
     }else{
    	 head = last = current;
     }
     count++;
}

//insert a new item at the end of the list
template <class T>
void LinkedList<T>::insert_last(T& item){
	node<T>* current = new node<T>;
	current->data = item;
	current->next=NULL;
	if(head != NULL){
        last->next = current;
        last = current;

	}else{
        head=last=current;
	}
    count++;
}

template <class U>
ostream& operator<< (ostream& os, LinkedList<U>& list){
       node<U>* temp = list.head;
       while(temp != NULL){
    	   os<<temp->data<<" ";
    	   temp = temp->next;
       }
       return os;
}

template <class T>
node<T>* LinkedList<T>::search(T& item){
	node<T>* temp = head;
	while(head != NULL && temp->data!=item){
		temp = temp->next;
	}
	return temp;
}

template <class T>
void LinkedList<T>::delete_node(T& item){
	node<T> *p, *q;
	if (head == NULL)
		cout<<"List is empty..."<<endl;
	else
		if(head->data == item){
              p = head;
              head= head->next;
              delete p;
              count--;
              if (head==NULL)
            	  last = NULL;
		}else{
			p= head;
			q = head->next;
			while(q!=NULL && q->data!=item){
				p = q;
				q = q->next;
			}
			if (q==NULL)
				cout<<"item is not found";
			else{
				p->next = q->next;
				if (q->next==NULL)
					last = p;
				delete q;
				count--;

			}

		}

}
template <class T>
T LinkedList<T>::back(){
	assert(last!=NULL);
	return last->data;
}

template <class T>
T LinkedList<T>::front(){
	assert(head!=NULL);
	return head->data;
}
template <class T>
void LinkedList<T>::destroy_list(){
	node<T>* p;
	while(head != NULL){
		p = head;
		head = head->next;
		delete p;
	}
	last = NULL;
	count = 0;
}

//destructor
template <class T>
LinkedList<T>::~LinkedList(){
    cout<<"List is destroyed..."<<endl;
    destroy_list();
}

// Prints the entire linked list
template <class U>
void printLinkedList(LinkedList<U> &c)
{
	c.print();
	cout << endl;
}

template <class T>
void LinkedList<T>::print()
{
	node<T> * tempNode = head;

	while (tempNode != NULL)
	{
		cout << tempNode->data << endl;
		tempNode = tempNode->next;
	}
}

// This function will reverse the linked list.  It utilizes a recursive helper function.
template <class T>
void LinkedList<T>::reverse()
{
	if (head->next != NULL)
	{
		reverseHelper(head);
		head->next = NULL;
	}
	node<T> *temp = head;
	head = last;
	last = temp;
}

// This is the recursive helper function to the reverse function, which reverses the linked list.
template <class T>
void LinkedList<T>::reverseHelper(node<T> *p)
{
	if (p->next != NULL)
	{
		reverseHelper(p->next);
		p->next->next = p;
	}
}

// This function returns the nth element from the end of the list
template <class T>
T LinkedList<T>::findNth(int n)
{
	assert(n <= count && n > 0);
	int c = count - n;
	node<T> *temp = head;
	int i;
	for (i = 0; i < c; i++)
	{
		temp = temp->next;
	}
	return temp->data;
}

// This function returns the middle element from the list
template <class T>
T LinkedList<T>::middle()
{
	node<T> * temp = head;
	int c = count / 2;
	if (count % 2 == 0)
	{
		c = c - 1;
	}

	int i;
	for (i = 0; i < c; i++)
	{
		temp = temp->next;
	}
	return temp->data;
}


#endif /* LINKEDLIST_H_ */
