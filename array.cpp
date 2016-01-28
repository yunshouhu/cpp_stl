// array::operator[]
#include <iostream>
#include <array>
void test_at()
{
	std::array<int, 10> myarray;
	// assign some values:
	for (int i = 0; i < 10; i++) 
		myarray.at(i) = i + 1;
	// print content:
	std::cout << "myarray contains:";
	for (int i = 0; i < 10; i++)
		std::cout << ' ' << myarray.at(i);
	std::cout << std::endl;;
}
//http://www.cplusplus.com/reference/array/array/at/
int main()
{
	std::array<int, 10> myarray;
	unsigned int i;

	for (i = 0; i < 10; i++)
		myarray[i] = i;

	std::cout << "myarray contains:";
	for (i = 0; i < 10; i++)
		std::cout << ' ' << myarray[i];
	std::cout << std::endl;
	test_at();
	
	return 0;
}