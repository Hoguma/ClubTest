#pragma once
#include "cScene.h"
class cButton;
class cMainScene : public cScene
{
private:
	texture* m_simage;
	texture* m_himage;
	texture* m_eximage;
	texture* m_nimage;
	texture* m_cimage;
	texture* m_background;

	cButton* m_start;
	cButton* m_howto;
	cButton* m_explain;
	cButton* m_next;
	cButton* m_credit;

	texture* m_eximageArr[5];
	texture* m_hbimage;
	texture* m_creimage;

	D3DXVECTOR2 m_bpos;

	bool b_howto;
	bool b_ex;
	bool b_credit;
	int page;
	bool play_once;

	MCI_OPEN_PARMS m_mciOpenParms;
	MCI_PLAY_PARMS m_mciPlayParms;

	MCI_OPEN_PARMS      mciOpen; //파일을 로드
	MCI_PLAY_PARMS       mciPlay; //파일을 재생
	MCI_STATUS_PARMS   mciStatus; //파일의 상태

	DWORD m_dwDeviceID;

	int dwID;

public:
	cMainScene();
	~cMainScene();


	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;
};

