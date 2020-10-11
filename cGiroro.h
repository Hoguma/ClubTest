#pragma once
#include "cPlayer.h"
class cTimer;
class cDororoBullet;

class cGiroro :
	public cPlayer
{
private:
	cTimer* m_timer = NULL;
public:
	cGiroro(Vec2 pos, vector<cBullet*>& playerBullet);
	virtual ~cGiroro();

	virtual void Update() override;
	virtual void Render() override;
};

