#pragma once
#include<string>

class Chain {
public:
	std::string data;//数据
	Chain* next = nullptr;//链表指针
	static Chain* head;

	Chain(std::string data, Chain* next = nullptr);
	Chain();
	~Chain();
	void addChain(std::string str);
	void printChain();
	void printChain(Chain* head);
	void flipChain();
	void deleteChain();
	
};