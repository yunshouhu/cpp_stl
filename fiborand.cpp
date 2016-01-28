#include <iostream>
#include <algorithm>   // Need random_shuffle()
#include <vector>      // Need vector
#include <functional>  // Need unary_function
#include <iterator>

using namespace std;

int iarray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
vector<int> v(iarray, iarray + 10);

void Display(vector<int>& vr, const char *s);

template <class Arg>
class FiboRand : public unary_function<Arg, Arg> {
	int i, j;
	Arg sequence[18];
public:
	FiboRand();
	Arg operator()(const Arg& arg);
};
//http://net.pku.edu.cn/~yhf/UsingSTL.htm
void main()
{
	FiboRand<int> fibogen; 
	cout << "Fibonacci random number generator" << endl;
	cout << "using random_shuffle and a function object" << endl;
	Display(v, "Before shuffle:");
	random_shuffle(v.begin(), v.end(), fibogen);
	Display(v, "After shuffle:");
}

void Display(vector<int>& vr, const char *s)
{
	cout << endl << s << endl;
	copy(vr.begin(), vr.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl;
}

template<class Arg>
FiboRand<Arg>::FiboRand()
{
	sequence[17] = 1;
	sequence[16] = 2;
	for (int n = 15; n > 0; n--)
		sequence[n] = sequence[n + 1] + sequence[n + 2];
	i = 17;
	j = 5;
}

template<class Arg>
Arg FiboRand<Arg>::operator()(const Arg& arg)
{
	Arg k = sequence[i] + sequence[j];
	sequence[i] = k;
	i--;
	j--;
	if (i == 0) i = 17;
	if (j == 0) j = 17;
	return k % arg;
}