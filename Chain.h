#pragma once
#include<string>

class Chain {
public:
	std::string data;//����
	Chain* next = nullptr;//����ָ��
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