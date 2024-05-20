#pragma once

// �̳з�ʽ 1 : �г���¼�ǵ�оƬ����ʹ�������������ͼ�������趨���ܡ��г���¼���û����Բ����г���¼�ǵĲ����˵���������������ܡ�

#include <string>

using namespace std;

class Product_1
{
public:
	virtual ~Product_1();

	virtual void capture() = 0;
};

class Camera_1 : public Product_1
{
public:
	Camera_1(string resolution = "1920*1080", string algorithm = "H.264", float EV = 4.0);
	~Camera_1();

	void setResolution(string resolution);
	string getResolution();

	void setAlgorithm(string algorithm);
	string getAlgorithm();

	void setEV(int EV);
	int getEV();

	void capture();

private:
	string resolution;	// �ֱ���
	string algorithm;	// �����㷨
	float EV;			// �عⲹ��ֵ
};

class Dashcam_1 : public Camera_1
{
public:
	Dashcam_1(string resolution = "1920*1080", string algorithm = "H.264", float EV = 4.0, string menu = "Default", bool autoShoot = false, float speed = 0.0);
	~Dashcam_1();

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