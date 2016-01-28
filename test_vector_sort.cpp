// VectorSort.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rectangle
{
	//���id
	int id;
	int length;
	int with;
};
static std::vector<Rectangle> delList;



//�Զ���������
bool SortByM1(const Rectangle &o1, const Rectangle &o2)//ע�⣺�������Ĳ���������һ��Ҫ��vector��Ԫ�ص�����һ��
{
	int ret = 0;
	ret = o1.id - o2.id;
	if (ret == 0)
	{
		ret = o1.length - o2.length;
		if (ret == 0)
		{
			ret = o1.with - o2.with;
			if (ret == 0)
			{
				delList.push_back(o2);
			}
		}
	}
	if (ret != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void MyPushback(std::vector<Rectangle> & vecTest, const int &m1, const int &m2, const int &m3)
{
	Rectangle test;
	test.id = m1;
	test.length = m2;
	test.with = m3;
	vecTest.push_back(test);
}

void PrintVector(std::vector<Rectangle> & vec)
{
	/*
	��һ�䣬
	vec.begin()��Ӧ��λ���������ĵ�һ��λ�ã�
	vec.end()��Ӧ����vector�е�����һ��Ԫ��λ�õĺ����һ��λ�ã�����Ϊ��ʵ������һ����Чλ�ã�
	�ĵ��ϵĶ��壺Returns an iterator referring to the past-the-end element in the vector container.
	*/
	for (std::vector<Rectangle>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << it->id << " " << it->length << " " << it->with << endl;;
	}
}

int main(int argc, char* argv[])
{
	std::vector<Rectangle> vecTest;
	/* sort �Ը����ݴ�������
	MyPushback(vecTest, 1, 1,1);
	MyPushback(vecTest, 1, 1,1);
	MyPushback(vecTest, 1, 2,1);
	MyPushback(vecTest, 1, 1,2);
	*/
	/**
	MyPushback(vecTest,9, 1, 1);
	MyPushback(vecTest, 8, 1, 1);
	MyPushback(vecTest, 8, 2, 1);
	MyPushback(vecTest, 7, 1, 2);
	*/
	//����֮ǰ
	std::cout << "Before Sort:" << std::endl;
	PrintVector(vecTest);

	std::cout << "�������е�����Ԫ�ذ�member1������������:" << std::endl;
	std::sort(vecTest.begin(), vecTest.end(), SortByM1);
	PrintVector(vecTest);


	std::cout << "��delList����:" << std::endl;
	PrintVector(delList);

	return 0;
}
