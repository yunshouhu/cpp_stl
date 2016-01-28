#include <set>
#include <string>
#include <iostream>
#include <functional>
#include <iterator>
using namespace std;

class BigObject
{
public:
	string id;
	explicit BigObject(const string& s) : id(s) {}
	bool operator< (const BigObject& other) const
	{
		return this->id < other.id;
	}
};

inline bool operator<(const string& otherId, const BigObject& obj)
{
	return otherId < obj.id;
}

inline bool operator<(const BigObject& obj, const string& otherId)
{
	return obj.id < otherId;
}
//https://msdn.microsoft.com/zh-CN/library/1fe2x6kt.aspx
int main()
{
	// Use C++14 brace-init syntax to invoke BigObject(string).
	// The s suffix invokes string ctor. It is a C++14 user-defined
	// literal defined in <string>
	BigObject b1{ "42F"s };
	BigObject b2{ "52F"s };
	BigObject b3{ "62F"s };
	set<BigObject, less<>> myNewSet; // C++14
	myNewSet.insert(b1);	
	myNewSet.insert(b3);
	myNewSet.insert(b2);
	auto it = myNewSet.find(string("62F"));
	if (it != myNewSet.end())
		cout << "myNewSet element = " << it->id << endl;
	else
		cout << "element not found " << endl;


	for (it = myNewSet.begin(); it != myNewSet.end(); it++)
	{
		cout << it->id << " ";

	}
	cout << endl;
	

	return 0;
}