#pragma once
#include "cBulletAdmin.h"
class cDororo;
class cMobBullet;
class cMob;

class cMobAdmin
{
private:
	MCI_OPEN_PARMS m_mciOpenParms;
	MCI_PLAY_PARMS m_mciPlayParms;

	MCI_OPEN_PARMS      mciOpen; //파일을 로드
	MCI_PLAY_PARMS       mciPlay; //파일을 재생
	MCI_STATUS_PARMS   mciStatus; //파일의 상태

	DWORD m_dwDeviceID;

	int dwID;

	MCI_OPEN_PARMS m_mciOpenParms1;
	MCI_PLAY_PARMS m_mciPlayParms1;

	MCI_OPEN_PARMS      mciOpen1; //파일을 로드
	MCI_PLAY_PARMS       mciPlay1; //파일을 재생
	MCI_STATUS_PARMS   mciStatus1; //파일의 상태

	DWORD m_dwDeviceID1;

	int dwID1;

	vector<cMob*> m_mobList;
	cBulletAdmin* m_bulletAdmin;
	cDororo* m_player;
	texture* m_gameover;
	texture* m_UI;
	texture* m_Hit;
	texture* m_Clear;

	DWORD HitNowTime;
	DWORD HitStartTime;

	bool b_Phase2;
	bool b_boss;
	bool b_bossdead;
	bool PlayOnce;
	bool play_once;
	bool b_hit;
	bool play_Once;
	int pHp;
	int pMHp;
	float m_pSpeed;
	int damage;
	bool b_coll = false;
	int inputscore;
	int score;
	bool once;
	bool isBossDead;
private:
	void CheckMonsterCollider();
	void Reset();
	void CreateBoss();
public:
	cMobAdmin(cBulletAdmin* bullet, cDororo* player);
	~cMobAdmin();

	void CreatMonster();

	DWORD InvisibleStartTime;
	DWORD InvisibleNowTime;
	DWORD NormalStartTime;
	DWORD NormalNowTime;
	DWORD BulletStartTime;
	DWORD BulletNowTime;

	DWORD slowStartTime;
	DWORD slowNowTime;
	/*DWORD StartTime;
	DWORD NowTime;*/

	void Init();
	void Update();
	void Render();
	void Release();


};

