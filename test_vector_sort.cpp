// VectorSort.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rectangle
{
	//编号id
	int id;
	int length;
	int with;
};
static std::vector<Rectangle> delList;



//自定义排序函数
bool SortByM1(const Rectangle &o1, const Rectangle &o2)//注意：本函数的参数的类型一定要与vector中元素的类型一致
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
	插一句，
	vec.begin()对应的位置是向量的第一个位置，
	vec.end()对应的是vector中的最后的一个元素位置的后面的一个位置（我认为，实际上是一个无效位置）
	文档上的定义：Returns an iterator referring to the past-the-end element in the vector container.
	*/
	for (std::vector<Rectangle>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << it->id << " " << it->length << " " << it->with << endl;;
	}
}

int main(int argc, char* argv[])
{
	std::vector<Rectangle> vecTest;
	/* sort 对该数据存在问题
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
	//排序之前
	std::cout << "Before Sort:" << std::endl;
	PrintVector(vecTest);

	std::cout << "对向量中的所有元素按member1进行升序排列:" << std::endl;
	std::sort(vecTest.begin(), vecTest.end(), SortByM1);
	PrintVector(vecTest);


	std::cout << "对delList排列:" << std::endl;
	PrintVector(delList);

	return 0;
}
