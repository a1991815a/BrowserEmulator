#ifndef __UIBASE_H__
#define __UIBASE_H__
#include <windows.h>
#include <string>

#define NS_UI_BEGIN	namespace UI {
#define NS_UI_END	}

NS_UI_BEGIN

class UIBase
{
public:
	UIBase();
	void autorelease();
	void retain();
	void release();
	int getRefrenceCount() const;
protected:
	virtual ~UIBase();
private:
	size_t m_refCount;
};
NS_UI_END
#endif
