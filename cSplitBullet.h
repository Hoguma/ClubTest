#pragma once
#include "cMobBullet.h"
class cNormalBullet;

class cSplitBullet :
	public cMobBullet
{
private:
	Vec2 vDirection;


	DWORD NowTime;
	DWORD StartTime;
public:
	cSplitBullet(const Vec2& pos, const Vec2& direction, float speed);
	virtual ~cSplitBullet();

	virtual void Update() override;
};

