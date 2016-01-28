// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction(int i, int j) { return (i < j); }

struct myclass {
	bool operator() (int i, int j) { return (i < j); }
} myobject;


int main() {

	int myints[] = { 32,71,12,45,26,80,53,33 };

	std::vector<int> myvector(myints, myints + 8);               // 32 71 12 45 26 80 53 33

	std::sort(myvector.begin(), myvector.begin() + 4);           //(12 32 45 71)26 80 53 33

	std::sort(myvector.begin() + 4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

	std::sort(myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	return 0;
}