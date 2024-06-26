#define _CRT_SECURE_NO_WARNINGS

// 继承方式 2 : 行车记录仪的芯片可以使用摄像机的拍摄、图像质量设定功能。行车记录仪用户仅仅可以操作行车记录仪的操作菜单。

#include <iostream>
#include "Camera_2.h"

using namespace std;

// Product

Product_2::~Product_2()
{
}

// Camera_2

Camera_2::Camera_2(string resolution, string algorithm, float EV)
{
	this->resolution = resolution;
	this->algorithm = algorithm;
	this->EV = EV;
}

Camera_2::~Camera_2()
{
}

void Camera_2::setResolution(string resolution)
{
	this->resolution = resolution;
}

string Camera_2::getResolution()
{
	return resolution;
}

void Camera_2::setAlgorithm(string algorithm)
{
	this->algorithm = algorithm;
}

string Camera_2::getAlgorithm()
{
	return algorithm;
}

void Camera_2::setEV(float EV)
{
	this->EV = EV;
}

float Camera_2::getEV()
{
	return EV;
}

void Camera_2::capture()
{
	cout << "-----------------------------------------" << endl;
	cout << "Camera capturing with following settings:" << endl;
	cout << "Resolution: " << resolution << endl;
	cout << "Algorithm: " << algorithm << endl;
	cout << "EV: " << EV << endl;
	cout << "-----------------------------------------" << endl;
}

// Dashcam_2

Dashcam_2::Dashcam_2(string resolution, string algorithm, float EV, string menu, bool autoShoot, float speed)
	: Camera_2(resolution, algorithm, EV)
{
	this->menu = menu;
	this->autoShoot = autoShoot;
	this->speed = speed;
}

Dashcam_2::~Dashcam_2()
{
}

void Dashcam_2::setMenu(string menu)
{
	this->menu = menu;
}

string Dashcam_2::getMenu()
{
	return menu;
}

void Dashcam_2::setAutoShoot(bool autoShoot)
{
	this->autoShoot = autoShoot;
}

bool Dashcam_2::getAutoShoot()
{
	return autoShoot;
}

void Dashcam_2::setSpeed(float speed)
{
	this->speed = speed;
}

float Dashcam_2::getSpeed()
{
	return speed;
}

void Dashcam_2::capture()
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