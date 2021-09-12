#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Queue
{
	
	int size = 0;
	class Node {
	public:
		T data = NULL;
		Node* next = nullptr;
	};
	Node* first = nullptr;
	Node* last = nullptr;
	int count = 0; //打印对齐用
public:
	Queue();
	~Queue();
	bool isEmpty();
	int isSize();
	void enqueue(T data);//入队
	T dequeue();//出队
	void printQueue();
};

template <typename T>
Queue<T>::Queue(){

}
template <typename T>
Queue<T>::~Queue() {
	
	while (first != nullptr) {
		Node* temp = first->next;
		delete first;
		first = temp;
	}
	cout << "队列删除完毕" << endl;
}
template <typename T>
bool Queue<T>::isEmpty() {
	return first == nullptr;
}
template <typename T>
int Queue<T>::isSize() {
	return size;
}
template <typename T>
void Queue<T>::enqueue(T data) {

	Node* node = new Node;
	node->data = data;

	if (size == 0) {
		first = node;
		last = node;
	}
	else {
		last->next = node;
		last = node;
	}

	size++;
}
template <typename T>
T Queue<T>::dequeue() {
	
	if (size != 0) {
		T t = first->data;
		Node* temp = first->next;
		delete first;
		first = temp;

		size--;
		count++;
		return t;
	}
	else {
		last = nullptr;
		cout << "Queue is no value out" ;
		return NULL;
	}
}

template <typename T>
void Queue<T>::printQueue() {
	Node* temp = first;
	cout << "打印队列 : " ;
	for (int i = 0; i < count;i++) {cout << "    " ;}
		
	

	while (temp != nullptr) {
		cout << temp->data << "   ";
		temp = temp->next;
	}
	cout << endl;
}
