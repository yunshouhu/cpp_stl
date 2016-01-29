// transform algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <functional>   // std::plus
#include <iterator>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using namespace std;

int op_increase(int i) { return ++i; }
bool IsOdd(int i) { return ((i % 2) == 1); }

void Display(vector<int>& vr, const char *s)
{
	cout << endl << s << endl;
	copy(vr.begin(), vr.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}
void Display(vector<int>& vr)
{
	copy(vr.begin(), vr.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

void test_std_transform()
{
	std::vector<int> foo;
	std::vector<int> bar;
	for (int i = 1; i < 6; i++)
		foo.push_back(i * 10); // foo: 10 20 30 40 50
	bar.resize(foo.size());  // allocate space
	std::transform(foo.begin(), foo.end(), bar.begin(), op_increase);// bar: 11 21 31 41 51
	 // std::plus adds together its two arguments:
	std::transform(foo.begin(), foo.end(), bar.begin(), foo.begin(), std::plus<int>());// foo: 21 41 61 81 101
	std::cout << "foo contains:";
	Display(foo);
}

void test_std_find()
{
	std::vector<int> intVector(100);
	intVector[20] = 50;
	vector<int>::iterator intIter = std::find(intVector.begin(), intVector.end(), 50);
	if (intIter != intVector.end())
		cout << "Vector contains value " << *intIter << endl;
	else
		cout << "Vector does not contain 50" << endl;

	std::vector<int> myvector;
	myvector.push_back(10);
	myvector.push_back(25);
	myvector.push_back(40);
	myvector.push_back(55);
	std::vector<int>::iterator it = std::find_if(myvector.begin(), myvector.end(), IsOdd);
	std::cout << "The first odd value is " << *it << '\n';
}
void test_std_replace()
{
	int myints[] = { 10, 20, 30, 30, 20, 10, 10, 20 };
	std::vector<int> myvector(myints, myints + 8);            // 10 20 30 30 20 10 10 20
	std::replace(myvector.begin(), myvector.end(), 20, 99); // 10 99 30 30 99 10 10 99
	std::cout << "myvector contains:";
	Display(myvector);
}


void test_std_replace_if()
{
	std::vector<int> myvector;
	for (int i = 1; i < 10; i++)
		myvector.push_back(i);               // 1 2 3 4 5 6 7 8 9
	std::replace_if(myvector.begin(), myvector.end(), IsOdd, 1024); // 0 2 0 4 0 6 0 8 0

	std::cout << "myvector contains:";
	Display(myvector);

}

void myfunction(int i) {  // function:
	std::cout << ' ' << i;
}

struct myclass {
	// for_each实现函数
	void operator() (int i) { std::cout << ' ' << i; }
} myobject;

void test_std_for_each()
{
	std::vector<int> myvector;
	myvector.push_back(10);
	myvector.push_back(20);
	myvector.push_back(30);
	std::cout << "myvector contains:";
	for_each(myvector.begin(), myvector.end(), myfunction);
	std::cout << '\n';

	std::cout << "myvector contains:";
	for_each(myvector.begin(), myvector.end(), myobject);
	std::cout << '\n';
}

void test_std_remove()
{
	int myints[] = { 1,2,3,4,5,6,7,8,9 };            // 1 2 3 4 5 6 7 8 9
	int* pbegin = myints;
	int* pend = myints + sizeof(myints) / sizeof(int);
	pend = std::remove_if(pbegin, pend, IsOdd);
	std::cout << "the range contains:";
	for (int* p = pbegin; p != pend; ++p)
		std::cout << ' ' << *p;
	std::cout << '\n';

	pend = std::remove(pbegin, pend, 8);
	for (int* p = pbegin; p != pend; ++p)
		std::cout << ' ' << *p;
	std::cout << '\n';
}
void test_stl_copy()
{
	int myints[] = { 10,20,30,40,50,60,70 };
	std::vector<int> myvector(7);
	std::copy(myints, myints + 7, myvector.begin());
	std::cout << "myvector contains:";
	Display(myvector);

}
void test_std_count()
{
	int myints[] = { 10,20,30,3,20,10,10,20 };   // 8 elements
	int mycount = std::count(myints, myints + 8, 10);
	std::cout << "10 appears " << mycount << " times.\n";

	std::vector<int> myvector(myints, myints + 8);
	mycount = std::count(myvector.begin(), myvector.end(), 20);
	std::cout << "20 appears " << mycount << " times.\n";

	mycount = std::count_if(myvector.begin(), myvector.end(), IsOdd);
	std::cout << "myvector contains " << mycount << " odd values.\n";
}
void test_std_remove_copy()
{
	int myints[] = { 10,20,30,30,20,10,10,20 };               // 10 20 30 30 20 10 10 20
	std::vector<int> myvector(8);
	//把符合条件的移到后面
	std::remove_copy(myints, myints + 8, myvector.begin(), 20); // 10 30 30 10 10 0 0 0

	std::cout << "myvector contains:";
	Display(myvector);
	std::replace_copy(myints, myints + 8, myvector.begin(), 10, 99);
	Display(myvector);


	std::vector<int> foo, bar;
	for (int i = 1; i < 10; i++)
		foo.push_back(i);          // 1 2 3 4 5 6 7 8 9
	bar.resize(foo.size());   // allocate space
	std::replace_copy_if(foo.begin(), foo.end(), bar.begin(), IsOdd, 0);// 0 2 0 4 0 6 0 8 0
	std::cout << "bar contains:";
	Display(bar);
}
void test_std_fill()
{
	std::vector<int> myvector(8); // myvector: 0 0 0 0 0 0 0 0
	std::fill(myvector.begin(), myvector.begin() + 4, 5);   // myvector: 5 5 5 5 0 0 0 0
	std::fill(myvector.begin() + 3, myvector.end() - 2, 8);   // myvector: 5 5 5 8 8 8 0 0

	std::cout << "myvector contains:";
	Display(myvector);
}

// function generator:
int RandomNumber() { return (std::rand() % 100); }

// class generator:
struct c_unique {
	int current;
	c_unique() { current = 0; }
	int operator()() { return ++current; }
} UniqueNumber;

int current = 10;
int MyUniqueNumber() { return ++current; }

void test_std_generate()
{
	std::srand(unsigned(std::time(0)));
	std::vector<int> myvector(8);

	std::generate(myvector.begin(), myvector.end(), RandomNumber);
	std::cout << "myvector contains:";
	Display(myvector);

	std::generate(myvector.begin(), myvector.end(), UniqueNumber);

	std::cout << "myvector contains:";
	Display(myvector);

	int myarray[9];
	std::generate_n(myarray, 9, MyUniqueNumber);
	std::cout << "myarray contains:";
	for (int i = 0; i < 9; ++i)
		std::cout << ' ' << myarray[i];
	std::cout << '\n';
}

int main() {

	test_std_find();
	test_std_replace();
	test_std_replace_if();
	test_std_for_each();
	test_std_transform();
	test_std_remove();
	test_stl_copy();
	test_std_count();
	test_std_remove_copy();
	test_std_fill();
	test_std_generate();
	return 0;
}