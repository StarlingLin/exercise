#pragma once

// ��Ϸ�ʽ��˽�м̳�

#include <string>

using namespace std;

class Product_4
{
public:
	virtual ~Product_4();

	virtual void capture() = 0;
};

class Camera_4 : public Product_4
{
public:
	Camera_4(string resolution = "1920*1080", string algorithm = "H.264", float EV = 4.0);
	~Camera_4();

	void setResolution(string resolution);
	string getResolution();

	void setAlgorithm(string algorithm);
	string getAlgorithm();

	void setEV(float EV);
	float getEV();

	void capture();

private:
	string resolution;	// �ֱ���
	string algorithm;	// �����㷨
	float EV;			// �عⲹ��ֵ
};

class Dashcam_4 : public Product_4
{
public:
	Dashcam_4(string resolution = "1920*1080", string algorithm = "H.264", float EV = 4.0, string menu = "Default", bool autoShoot = false, float speed = 0.0);
	~Dashcam_4();

	void setMenu(string menu);
	string getMenu();

	void setAutoShoot(bool autoShoot);
	bool getAutoShoot();

	void setSpeed(float speed);
	float getSpeed();

	void capture();

private:
	Camera_4 camera;
	string menu;		// �����˵�
	bool autoShoot;		// �Զ�����
	float speed;		// ���ٴ�����
};