#include "NormalDelegate.h"

CNormalDelegate::~CNormalDelegate()
{
}

void CNormalDelegate::Invoke()
{
	m_Fun();
}

bool CNormalDelegate::compare(CMDelegate * _dele) const
{
	if (_dele == NULL || !_dele->isType(typeid(CNormalDelegate)))return false;
	CNormalDelegate* cast = static_cast<CNormalDelegate*>(_dele);
	return m_Fun == cast->m_Fun;
}
