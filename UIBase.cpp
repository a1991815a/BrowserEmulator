#include "UIBase.h"
#include <assert.h>

#define AUTO_FLAG 0x80000000
#define REF_FLAG 0x7FFFFFFF

UI::UIBase::UIBase()
	:m_refCount(0)
{

}

UI::UIBase::~UIBase()
{

}

void UI::UIBase::autorelease()
{
	m_refCount |= AUTO_FLAG;
}

void UI::UIBase::retain()
{
	if(m_refCount & AUTO_FLAG)
		++this->m_refCount;
}

void UI::UIBase::release()
{
	if (m_refCount & AUTO_FLAG == 0)
		return;
	assert(m_refCount != 0);
	if (--m_refCount & REF_FLAG == 0)
		delete this;
}

int UI::UIBase::getRefrenceCount() const
{
	return m_refCount & REF_FLAG;
}