#include<iostream>
#include"delegatefun.h"

using namespace std;
void fun()
{
	cout << "��������" << endl;
}
class A
{
public:
	A();
	~A();
	void fun()
	{
		cout << "��Ա����" << endl;
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