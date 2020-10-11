#pragma once
#include <functional>
class cTimer
{
private:
	float m_Time;
	float m_CurTime;
	float m_OldTime;
	function<void()> m_Func;
	bool m_Loop;
public:
	cTimer(float Time, function<void()> Func, bool Loop = false);
	~cTimer();
	void Update();
};