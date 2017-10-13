#pragma once
#include<list>
#include"MDelegate.h"
template<typename ReturnType, typename...Param>
class CMDelegate;
/*
* 普通模板 试用与返回值不是void
*/
template<typename ReturnType,typename...Param>
class CDelegate
{
public:
	CDelegate();
	virtual ~CDelegate();
	CDelegate& operator+=(CMDelegate<ReturnType, Param...> *);
	CDelegate& operator-= (CMDelegate<ReturnType, Param...> *);
	std::list<ReturnType>& operator()(Param...par);
private:
	CDelegate(CDelegate&);
	CDelegate& operator=(const CDelegate&) {};
	std::list<CMDelegate<ReturnType, Param...>*>m_delegateList;
	std::list<ReturnType>m_ReturnList;
};

template<typename ReturnType, typename...Param>
CDelegate<ReturnType, Param...>::CDelegate()
{
}

template<typename ReturnType, typename...Param>
CDelegate<ReturnType, Param...>::~CDelegate()
{
	auto it = m_delegateList.begin();
	while (it != m_delegateList.end())
	{
		if ((*it) != NULL)
		{
			delete (*it);
		}
	}
	m_delegateList.clear();
}

template<typename ReturnType, typename...Param>
CDelegate<ReturnType, Param...> & CDelegate<ReturnType, Param...>::operator+=(CMDelegate<ReturnType, Param...> *_dele)
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
	return *this;
}

template<typename ReturnType, typename...Param>
CDelegate<ReturnType, Param...> & CDelegate<ReturnType, Param...>::operator-=(CMDelegate<ReturnType, Param...> * _dele)
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

template<typename ReturnType, typename...Param>
std::list<ReturnType>& CDelegate<ReturnType, Param...>::operator()(Param...par)
{
	for (auto it = m_delegateList.begin(); it != m_delegateList.end(); it++)
	{
		m_ReturnList.push_back((*it)->Invoke(par...));
	}
	return m_ReturnList;
}



/*
* 特例模板 返回值是void
*/
template<typename...Param>
class CDelegate<void,Param...>
{
public:
	CDelegate();
	virtual ~CDelegate();
	CDelegate& operator+=(CMDelegate<void,Param...> *);
	CDelegate& operator-= (CMDelegate<void,Param...> *);
	void operator()(Param...);
private:
	CDelegate(CDelegate&);
	CDelegate& operator=(const CDelegate&) {};
	std::list<CMDelegate<void,Param...>*>m_delegateList;
	//std::list<ReturnType>m_ReturnList;
};

template<typename...Param>
CDelegate<void, Param...>::CDelegate()
{
}

template<typename...Param>
CDelegate<void, Param...>::~CDelegate()
{
	auto it = m_delegateList.begin();
	while (it != m_delegateList.end())
	{
		if ((*it) != NULL)
		{
			delete (*it);
		}
	}
	m_delegateList.clear();
}

template<typename...Param>
CDelegate<void, Param...> & CDelegate<void, Param...>::operator+=(CMDelegate<void, Param...> *_dele)
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

template<typename...Param>
CDelegate<void, Param...> & CDelegate<void, Param...>::operator-=(CMDelegate<void, Param...> * _dele)
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

template<typename...Param>
void CDelegate<void, Param...>::operator()(Param...par)
{
	for (auto it = m_delegateList.begin(); it != m_delegateList.end(); it++)
	{
		(*it)->Invoke(par);
	}
}














