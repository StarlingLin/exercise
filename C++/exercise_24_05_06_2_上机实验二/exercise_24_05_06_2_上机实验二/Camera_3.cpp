#define _CRT_SECURE_NO_WARNINGS

// 继承方式 3 : 行车记录仪的芯片可以使用摄像机的拍摄、图像质量设定功能。行车记录仪用户仅仅可以操作行车记录仪的操作菜单。同时其他公司购买行车记录仪，因该公司也用于销售，不得泄露其全部内容。

#include <iostream>
#include "Camera_3.h"

using namespace std;

// Product

Product_3::~Product_3()
{
}

// Camera_3

Camera_3::Camera_3(string resolution, string algorithm, float EV)
{
	this->resolution = resolution;
	this->algorithm = algorithm;
	this->EV = EV;
}

Camera_3::~Camera_3()
{
}

void Camera_3::setResolution(string resolution)
{
	this->resolution = resolution;
}

string Camera_3::getResolution()
{
	return resolution;
}

void Camera_3::setAlgorithm(string algorithm)
{
	this->algorithm = algorithm;
}

string Camera_3::getAlgorithm()
{
	return algorithm;
}

void Camera_3::setEV(float EV)
{
	this->EV = EV;
}

float Camera_3::getEV()
{
	return EV;
}

void Camera_3::capture()
{
}

// Dashcam_3

Dashcam_3::Dashcam_3(string resolution, string algorithm, float EV, string menu, bool autoShoot, float speed)
	: Camera_3(resolution, algorithm, EV)
{
	this->menu = menu;
	this->autoShoot = autoShoot;
	this->speed = speed;
}

Dashcam_3::~Dashcam_3()
{
}

void Dashcam_3::setMenu(string menu)
{
	this->menu = menu;
}

string Dashcam_3::getMenu()
{
	return menu;
}

void Dashcam_3::setAutoShoot(bool autoShoot)
{
	this->autoShoot = autoShoot;
}

bool Dashcam_3::getAutoShoot()
{
	return autoShoot;
}

void Dashcam_3::setSpeed(float speed)
{
	this->speed = speed;
}

float Dashcam_3::getSpeed()
{
	return speed;
}

void Dashcam_3::capture()
{
	cout << "-----------------------------------------" << endl;
	cout << "Dashcam capturing with following settings:" << endl;
	cout << "Resolution: " << resolution << endl;	//和继承方式 2 不同的是，这里可以访问到 resolution，下面的 algorithm 和 EV 也是一样的
	cout << "Algorithm: " << algorithm << endl;
	cout << "EV: " << EV << endl;
	cout << "Menu: " << menu << endl;
	cout << "AutoShoot: " << autoShoot << endl;
	cout << "Speed: " << speed << endl;
	cout << "-----------------------------------------" << endl;
}