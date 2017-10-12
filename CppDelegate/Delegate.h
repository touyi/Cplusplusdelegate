#pragma once
#include<list>

class CMDelegate;
class CDelegate
{
public:
	CDelegate();
	virtual ~CDelegate();
	CDelegate& operator+=(CMDelegate *);
	CDelegate& operator-= (CMDelegate *);
	void operator()();
private:
	std::list<CMDelegate*>m_delegateList;
};



