#include<iostream>
#include"delegatefun.h"

using namespace std;
int fun(int *a)
{
	return 1;
}
class A
{
public:
	A();
	~A();
	int fun(int *a)
	{
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
	CDelegate<int,int*> e;
	e += newDelegate(fun);
	e += newDelegate(&A(), &A::fun);
	int * tt = new int();
	auto temp = e(tt);
	
	e-= newDelegate(fun);
	//e(6);
	system("pause");
	return 0;
}