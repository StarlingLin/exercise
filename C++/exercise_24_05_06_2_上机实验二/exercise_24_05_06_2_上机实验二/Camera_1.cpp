#define _CRT_SECURE_NO_WARNINGS

// 继承方式 1 : 行车记录仪的芯片可以使用摄像机的摄像、图像质量设定功能。行车记录仪用户可以操作行车记录仪的操作菜单和摄像机的摄像功能。

#include <iostream>
#include "Camera_1.h"

using namespace std;

// Product

Product_1::~Product_1()
{
}

// Camera_1

Camera_1::Camera_1(string resolution, string algorithm, float EV)
{
	this->resolution = resolution;
	this->algorithm = algorithm;
	this->EV = EV;
}

Camera_1::~Camera_1()
{
}

void Camera_1::setResolution(string resolution)
{
	this->resolution = resolution;
}

string Camera_1::getResolution()
{
	return resolution;
}

void Camera_1::setAlgorithm(string algorithm)
{
	this->algorithm = algorithm;
}

string Camera_1::getAlgorithm()
{
	return algorithm;
}

void Camera_1::setEV(int EV)
{
	this->EV = EV;
}

int Camera_1::getEV()
{
	return EV;
}

void Camera_1::capture()
{
	cout << "-----------------------------------------" << endl;
	cout << "Camera capturing with following settings:" << endl;
	cout << "Resolution: " << resolution << endl;
	cout << "Algorithm: " << algorithm << endl;
	cout << "EV: " << EV << endl;
	cout << "-----------------------------------------" << endl;
}

// Dashcam_1

Dashcam_1::Dashcam_1(string resolution, string algorithm, float EV, string menu, bool autoShoot, float speed)
	: Camera_1(resolution, algorithm, EV)
{
	this->menu = menu;
	this->autoShoot = autoShoot;
	this->speed = speed;
}

Dashcam_1::~Dashcam_1()
{
}

void Dashcam_1::setMenu(string menu)
{
	this->menu = menu;
}

string Dashcam_1::getMenu()
{
	return menu;
}

void Dashcam_1::setAutoShoot(bool autoShoot)
{
	this->autoShoot = autoShoot;
}

bool Dashcam_1::getAutoShoot()
{
	return autoShoot;
}

void Dashcam_1::setSpeed(float speed)
{
	this->speed = speed;
}

float Dashcam_1::getSpeed()
{
	return speed;
}

void Dashcam_1::capture()
{
	cout << "-----------------------------------------" << endl;
	cout << "Dashcam capturing with following settings:" << endl;
	cout << "Resolution: " << getResolution() << endl;
	cout << "Algorithm: " << getAlgorithm() << endl;
	cout << "EV: " << getEV() << endl;
	cout << "Menu: " << menu << endl;
	cout << "AutoShoot: " << autoShoot << endl;
	cout << "Speed: " << speed << endl;
	cout << "-----------------------------------------" << endl;
}