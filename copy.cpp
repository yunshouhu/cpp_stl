// name:example2_3.cpp
// alias:aesthetic version

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
void main(void)
{
	typedef vector<int>				int_vector;
	typedef istream_iterator<int>				istream_itr;
	typedef ostream_iterator<int>				ostream_itr;
	typedef back_insert_iterator< int_vector >	back_ins_itr;
	// STL中的vector容器
	int_vector num;

	// 从标准输入设备读入整数， 
	// 直到输入的是非整型数据为止
	copy(istream_itr(cin), istream_itr(), back_ins_itr(num));

	// STL中的排序算法
	sort(num.begin(), num.end());

	// 将排序结果输出到标准输出设备
	copy(num.begin(), num.end(), ostream_itr(cout, "\t"));
}
