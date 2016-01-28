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

//http://net.pku.edu.cn/~yhf/UsingSTL.htm ��ʮ��������STL
int main()
{
	int k = 0;

	k=count_if(aList.begin(), aList.end(),bind1st(greater<int>(), 8));
	
	cout << "Number elements < 8 == " << k << endl;

	// �Ƴ�����С��4��Ԫ��
	aList.erase(std::remove_if(aList.begin(), aList.end(),
		std::bind2nd(std::less< int>(), 4)), aList.end());
	Display(aList, "�Ƴ�����С��4��Ԫ�غ�");
	// �Ƴ����д���6��Ԫ��
	aList.erase(std::remove_if(aList.begin(), aList.end(),
		std::bind1st(std::less< int>(), 6)), aList.end());
	Display(aList, "�Ƴ����д���6��Ԫ�غ�");

	return 0;
}