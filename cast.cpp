
//C++ 强制类型转换
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
using namespace std;

class A
{
public:
	void show()
	{
		
		cout << "from A" << endl;
	}
	
};
class B :public A
{
public:
	void show()
	{
		cout << "from B" << endl;
	}
};

void test_static_cast()
{
	A *pa = new A();
	pa->show();
	B *pb = static_cast<B*>(pa);
	pa->show();
	B *ppb = new B();
	ppb->show();
	A *ppa = static_cast<A*>(ppb);
	ppb->show();
	
}
class Employee
{
public:
	Employee(){}
	Employee(string inputname):name(inputname)
	{
	}
	virtual   void show()
	{
		cout << "from Employee "<<name << endl;
	}
private:
	string name;
};
class Programmer:public Employee
{
public:
	Programmer()
	{
			
	};
	Programmer(string inputname) :name(inputname)
	{

	}
	void show()
	{
		cout << "from Programmer " << name << endl;
	}
private:
	string name;
};

void test_dynamic_cast()
{
	Employee *pe=new Employee("nanning");
	pe->show();
	Programmer *pm = dynamic_cast<Programmer *>(pe);
	//pm->show();

}
void test_reinterpret_cast()
{
	int i=1024;
	char *p = "Thisisanexample.";
	i = reinterpret_cast<int>(p);
	cout << i << endl;
	cout << p << endl;
}
class BBB
{
	
public:
	int m_iNum;
	void show()
	{
		cout << m_iNum << endl;
	}
};
void test_const_cast()
{
	string data = "hehe";
	char* str = const_cast<char*>(data.c_str());
	cout << str << endl;
	


}
int main()
{	
	test_static_cast();
	test_dynamic_cast();
	test_reinterpret_cast();
	test_const_cast();
	return 0;
}





