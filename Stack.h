#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Stack
{
	int size = 0;
	class Node {
	public:
		T data = NULL;
		Node* next = nullptr;
	};
	Node* first = nullptr;
public:
	Stack();
	~Stack();
	bool isEmpty();
	int isSize();
	void enStack(T data);//入栈
	T deStack();//出栈
	void printStack();
	void rprint(Node* node);
};

template <typename T>
Stack<T>::Stack() {

}
template <typename T>
Stack<T>::~Stack() {

	while (first != nullptr) {
		Node* temp = first->next;
		delete first;
		first = temp;
	}
	cout << "栈表删除完毕" << endl;
}
template <typename T>
bool Stack<T>::isEmpty() {
	return first == nullptr;
}
template <typename T>
int Stack<T>::isSize() {
	return size;
}
template <typename T>
void Stack<T>::enStack(T data) {

	Node* node = new Node;
	node->data = data;

	if (size != 0) 
		node->next = first;
		
	first = node;

	size++;
}
template <typename T>
T Stack<T>::deStack() {

	if (size != 0) {
		T t = first->data;

		Node* temp = first->next;
		delete first;
		first = temp;

		size--;
		return t;
	}
	else {
		cout << "Stack is no value out";
		return NULL;
	}
}

template <typename T>
void Stack<T>::printStack() {

	cout << "打印栈表 : ";
	Node* temp = first;
	Stack<T>::rprint(temp);
	cout << endl;
}

template <typename T>
void Stack<T>::rprint(Node* temp)  {
	if (temp) {
		rprint(temp->next);//先打印以node->m_next为首的链表，在打印自己就是逆向打印了.
		cout << temp->data << "  ";
	}
}