#pragma once

// 继承方式 1 : 行车记录仪的芯片可以使用摄像机的摄像、图像质量设定功能。行车记录仪用户可以操作行车记录仪的操作菜单和摄像机的摄像功能。

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
	string resolution;	// 分辨率
	string algorithm;	// 编码算法
	float EV;			// 曝光补偿值
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
	string menu;		// 操作菜单
	bool autoShoot;		// 自动拍摄
	float speed;		// 车速传感器
};