#pragma once

// �̳з�ʽ 3 : �г���¼�ǵ�оƬ����ʹ������������㡢ͼ�������趨���ܡ��г���¼���û����Բ����г���¼�ǵĲ����˵���������������ܡ�
// ͬʱ������˾�����г���¼�ǣ���ù�˾Ҳ�������ۣ�����й¶��ȫ�����ݡ�

#include <string>

using namespace std;

class Product_3
{
public:
	virtual ~Product_3();

	virtual void capture() = 0;
};

class Camera_3 : public Product_3
{
public:
	Camera_3(string resolution = "1920*1080", string algorithm = "H.264", float EV = 4.0);
	~Camera_3();

	void setResolution(string resolution);
	string getResolution();

	void setAlgorithm(string algorithm);
	string getAlgorithm();

	void setEV(float EV);
	float getEV();

	void capture();

protected:
	string resolution;	// �ֱ���
	string algorithm;	// �����㷨
	float EV;			// �عⲹ��ֵ
};

class Dashcam_3 : protected Camera_3
{
public:
	Dashcam_3(string resolution = "1920*1080", string algorithm = "H.264", float EV = 4.0, string menu = "Default", bool autoShoot = false, float speed = 0.0);
	~Dashcam_3();

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