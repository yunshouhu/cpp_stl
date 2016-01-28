#include <iostream>
#include <numeric>      // Need accumulate()
#include <vector>       // Need vector
#include <functional>   // Need multiplies() (or times())
using namespace std;
#define MAX 10
std::vector<long> v(MAX);    // Vector object
int main()
{
	for (int i = 0; i < MAX; i++)
		v[i] = i + 1;
	// Accumulate the sum of contained values
	long sum =accumulate(v.begin(), v.end(), 0);
	cout << "Sum of values == " << sum << endl;

	// Accumulate the product of contained values
	long product =accumulate(v.begin(), v.end(), 1, multiplies<long>());//ע������
	cout << "Product of values == " << product << endl;
	return 0;
}