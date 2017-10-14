#include<iostream>
#include"delegatefun.h"

using namespace std;
int fun(int a)
{
	cout << 2 << endl;
	return 2;
}
class A
{
public:
	A();
	~A();
	int fun(int a)
	{
		cout << 1 << endl;
		return 1;
	}
private:

};

A::A()
{
}

A::~A()
{
}
int main()
{
	CDelegate<int,int> e;
	e += newDelegate(fun);
	e += newDelegate(&A(), &A::fun);
	auto p = [](int a) { cout << 3; return 3; };
	e += newDelegate(p);
	e(5);
	system("pause");
	return 0;
}