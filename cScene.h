#pragma once
class cScene abstract
{
public:
	virtual void Init() PURE;
	virtual void Release() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;

	cScene();
	virtual ~cScene();
	//����� ��ų Ŭ������� �Ҹ��ڴ� virtual.
	//�ȱ׷��� 8����Ʈ�� �޸𸮰� ���� ����.
};