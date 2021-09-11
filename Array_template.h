#pragma once
#include<iostream>
using namespace std;

template <typename Item>
class Array_template
{
	Item* m_ary;//ָ��
	int m_size = 0;//ֵ
	int m_capacity;//����
public:
	Array_template(int capacity = 0);
	~Array_template();
	void addary(int);//�������Ԫ��&&����
	void setary(int,Item);//�������Ԫ��&&����
	Item& getary(int);//��ȡ�����ڵ�ֵ
	int getcapa();//��ȡ����
	void print();//��ӡ����
	void printez();//��ӡ����
	Item& operator[](int);//���������
};

//������������
template <typename Item>
Array_template<Item>::Array_template(int capacity) 
{
	m_capacity = capacity <= 0 ? 5 : capacity;
	m_ary = new Item[m_capacity]{ 0 };
	cout << "Creation completed, array capacity is: " << m_capacity << "\t\tNumber of elements: " << m_size << endl;
}

template <typename Item>
Array_template<Item>::~Array_template() 
{
	cout << "Array destroy completed" << endl;
	if (m_ary == NULL) return;
	delete[] m_ary;
	m_ary = NULL;
}

//�����������Ԫ��
template <typename Item>
void Array_template<Item>::addary(int var) 
{
	if (m_size == m_capacity) {//��������
		Item* temp = m_ary;
		m_ary = new Item[++m_capacity]{ 0 };
		cout << "Capacity expanded to" << m_capacity << endl;
		for (int i = 0; i < m_capacity; i++) 
		{
			m_ary[i] = temp[i];
		}
		delete temp;
	}
	m_ary[m_size++] = var;
}

//�鿴��indexλ�����ֵ
template <typename Item>
Item& Array_template<Item>::getary(int index) 
{
	if (index >= 0 && index < m_capacity) 
	{
		//cout << m_ary[index] << endl;
		return m_ary[index];
	}
	else cout << "error : Index exceeds array capacity" << endl;
	return m_ary[0];
}

//��ȡ����
template <typename Item>
int Array_template<Item>::getcapa() 
{
	return m_capacity;
}

//��ӡ����
template <typename Item>
void Array_template<Item>::print() 
{
	cout << "print:" << endl;
	for (int i = 0; i < m_capacity; i++) 
	{
		cout << "array[" << i << "] = " << m_ary[i] << endl;
	}
}

template<typename Item>
inline void Array_template<Item>::printez()
{
	cout  << "printez:\t" ;
	for (int i = 0; i < m_capacity; i++)
	{
		cout  << m_ary[i] << ' ' ;
	}
	cout << endl; 
}

//���ص�����������
template <typename Item>
Item& Array_template<Item>::operator[](int index) 
{
	return getary(index);
}

//���õ�indexλ�����ֵ
template <typename Item>
void Array_template<Item>::setary(int index, Item data) 
{
	m_ary[index] = data;
}