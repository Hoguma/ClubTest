#pragma once
#include"cScene.h"

class cTitleScene : public cScene
{
private:
	texture* m_image;
	bool b_click;

	MCI_OPEN_PARMS m_mciOpenParms;
	MCI_PLAY_PARMS m_mciPlayParms;

	MCI_OPEN_PARMS      mciOpen; //������ �ε�
	MCI_PLAY_PARMS       mciPlay; //������ ���
	MCI_STATUS_PARMS   mciStatus; //������ ����

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

