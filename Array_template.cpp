#include<iostream>
#include"Array_template.h"

using namespace std;
typedef int TYPE;//�ɸ������������



void BubblingSort(Array_template<TYPE>& array);//ð������
void SelectSort(Array_template<TYPE>& array);//ѡ������
void InsertSort(Array_template<TYPE>& array);//��������
void shellSort(Array_template<TYPE>& array);//ϣ������
void MergeSort(Array_template<TYPE>& array);//�鲢����(���׽ӿ�)


void arrayDynamic() 
{
	
	enum {
		NUM = 30,	//�����������ĳߴ�
	};
		
	//���� ��� ��̬����
	Array_template<TYPE> array;		
	srand((unsigned int)time(NULL));
	for (int i = 0; i < NUM; i++){array.addary(rand() % 100);}//%26+65�Ǵ�д��ĸ�ķ�Χ
	array.printez();


#if 0
	//ð������
	BubblingSort(array);

#elif 0
	//ѡ������
	SelectSort(array);

#elif 0
	//��������
	InsertSort(array);

#elif 0
	//ϣ������
	shellSort(array);

#elif 1
	//�鲢����
	MergeSort(array);


#endif
	array.printez();
}


//ð������
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
	cout << "ð������:" << endl;
}
//ѡ������
void SelectSort(Array_template<TYPE>& array)
{
	for (int i = 0; i < array.getcapa() - 1; i++)
	{
		int position = i;
		for (int j = i + 1; j < array.getcapa(); j++)
		{
			if (array[j] < array[position])	 position = j;	//�ҵ���Сλ������
		}
		if (position != i) {			//��Сλ��iλ��λ
			TYPE temp = array[i];
			array[i] = array[position];
			array[position] = temp;
		}
	}
	cout << "ѡ������:" << endl;
}
//��������
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
	cout << "��������:" << endl;
}
//ϣ������
void shellSort(Array_template<TYPE>& array) 
{
	//��������size ȷ��������h�ĳ�ʼֵ
	int h = 1;
	while (h < array.getcapa() / 2) {
		h = 2 * h + 1;
	}
	//ÿhλ Ԫ�ؽ��������� ���в�������
	while (h >= 1)						//���´���������
	{
		//cout << "������h :" << h << "\t0  1  2  3  4  5  6  7  8  9" << endl;
		for (int i = 0; i < h; i++)//�������������� ��������
		{
			if (i + h > array.getcapa() - 1) break;//��һ��ѭ�����ײ���Խ��
			
			int n = 1;//n�� ������index    ʵ��index=a[i]+n*h
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
		h = h / 2;//������h��С����
	}
	cout << "ϣ������:" << endl;
}
//�鲢����  �ϲ����������鲢����
void Merge(Array_template<TYPE>& array, int low, int mid, int high)
{
	// ����ָ��
	int i = low;
	int left = low;
	int right = mid + 1;
	TYPE* assit = new TYPE[array.getcapa()]();
	
	//��������ָ�� Сֵ����assit��ʱ����
	while (left <= mid && right <= high) 
	{
		/*if (array[left] <= array[right]) assit[i++] = array[left++];
		else assit[i++] = array[right++];*/
		(array[left] <= array[right])?(assit[i++] = array[left++]): assit[i++] = array[right++];
	}
	while (left <= mid) {assit[i++] = array[left++];}//������������ʣ���Ԫ��
	while (right <= high) {assit[i++] = array[right++];}//��ת�Ƶ���ʱ������
	
	for (int index = low; index <= high; index++) {
			array[index] = assit[index];
	}
	delete[] assit;
}
//�鲢����   ���������� �ݹ�
void MergeSort(Array_template<TYPE>& array, int low, int high )
{
	if (low >= high) return;
	int mid = (low + high) / 2;
	//���м��п�
	MergeSort(array, low, mid);
	MergeSort(array, mid + 1, high);
	//�����鵥������
	Merge(array, low, mid, high);
}
//�鲢����(�ӿ�)
void MergeSort(Array_template<TYPE>& array)
{
	int low = 0;
	int high = array.getcapa()-1;//��С�������������
	MergeSort(array, low, high);//�Դ�0������������
	cout << "�鲢����:" << endl;
}



