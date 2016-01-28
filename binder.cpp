#include <iostream>
#include <algorithm>
#include <functional>
#include <list>
#include <iterator>
using namespace std;


int iarray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
list<int> aList(iarray, iarray + 10);

void Display(list<int>& vr, const char *s)
{
	cout << endl << s << endl;
	copy(vr.begin(), vr.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl;
}

//http://net.pku.edu.cn/~yhf/UsingSTL.htm 三十分钟掌握STL
int main()
{
	int k = 0;

	k=count_if(aList.begin(), aList.end(),bind1st(greater<int>(), 8));
	
	cout << "Number elements < 8 == " << k << endl;

	// 移除所有小于4的元素
	aList.erase(std::remove_if(aList.begin(), aList.end(),
		std::bind2nd(std::less< int>(), 4)), aList.end());
	Display(aList, "移除所有小于4的元素后");
	// 移除所有大于6的元素
	aList.erase(std::remove_if(aList.begin(), aList.end(),
		std::bind1st(std::less< int>(), 6)), aList.end());
	Display(aList, "移除所有大于6的元素后");

	return 0;
}