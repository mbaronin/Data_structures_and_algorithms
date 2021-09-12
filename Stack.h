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
	void enStack(T data);//��ջ
	T deStack();//��ջ
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
	cout << "ջ��ɾ�����" << endl;
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

	cout << "��ӡջ�� : ";
	Node* temp = first;
	Stack<T>::rprint(temp);
	cout << endl;
}

template <typename T>
void Stack<T>::rprint(Node* temp)  {
	if (temp) {
		rprint(temp->next);//�ȴ�ӡ��node->m_nextΪ�׵������ڴ�ӡ�Լ����������ӡ��.
		cout << temp->data << "  ";
	}
}