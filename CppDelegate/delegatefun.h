#pragma once
#include"Delegate.h"
#include"NormalDelegate.h"
#include"MemberDelegate.h"
#include"Delegate.h"

template<typename ReturnType,typename...param>
CMDelegate<ReturnType,param...>* newDelegate(ReturnType(*fun)(param...))
{
	return new CNormalDelegate<ReturnType,param...>(fun);
}

template<typename T, typename ReturnType, typename...param>
CMDelegate<ReturnType, param...>* newDelegate(T* object, ReturnType(T::*fun)(param...))
{
	return new CMemberDelegate<T, ReturnType, param...>(object, fun);
}

template<typename T>
CMemberDelegate<T,decltype(&T::operator())>* newDelegate(T& object)
{
	return new CMemberDelegate<T, decltype(&T::operator())>(&object, &T::operator());
}