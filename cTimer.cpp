#include "DXUT.h"
#include "cTimer.h"


cTimer::cTimer(float Time, function<void()> Func, bool Loop)
	:m_Time(Time * 1000), m_Func(Func), m_Loop(Loop)
{
	m_OldTime = GetTickCount();
	m_CurTime = m_OldTime;
}

cTimer::~cTimer()
{
}

void cTimer::Update()
{
	m_CurTime = GetTickCount();
	if (m_CurTime - m_OldTime >= m_Time)
	{
		m_Func();
		if (m_Loop)
		{
			m_OldTime = GetTickCount();
		}
		else
		{
			delete this;
		}
	}
}