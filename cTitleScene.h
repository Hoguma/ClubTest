#pragma once
#include"cScene.h"

class cTitleScene : public cScene
{
private:
	texture* m_image;
	bool b_click;

	MCI_OPEN_PARMS m_mciOpenParms;
	MCI_PLAY_PARMS m_mciPlayParms;

	MCI_OPEN_PARMS      mciOpen; //파일을 로드
	MCI_PLAY_PARMS       mciPlay; //파일을 재생
	MCI_STATUS_PARMS   mciStatus; //파일의 상태

	DWORD m_dwDeviceID;

	int dwID;

public:
	cTitleScene();
	~cTitleScene();


	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;
};

