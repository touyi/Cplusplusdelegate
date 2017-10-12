#pragma once
class CMDelegate
{
public:
	CMDelegate();
	virtual ~CMDelegate();
	virtual bool isType(const type_info &inf) = 0;
	virtual void Invoke() = 0;
	virtual bool compare(CMDelegate * _dele) const = 0;
};

