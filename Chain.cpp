#include<iostream>
#include"Chain.h"


Chain* Chain::head = nullptr;

//����תʵ��
void uesChine() {
	//����һ������
	Chain* node = nullptr;

	node->addChain("First paragraph");//��ӳ�ʼԪ�� ͷ�巨
	node->addChain("Second paragraph");
	node->addChain("The third paragraph");
	node->addChain("The fourth paragraph");
	node->addChain("The fifth paragraph");

	node->printChain(); std::cout << std::endl;
	node->flipChain();//��ת����
	node->printChain(); std::cout << std::endl;

	node->deleteChain();

	node->printChain(); std::cout << std::endl;


}



Chain::Chain()
{
	std::cout << "\t\t\tcreate Chine\n";
}

Chain::Chain(std::string data, Chain* next ):data(data),next(next)
{
	std::cout << "\t\t\tcreate Chine with value\n";
}

Chain::~Chain()
{
	std::cout << "\t\t\tdestroy Chine\n";
}

void Chain::addChain( std::string str)
{
	Chain* node = new Chain;
	node->data = str;

	Chain* temp;
	if (Chain::head == nullptr) {
		Chain::head = node;
	}
	else {
		temp = Chain::head;
		Chain::head = node;
		node->next = temp;
	}
}

template <typename 	T>
void printEveryChain(T temp) 
{
	if (temp == nullptr) std::cout << "print : headptr is null\n";
	while (temp != nullptr) {
		std::cout << temp->data << '\n';
		temp = temp->next;
	}
}

void Chain::printChain()
{
	Chain* temp = Chain::head;
	printEveryChain<Chain*>(temp);
}
void Chain::printChain(Chain* head)
{
	Chain* temp = head;
	printEveryChain<Chain*>(temp);
}

void Chain::flipChain()
{
	//�����㷨
	Chain* previous = nullptr;
	Chain* current;
	Chain* temp;
	current = Chain::head;
	while (current != nullptr) {
		temp = current->next; //��һ�� ��λλ��
		current->next = previous;// ��תָ��

		previous = current;//previous��ǰ��
		current = temp;//current��ǰ��
	}
	Chain::head = previous;
}

void Chain::deleteChain()
{
	
	Chain* temp;
	
	while (Chain::head != nullptr)
	{
		temp = Chain::head->next;
		delete Chain::head;
		Chain::head = temp;
	}
}


