#pragma once

// 继承方式 2 : 行车记录仪的芯片可以使用摄像机的拍摄、图像质量设定功能。行车记录仪用户仅仅可以操作行车记录仪的操作菜单。

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
	string resolution;	// 分辨率
	string algorithm;	// 编码算法
	float EV;			// 曝光补偿值
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
	string menu;		// 操作菜单
	bool autoShoot;		// 自动拍摄
	float speed;		// 车速传感器
};