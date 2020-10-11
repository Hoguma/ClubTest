#pragma once
#include "cPlayer.h"

class cBullet;
class cMob;
class cTimer;

class cDororo : public cPlayer
{
private:
	MCI_OPEN_PARMS m_mciOpenParms;
	MCI_PLAY_PARMS m_mciPlayParms;

	MCI_OPEN_PARMS      mciOpen; //파일을 로드
	MCI_PLAY_PARMS       mciPlay; //파일을 재생
	MCI_STATUS_PARMS   mciStatus; //파일의 상태

	DWORD m_dwDeviceID;

	int dwID;
	DWORD startStime;
	texture* m_playerSImage;
	cTimer* m_timer = NULL;

public:
	cDororo(Vec2 pos, vector<cBullet*>& playerBullet);
	~cDororo();

	virtual void Update() override;
	virtual void Render() override;

};

