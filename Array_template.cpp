#include<iostream>
#include"Array_template.h"

using namespace std;
typedef int TYPE;//可更改数组的类型



void BubblingSort(Array_template<TYPE>& array);//冒泡排序
void SelectSort(Array_template<TYPE>& array);//选择排序
void InsertSort(Array_template<TYPE>& array);//插入排序
void shellSort(Array_template<TYPE>& array);//希尔排序
void MergeSort(Array_template<TYPE>& array);//归并排序(简易接口)
void QuickSort(Array_template<TYPE>& array);//快速排序

void arrayDynamic() 
{
	
	enum {
		NUM = 30,	//随机生成数组的尺寸
	};
		
	//创建 随机 动态数组
	Array_template<TYPE> array;		
	srand((unsigned int)time(NULL));
	for (int i = 0; i < NUM; i++){array.addary(rand() % 100);}//%26+65是大写字母的范围
	array.printez();


#if 0
	//冒泡排序
	BubblingSort(array);

#elif 0
	//选择排序
	SelectSort(array);

#elif 0
	//插入排序
	InsertSort(array);

#elif 0
	//希尔排序
	shellSort(array);

#elif 0
	//归并排序
	MergeSort(array);
	
#elif 1
	//快速排序
	QuickSort(array);

#endif
	array.printez();
}


//冒泡排序
void BubblingSort(Array_template<TYPE>& array)
{
	for (int i = 0; i < array.getcapa() - 1; i++) {
		for (int j = 0; j < array.getcapa() - 1; j++) {
			if (array[j] > array[j + 1]) {
				TYPE temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	cout << "冒泡排序:" << endl;
}
//选择排序
void SelectSort(Array_template<TYPE>& array)
{
	for (int i = 0; i < array.getcapa() - 1; i++)
	{
		int position = i;
		for (int j = i + 1; j < array.getcapa(); j++)
		{
			if (array[j] < array[position])	 position = j;	//找到最小位的索引
		}
		if (position != i) {			//最小位和i位换位
			TYPE temp = array[i];
			array[i] = array[position];
			array[position] = temp;
		}
	}
	cout << "选择排序:" << endl;
}
//插入排序
void InsertSort(Array_template<TYPE>& array)
{
	for (int i = 1; i < array.getcapa(); i++)
	{
		TYPE temp = array[i];
		int j = i - 1;

		while (j >= 0 && temp < array[j])
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}
	cout << "插入排序:" << endl;
}
//希尔排序
void shellSort(Array_template<TYPE>& array) 
{
	//根据数组size 确定增长量h的初始值
	int h = 1;
	while (h < array.getcapa() / 2) {
		h = 2 * h + 1;
	}
	//每h位 元素建立新数组 进行插入排序
	while (h >= 1)						//重新创建子数组
	{
		//cout << "增长量h :" << h << "\t0  1  2  3  4  5  6  7  8  9" << endl;
		for (int i = 0; i < h; i++)//遍历所有子数组 插入排序
		{
			if (i + h > array.getcapa() - 1) break;//第一轮循环容易产生越界
			
			int n = 1;//n是 子数组index    实际index=a[i]+n*h
			while (i + n * h < array.getcapa())
			{
				TYPE temp = array[i + n * h];
				int j = i + (n - 1) * h;

				while (j >= 0 && temp < array[j])
				{
					array[j + h] = array[j];
					j = j - h;
				}
				array[j + h] = temp;
				n++;
				//array.printez();
			}
		}
		h = h / 2;//增长量h减小规则
	}
	cout << "希尔排序:" << endl;
}
//归并排序  合并左右子数组并排序
void Merge(Array_template<TYPE>& array, int low, int mid, int high)
{
	// 定义指针
	int i = low;
	int left = low;
	int right = mid + 1;
	TYPE* assit = new TYPE[array.getcapa()]();
	
	//遍历左右指针 小值放入assit临时数组
	while (left <= mid && right <= high) 
	{
		/*if (array[left] <= array[right]) assit[i++] = array[left++];
		else assit[i++] = array[right++];*/
		(array[left] <= array[right])?(assit[i++] = array[left++]): assit[i++] = array[right++];
	}
	while (left <= mid) {assit[i++] = array[left++];}//将左右数组中剩余的元素
	while (right <= high) {assit[i++] = array[right++];}//都转移到临时数组中
	
	for (int index = low; index <= high; index++) {
			array[index] = assit[index];
	}
	delete[] assit;
}
//归并排序   创建子数组 递归
void MergeSort(Array_template<TYPE>& array, int low, int high )
{
	if (low >= high) return;
	int mid = (low + high) / 2;
	//从中间切开
	MergeSort(array, low, mid);
	MergeSort(array, mid + 1, high);
	//两个组单独排序
	Merge(array, low, mid, high);
}
//归并排序(接口)
void MergeSort(Array_template<TYPE>& array)
{
	int low = 0;
	int high = array.getcapa()-1;//最小索引和最大索引
	MergeSort(array, low, high);//对从0至最后进行排序
	cout << "归并排序:" << endl;
}
//快速排序  创建子数组 递归
void QuickSort(Array_template<TYPE>& array, int left, int right) 
{
	int i = left, j = right;
	int midindex = array[(left + right) / 2];

	while (i <= j)
	{
		while (array[i] < midindex)i++;//从左到右找到大于等于基准点的元素 
		while (array[j] > midindex)j--;//从右到左找到小于等于基准点的元素

		if (i <= j)//如果i<=j   则互换元素
		{
			TYPE temp;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (left < j) QuickSort(array, left, j);
	if (i < right) QuickSort(array, i, right);
}
//快速排序(接口)
void QuickSort(Array_template<TYPE>& array)
{
	int low = 0;
	int high = array.getcapa() - 1;//最小索引和最大索引
	QuickSort(array, low, high);//对从0至最后进行排序
	cout << "快速排序:" << endl;
}


