#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <string>
#include <cstdlib>
#pragma comment(lib, "winmm.lib")
#include <mmsystem.h>
#include "Digitalv.h"

using namespace std;
using Vec2 = D3DXVECTOR2;

#define g_device DXUTGetD3D9Device()
//���̷�ƮX�� ����̽�(device)��� ������ ����Ѵ�
//�� ����̽��� ���α׷��Ӱ� �׷���ī�带 �����Ҽ� �ִ� ����� �ִ� �༮�̶� �����ϸ� �ȴ�

#ifdef _DEBUG
#define DEBUG_LOG(log) cout << log << endl;
#else
#define DEBUG_LOG(log)
#endif

const int WINSIZEX = 1280;
const int WINSIZEY = 720;



//�Ŵ��� �߰�
#include "cImageManager.h"
#include "cSceneManager.h"
#include "cInputManager.h"
