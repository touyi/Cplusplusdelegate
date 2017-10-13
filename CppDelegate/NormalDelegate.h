#pragma once
#include "MDelegate.h"
#include<typeinfo>
template<typename ReturnType,typename...param>
class CNormalDelegate :
	public CMDelegate<ReturnType,param...>
{
public:
	typedef ReturnType(*NFUN)(param...);
	CNormalDelegate(NFUN fun) :m_Fun(fun) {}
	virtual ~CNormalDelegate();
	virtual bool isType(const std::type_info &inf) override{ 
		return typeid(CNormalDelegate) == inf;
	}
	virtual ReturnType Invoke(param...par) override;
	virtual bool compare(CMDelegate * _dele) const override;
private:
	NFUN m_Fun;
};

template<typename ReturnType, typename...param>
CNormalDelegate<ReturnType, param...>::~CNormalDelegate()
{
}

template<typename ReturnType, typename...param>
ReturnType CNormalDelegate<ReturnType, param...>::Invoke(param...par)
{
	return m_Fun(par...);
}
template<typename ReturnType, typename...param>
bool CNormalDelegate<ReturnType, param...>::compare(CMDelegate<ReturnType, param...>* _dele) const
{
	if (_dele == NULL || !_dele->isType(typeid(CNormalDelegate)))return false;
	CNormalDelegate* cast = static_cast<CNormalDelegate*>(_dele);
	return m_Fun == cast->m_Fun;
}