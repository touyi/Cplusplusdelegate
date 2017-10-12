#include<iostream>
#include"delegatefun.h"

using namespace std;
void fun()
{
	cout << "正常函数" << endl;
}
class A
{
public:
	A();
	~A();
	void fun()
	{
		cout << "成员函数" << endl;
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
	CDelegate e;
	e += newDelegate(fun);
	e += newDelegate(&A(), &A::fun);
	e();
	e-= newDelegate(fun);
	e();
	system("pause");
	return 0;
}