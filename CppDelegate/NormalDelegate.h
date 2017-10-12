#pragma once
#include "MDelegate.h"
#include<typeinfo>
class CNormalDelegate :
	public CMDelegate
{
public:
	typedef void(*NFUN)();
	CNormalDelegate(NFUN fun) :m_Fun(fun) {}
	virtual ~CNormalDelegate();
	virtual bool isType(const std::type_info &inf) override{ 
		return typeid(CNormalDelegate) == inf;
	}
	virtual void Invoke() override;
	virtual bool compare(CMDelegate * _dele) const override;
private:
	NFUN m_Fun;
};