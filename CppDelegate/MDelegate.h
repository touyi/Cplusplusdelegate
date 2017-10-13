#pragma once
template<typename ReturnType,typename...param>
class CMDelegate
{
public:
	CMDelegate() {};
	virtual ~CMDelegate() {};
	virtual bool isType(const type_info &inf) = 0;
	virtual ReturnType Invoke(param...) = 0;
	virtual bool compare(CMDelegate<ReturnType,param...> * _dele) const = 0;
};

