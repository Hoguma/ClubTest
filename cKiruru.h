#pragma once
#include "cMob.h"
class cDororo;
class cMobBullet;
class cNormalBullet;
class cXBullet;

class cKiruru : public cMob
{
private:
	cDororo* m_player;

	texture* m_MonsterImage2;

	vector<cMobBullet*>& m_firebullet;

	bool b_spawn;
	int phaseStack;
	bool b_phase;
	int move;
	int oldmove;
	bool b_move;

	DWORD p1p1NowTime;
	DWORD p1p1StartTime;
	DWORD p1p2NowTime;
	DWORD p1p2StartTime;
	DWORD p1p3NowTime;
	DWORD p1p3StartTime;
	DWORD p2p1NowTime;
	DWORD p2p1StartTime;
	DWORD p2p2NowTime;
	DWORD p2p2StartTime;
	DWORD p2p3NowTime;
	DWORD p2p3StartTime;


	Vec2 bulletPos;

public:
	cKiruru(const D3DXVECTOR2& pos, vector<cMobBullet*>& bullet, cDororo* player);
	virtual ~cKiruru();

	virtual void Update() override;
	virtual void Render() override;

	void Phase1Pattern1();

	void Phase1Pattern2();

	void Phase1Pattern3();

	/*void Phase2Pattern1();*/

	void Phase2Pattern2();

	void Phase2Pattern3();

	bool GetSpawn() { return b_spawn; }
	bool Get2Phase() { return b_phase; }
};

