// array::operator[]
#include <iostream>
#include <array>
using namespace std;

template<class Type, size_t _Size>
void Display(std::array<Type,_Size>& vr)
{
	copy(vr.begin(), vr.end(), ostream_iterator<Type>(cout, " "));
	cout << endl;
}


void test_array_at()
{
	std::array<int, 10> myarray;
	// assign some values:
	for (int i = 0; i < 10; i++) 
		myarray.at(i) = i + 1;
	std::cout << "myarray contains:";
	Display(myarray);
}
void test_array_oper()
{
	std::array<int, 10> myarray;
	for (unsigned int i = 0; i < 10; i++)
		myarray[i] = i;
	std::cout << "myarray contains:";
	Display(myarray);
}
void test_std_get()
{
	std::array<int, 3> myarray = { 10, 20, 30 };
	std::tuple<int, int, int> mytuple(10, 20, 30);

	std::tuple_element<0, decltype(myarray)>::type myelement;  // int myelement

	myelement = std::get<2>(myarray);
	std::get<2>(myarray) = std::get<0>(myarray);
	std::get<0>(myarray) = myelement;

	std::cout << "first element in myarray: " << std::get<0>(myarray) << "\n";
	std::cout << "first element in mytuple: " << std::get<0>(mytuple) << "\n";

}
void test_std_tuple_size()
{
	std::tuple<int, char, double> mytuple(10, 'a', 3.14);
	std::cout << "mytuple has ";
	std::cout << std::tuple_size<decltype(mytuple)>::value;
	std::cout << " elements." << '\n';
}

void test_array_data()
{
	const char* cstr = "Test string";
	int len = strlen(cstr)+1;
	cout << len << endl;
	std::array<char, 12> charray;
	std::memcpy(charray.data(), cstr, len);

	std::cout << charray.data() << '\n';
}


//http://www.cplusplus.com/reference/array/array/at/
int main()
{
	test_array_oper();
	test_array_at();
	test_std_get();
	test_std_tuple_size();
	test_array_data();
	return 0;
}