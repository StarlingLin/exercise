#pragma once

// 继承方式 3 : 行车记录仪的芯片可以使用摄像机的拍摄、图像质量设定功能。行车记录仪用户可以操作行车记录仪的操作菜单和摄像机的摄像功能。
// 同时其他公司购买行车记录仪，因该公司也用于销售，不得泄露其全部内容。

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
	string resolution;	// 分辨率
	string algorithm;	// 编码算法
	float EV;			// 曝光补偿值
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
	string menu;		// 操作菜单
	bool autoShoot;		// 自动拍摄
	float speed;		// 车速传感器
};