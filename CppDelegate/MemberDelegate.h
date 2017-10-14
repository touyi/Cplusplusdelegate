#pragma once
#include "MDelegate.h"
#include<typeinfo>
/*
* 普通类成员函数模板
*/
template<typename T,typename ReturnType,typename...param>
class CMemberDelegate :
	public CMDelegate<ReturnType,param...>
{
public:
	typedef ReturnType(T::*MFUN)(param...);
	CMemberDelegate(T* object, MFUN fun) :m_object(object), m_fun(fun) {}
	virtual ~CMemberDelegate();
	virtual bool isType(const std::type_info&inf)override { return typeid(CMemberDelegate) == inf; }
	virtual ReturnType Invoke(param...) override;
	virtual bool compare(CMDelegate* _dele) const override;
private:
	T* m_object;
	MFUN m_fun;
};

template<typename T, typename ReturnType, typename...param>
CMemberDelegate<T,ReturnType,param...>::~CMemberDelegate()
{
}
template<typename T, typename ReturnType, typename...param>
ReturnType CMemberDelegate<T, ReturnType, param...>::Invoke(param...par)
{
	return (m_object->*m_fun)(par...);
}
template<typename T, typename ReturnType, typename...param>
bool CMemberDelegate<T, ReturnType, param...>::compare(CMDelegate<ReturnType, param...> * _dele) const
{
	if (_dele == 0 || !_dele->isType(typeid(CMemberDelegate))) return false;
	CMemberDelegate* cast = static_cast<CMemberDelegate*>(_dele);
	return cast->m_object == m_object && cast->m_fun == m_fun;
}

/*
* 特例const限定类成员模板
*/
template<typename T, typename ReturnType, typename...param>
class CMemberDelegate<T, ReturnType(T::*)(param...)const> :
	public CMDelegate<ReturnType, param...>
{
public:
	typedef ReturnType(T::*MFUN)(param...)const;
	CMemberDelegate(T* object, MFUN fun) :m_object(object), m_fun(fun) {}
	virtual ~CMemberDelegate();
	virtual bool isType(const std::type_info&inf)override { return typeid(CMemberDelegate) == inf; }
	virtual ReturnType Invoke(param...) override;
	virtual bool compare(CMDelegate* _dele) const override;
private:
	T* m_object;
	MFUN m_fun;
};

template<typename T, typename ReturnType, typename...param>
CMemberDelegate<T, ReturnType(T::*)(param...)const>::~CMemberDelegate()
{
}
template<typename T, typename ReturnType, typename...param>
ReturnType CMemberDelegate<T, ReturnType(T::*)(param...)const>::Invoke(param...par)
{
	return (m_object->*m_fun)(par...);
}
template<typename T, typename ReturnType, typename...param>
bool CMemberDelegate<T, ReturnType(T::*)(param...)const>::compare(CMDelegate<ReturnType, param...> * _dele) const
{
	if (_dele == 0 || !_dele->isType(typeid(CMemberDelegate))) return false;
	CMemberDelegate* cast = static_cast<CMemberDelegate*>(_dele);
	return cast->m_object == m_object && cast->m_fun == m_fun;
}