#pragma once
#include"Delegate.h"
#include"NormalDelegate.h"
#include"MemberDelegate.h"
#include"Delegate.h"
CMDelegate* newDelegate(void(*fun)())
{
	return new CNormalDelegate(fun);
}

template<typename T>
CMDelegate* newDelegate(T* object, void(T::*fun)())
{
return new CMemberDelegate<T>(object, fun);
}