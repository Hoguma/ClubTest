	#pragma once

//�̱����̶� Ŭ������ ���������� ����ϰ� ����� �ִ°��� �ǹ��Ѵ�.
template <typename T>
class singleton
{
private:
	//Ŭ���� ���� ������ static�� ����ϰ� �Ǹ�
	//Ŭ������ ���� ������ �ʾƵ� ������ ���� ��������� �ȴ�.
	static T* p;
public:
	singleton() {};
	virtual ~singleton() {};

	//�Լ��� static�� ����ϰ� �Ǹ�
	//Ŭ������ ��� Ŭ�����̸������� �Լ��� ����Ҽ� �ְ� �ȴ�
	static T* GetInstance()
	{
		if (!p)
			p = new T;
		return p;
	}
	static void ReleaseInstance()
	{
		if (p)
			delete p;
		p = nullptr;
	}
	//���� �� singletonŬ������ ��ӹް� �Ǹ�, �� Ŭ������ ���������� ����ϰ� ����Ҽ� �ִ�.
	//������ ó���ӵ��� �Ϲ�Ŭ������ ���� ������
	//��ü ������ �����ϴ� ����߿� �ϳ��̹Ƿ�
	//�� �ʿ��Ѱ��� �ƴϸ� ������� �ʴ°��� ����.
};

template <typename T>
T* singleton<T>::p = nullptr;
//����ƽ ������ ���ο��� �ʱ�ȭ�� ���ϰ�, Ŭ���� �ܺο��� �ѹ� �ʱ�ȭ ���־�� �Ѵ�