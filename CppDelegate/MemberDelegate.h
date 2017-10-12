#pragma once
#include "MDelegate.h"
#include<typeinfo>
template<typename T>
class CMemberDelegate :
	public CMDelegate
{
public:
	typedef void(T::*MFUN)();
	CMemberDelegate(T* object, MFUN fun) :m_object(object), m_fun(fun) {}
	virtual ~CMemberDelegate();
	virtual bool isType(const std::type_info&inf)override { return typeid(CMemberDelegate) == inf; }
	virtual void Invoke() override;
	virtual bool compare(CMDelegate* _dele) const override;
private:
	T* m_object;
	MFUN m_fun;
};

template<typename T>
CMemberDelegate<T>::~CMemberDelegate()
{
}
template<typename T>
void CMemberDelegate<T>::Invoke()
{
	(m_object->*m_fun)();
}
template<typename T>
bool CMemberDelegate<T>::compare(CMDelegate * _dele) const
{
	if (_dele == 0 || !_dele->isType(typeid(CMemberDelegate))) return false;
	CMemberDelegate* cast = static_cast<CMemberDelegate*>(_dele);
	return cast->m_object == m_object && cast->m_fun == m_fun;
}



