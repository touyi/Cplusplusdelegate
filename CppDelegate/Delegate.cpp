#include "Delegate.h"
#include"NormalDelegate.h"
#include"MemberDelegate.h"
#include"MDelegate.h"

CDelegate::CDelegate()
{
}


CDelegate::~CDelegate()
{
	auto it = m_delegateList.begin();
	while (it!= m_delegateList.end())
	{
		if ((*it) != NULL)
		{
			delete (*it);
		}
	}
	m_delegateList.clear();
}

CDelegate & CDelegate::operator+=(CMDelegate *_dele)
{
	if (_dele == NULL)
		return *this;
	for (auto it = m_delegateList.begin(); it != m_delegateList.end(); it++)
	{
		if ((*it)->compare(_dele))
		{
			return *this;
		}
	}
	m_delegateList.push_back(_dele);
}

CDelegate & CDelegate::operator-=(CMDelegate * _dele)
{
	auto it = m_delegateList.begin();
	while (it != m_delegateList.end())
	{
		if ((*it)->compare(_dele))
		{
			delete *it;
			it = m_delegateList.erase(it);
		}
		else
		{
			it++;
		}
	}
	return *this;
}

void CDelegate::operator()()
{
	for (auto it = m_delegateList.begin(); it != m_delegateList.end(); it++)
	{
		(*it)->Invoke();
	}
}


