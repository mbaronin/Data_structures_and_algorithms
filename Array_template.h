#pragma once
#include<iostream>
using namespace std;

template <typename Item>
class Array_template
{
	Item* m_ary;//指针
	int m_size = 0;//值
	int m_capacity;//容量
public:
	Array_template(int capacity = 0);
	~Array_template();
	void addary(int);//数组添加元素&&扩容
	void setary(int,Item);//数组添加元素&&扩容
	Item& getary(int);//获取数组内的值
	int getcapa();//获取容量
	void print();//打印数组
	void printez();//打印数组
	Item& operator[](int);//运算符重载
};

//创建数组容量
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

//在数组中添加元素
template <typename Item>
void Array_template<Item>::addary(int var) 
{
	if (m_size == m_capacity) {//数组扩容
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

//查看第index位数组的值
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

//获取容量
template <typename Item>
int Array_template<Item>::getcapa() 
{
	return m_capacity;
}

//打印数组
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

//重载调用数组索引
template <typename Item>
Item& Array_template<Item>::operator[](int index) 
{
	return getary(index);
}

//设置第index位数组的值
template <typename Item>
void Array_template<Item>::setary(int index, Item data) 
{
	m_ary[index] = data;
}