#pragma once

// �̳з�ʽ 2 : �г���¼�ǵ�оƬ����ʹ������������㡢ͼ�������趨���ܡ��г���¼���û��������Բ����г���¼�ǵĲ����˵���

#include <string>

using namespace std;

class Product_2
{
public:
	virtual ~Product_2();

	virtual void capture() = 0;
};

class Camera_2 : public Product_2
{
public:
	Camera_2(string resolution = "1920*1080", string algorithm = "H.264", float EV = 4.0);
	~Camera_2();

	void setResolution(string resolution);
	string getResolution();

	void setAlgorithm(string algorithm);
	string getAlgorithm();

	void setEV(int EV);
	int getEV();

	void capture();

protected:
	string resolution;	// �ֱ���
	string algorithm;	// �����㷨
	float EV;			// �عⲹ��ֵ
};

class Dashcam_2 : public Camera_2
{
public:
	Dashcam_2(string resolution = "1920*1080", string algorithm = "H.264", float EV = 4.0, string menu = "Default", bool autoShoot = false, float speed = 0.0);
	~Dashcam_2();

	void setMenu(string menu);
	string getMenu();

	void setAutoShoot(bool autoShoot);
	bool getAutoShoot();

	void setSpeed(float speed);
	float getSpeed();

	void capture();

private:
	string menu;		// �����˵�
	bool autoShoot;		// �Զ�����
	float speed;		// ���ٴ�����
};