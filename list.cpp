#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
#include <string>
using namespace std;

template<class Type>
void Display(list<Type>& vr)
{
	copy(vr.begin(), vr.end(), ostream_iterator<Type>(cout, " "));
	cout << endl;
}
void DisplayByFor(list<int>& mylist)
{
	for (auto & x : mylist)
		std::cout << x << " ";
	cout << endl;
}
void test_list_emplace()
{
	std::list< std::pair<int, char> > mylist;
	mylist.emplace_front(10, 'a');
	mylist.emplace_front(20, 'b');
	mylist.emplace_front(30, 'c');
	std::cout << "mylist contains:";
	for (auto& x : mylist)
		std::cout << " (" << x.first << "," << x.second << ")";
	std::cout << std::endl;

	mylist.emplace(mylist.begin(), 100, 'x');
	mylist.emplace(mylist.end(), 200, 'y');
	for (auto& x : mylist)
		std::cout << " (" << x.first << "," << x.second << ")";
	std::cout << std::endl;
}
void test_list_erase()
{
	std::list<int> mylist;
	std::list<int>::iterator it1, it2;
	for (int i = 1; i < 10; ++i)
		mylist.push_back(i * 10);
	// 10 20 30 40 50 60 70 80 90
	it1 = it2 = mylist.begin();
	//游标指针移动6位
	advance(it2, 6);
	++it1;
	it1 = mylist.erase(it1); // 10 30 40 50 60 70 80 90
	it2 = mylist.erase(it2); // 10 30 40 50 60 80 90
	++it1;
	--it2;
	mylist.erase(it1, it2); // 10 30 60 80 90

	std::cout << "mylist contains:";
	Display(mylist);
}
void test_list_splice()
{
	std::list<int> mylist1, mylist2;
	std::list<int>::iterator it;
	for (int i = 1; i <= 4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4
	for (int i = 1; i <= 3; ++i)
		mylist2.push_back(i * 10);   // mylist2: 10 20 30
	it = mylist1.begin();
	++it;                         // points to 2
	mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
								 // mylist2 (empty) // "it" still points to 2 (the 5th element)
	mylist2.splice(mylist2.begin(), mylist1, it);
	// mylist1: 1 10 20 30 3 4
	// mylist2: 2 // "it" is now invalid.
	it = mylist1.begin();
	std::advance(it, 3);           // "it" points now to 30
	mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
	// mylist1: 30 3 4 1 10 20
	std::cout << "mylist1 contains:";
	Display(mylist1);
	std::cout << "mylist2 contains:";
	Display(mylist2);

}

// a predicate implemented as a function:
bool single_digit(const int& value) { return (value < 10); }
// a predicate implemented as a class:
struct is_odd {
	bool operator() (const int& value) { return (value % 2) == 1; }
};

void test_list_remove()
{
	int myints[] = { 15,36,7,17,20,39,4,1,89 };
	std::list<int> mylist(myints, myints + 9);
	mylist.remove(89);
	mylist.remove_if(single_digit);           // 15 36 17 20 39
	mylist.remove_if(is_odd());               // 36 20
	std::cout << "mylist contains:";
	Display(mylist);
}
// compare only integral part:
bool mycomparison(double first, double second)
{
	return (int(first) < int(second));
}
void test_list_merge()
{
	std::list<double> first, second;
	first.push_back(3.1);
	first.push_back(2.2);
	first.push_back(2.9);
	second.push_back(3.7);
	second.push_back(7.1);
	second.push_back(1.4);

	first.sort();
	second.sort();
	first.merge(second);
	// (second is now empty)
	second.push_back(2.1);
	first.merge(second, mycomparison);
	std::cout << "first contains:";
	Display(first);
}
// a binary predicate implemented as a function:
bool same_integral_part(double first, double second)
{
	return (int(first) == int(second));
}
// a binary predicate implemented as a class:
struct is_near
{
	bool operator() (double first, double second)
	{
		return (fabs(first - second) < 5.0);
	}
};
void test_list_unique()
{
	double mydoubles[] = { 12.15,  2.72, 73.0,  12.77,  3.14,
			12.77, 73.35, 72.25, 15.3,  72.25 };
	std::list<double> mylist(mydoubles, mydoubles + 10);
	mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
							   // 15.3,  72.25, 72.25, 73.0,  73.35
	mylist.unique();           //  2.72,  3.14, 12.15, 12.77
							   // 15.3,  72.25, 73.0,  73.35
	mylist.unique(same_integral_part);  //  2.72,  3.14, 12.15
										// 15.3,  72.25, 73.0

	mylist.unique(is_near());           //  2.72, 12.15, 72.25

	std::cout << "mylist contains:";
	Display(mylist);
}
void test_list_reverse()
{
	std::list<int> mylist;
	for (int i = 1; i < 10; ++i) mylist.push_back(i);
	mylist.reverse();
	Display(mylist);
}
// comparison, not case sensitive.
bool compare_nocase(const std::string& first, const std::string& second)
{
	unsigned int i = 0;
	while ((i < first.length()) && (i < second.length()))
	{
		if (tolower(first[i]) < tolower(second[i])) return true;
		else if (tolower(first[i]) > tolower(second[i])) return false;
		++i;
	}
	return (first.length() < second.length());
}
void test_list_sort()
{
	std::list<std::string> mylist;
	std::list<std::string>::iterator it;
	mylist.push_back("one");
	mylist.push_back("two");
	mylist.push_back("Three");
	mylist.sort();

	std::cout << "mylist contains:";
	Display(mylist);
	mylist.sort(compare_nocase);
	std::cout << "mylist contains:";
	Display(mylist);
}
void test_list_assign()
{
	std::list<int> first;
	std::list<int> second;
	first.assign(7, 100);                      // 7 ints with value 100
	second.assign(first.begin(), first.end()); // a copy of first
	int myints[] = { 1776,7,4 };
	first.assign(myints, myints + 3);            // assigning from array
	std::cout << "Size of first: " << int(first.size()) << '\n';
	std::cout << "Size of second: " << int(second.size()) << '\n';
}
void main()
{
	test_list_emplace();
	test_list_erase();
	test_list_splice();
	test_list_remove();
	test_list_merge();
	test_list_unique();
	test_list_reverse();
	test_list_sort();
	test_list_assign();

}