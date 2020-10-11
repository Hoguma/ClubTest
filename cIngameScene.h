#pragma once
#include "cScene.h"

class cScroolMap;
class cDororo;
class cBulletAdmin;
class cMobAdmin;
class cCheckColl;

class cIngameScene : public cScene
{
private:
	cScroolMap* m_map;
	cDororo* m_player;
	cBulletAdmin* m_bullet;
	cMobAdmin* m_mob;
	cCheckColl* m_ChCollPM;
public:
	cIngameScene();
	virtual ~cIngameScene();

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;
};

