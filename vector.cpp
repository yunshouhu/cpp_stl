#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;


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

void DisplayByAt(vector<int>& myvector)
{
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	cout << endl;
}
void DisplayByOperator(vector<int>& myvector)
{
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];//operator
	cout << endl;
}

void test_vector_data()
{
	std::vector<int> myvector(5);
	//vector=>指针
	int* p = myvector.data();
	*p = 10;
	++p;
	*p = 20;
	p[2] = 100;
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

}
void test_vector_swap()
{
	std::vector<int> foo(3, 100);   // three ints with a value of 100
	std::vector<int> bar(5, 200);   // five ints with a value of 200
	//交换vector数组
	foo.swap(bar);
	std::cout << "foo contains:";
	for (unsigned i = 0; i < foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';
	std::cout << "bar contains:";
	for (unsigned i = 0; i < bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';
}
void test_vector_operator()
{
	std::vector<int> myvector(10);   // 10 zero-initialized elements
	std::vector<int>::size_type sz = myvector.size();
	for (unsigned i = 0; i < sz; i++)
		myvector[i] = i;
	// reverse vector using operator[]:
	for (unsigned i = 0; i < sz / 2; i++)
	{
		int temp;
		temp = myvector[sz - 1 - i]; //operator
		myvector[sz - 1 - i] = myvector[i];
		myvector[i] = temp;
	}
	std::cout << "myvector contains:";
	DisplayByOperator(myvector);
	
}
void test_vector_at()
{
	std::vector<int> myvector(10);   // 10 zero-initialized ints
	for (unsigned i = 0; i < myvector.size(); i++)
		myvector.at(i) = i;
	DisplayByAt(myvector);
}
void test_vector_erase()
{
	std::vector<int> myvector;
	for (int i = 1; i <= 10; i++) 
		myvector.push_back(i);
	myvector.erase(myvector.begin() + 5);
	myvector.erase(myvector.begin(), myvector.begin() + 3);

	std::cout << "myvector contains:";
	DisplayByOperator(myvector);
}
//构造和插入新数据
void test_vector_emplace()
{
	std::vector<int> myvector = { 10,20,30 };
	auto it = myvector.emplace(myvector.begin() + 1, 100);
	myvector.emplace(it, 200);
	myvector.emplace(myvector.end(), 300);

	std::cout << "myvector contains:";
	for (auto & x : myvector)
		std::cout << ' ' << x;
	std::cout << '\n';
}
void test_vector_insert()
{
	std::vector<int> myvector(3, 100); //100 100 100
	std::vector<int>::iterator it;
	it = myvector.begin();
	it = myvector.insert(it, 200);//200 100 100 100
	myvector.insert(it, 2, 300); //300 300 200 100 100 100
	// "it" no longer valid, get a new one:
	it = myvector.begin();

	std::vector<int> anothervector(2, 400);//400 400
	//300 300 400 400 200 100 100 100
	myvector.insert(it + 2, anothervector.begin(), anothervector.end());

	int myarray[] = { 501,502,503 };
	//501 502 503 300 300 400 400 200 100 100 100
	myvector.insert(myvector.begin(), myarray, myarray + 3);
	Display(myvector);
}
void test_vector_assign()
{
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;
	first.assign(7, 100);             // 7 ints with a value of 100

	std::vector<int>::iterator it;
	it = first.begin() + 1;
	second.assign(it, first.end() - 1); // the 5 central values of first
	int myints[] = { 1776,7,4 };
	third.assign(myints, myints + 3);   // assigning from array.

	Display(first);
	Display(second);
	Display(third);
	std::cout << "Size of first: " << int(first.size()) << '\n';
	std::cout << "Size of second: " << int(second.size()) << '\n';
	std::cout << "Size of third: " << int(third.size()) << '\n';
}

void main()
{

	test_vector_data();
	test_vector_swap();
	test_vector_operator();
	test_vector_at();
	test_vector_erase();
	test_vector_emplace();
	test_vector_insert();
	test_vector_assign();

}