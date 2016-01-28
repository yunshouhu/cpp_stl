#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main()
{
	list<int> iList;
	list<int>::iterator p =find(iList.begin(), iList.end(), 2);

	cout << "before: p == " << *p << endl;
	advance(p, 2);  // same as p = p + 2;
	cout << "after : p == " << *p << endl;

	int k = 0;

	distance(p, iList.end(), k);
	cout << "k == " << k << endl;
	return 0;
}