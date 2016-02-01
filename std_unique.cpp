// unique algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::unique, std::distance
#include <vector>       // std::vector
#include <iterator>
using namespace std;

bool myfunction(int i, int j) {
	return (i == j);
}
void Display(vector<int>& vr)
{
	copy(vr.begin(), vr.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}


int main() {
	int myints[] = { 10,20,20,20,30,30,20,20,10 };           // 10 20 20 20 30 30 20 20 10
	std::vector<int> myvector(myints, myints + 9);
	// using default comparison:
	std::vector<int>::iterator it;
	Display(myvector);

	//����ȥ���ظ��ķ�Χ 
	//ɾ������һ��Ԫ�ش�ÿ�������ĵȼ�Ԫ�ط�Χ(��һ,���)�� 
	it = std::unique(myvector.begin(), myvector.end());   // 10 20 30 20 10 ?  ?  ?  ?

	myvector.erase(it, myvector.end());

	Display(myvector);

	//myvector.resize(std::distance(myvector.begin(), it)); // 10 20 30 20 10
	//Display(myvector);

	std::unique(myvector.begin(), myvector.end(), myfunction);   // (no changes)

	Display(myvector);

	return 0;
}
