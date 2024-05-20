#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Camera_4.h"

using namespace std;

// Product

Product_4::~Product_4()
{
}

// Camera_4

Camera_4::Camera_4(string resolution, string algorithm, float EV)
{
	this->resolution = resolution;
	this->algorithm = algorithm;
	this->EV = EV;
}

Camera_4::~Camera_4()
{
}

void Camera_4::setResolution(string resolution)
{
	this->resolution = resolution;
}

string Camera_4::getResolution()
{
	return resolution;
}

void Camera_4::setAlgorithm(string algorithm)
{
	this->algorithm = algorithm;
}

string Camera_4::getAlgorithm()
{
	return algorithm;
}

void Camera_4::setEV(float EV)
{
	this->EV = EV;
}

float Camera_4::getEV()
{
	return EV;
}

void Camera_4::capture()
{
	cout << "-----------------------------------------" << endl;
	cout << "Camera capturing with following settings:" << endl;
	cout << "Resolution: " << resolution << endl;
	cout << "Algorithm: " << algorithm << endl;
	cout << "EV: " << EV << endl;
	cout << "-----------------------------------------" << endl;
}

// Dashcam_4

Dashcam_4::Dashcam_4(string resolution, string algorithm, float EV, string menu, bool autoShoot, float speed) : camera(resolution, algorithm, EV)
{
	this->menu = menu;
	this->autoShoot = autoShoot;
	this->speed = speed;
}

Dashcam_4::~Dashcam_4()
{
}

void Dashcam_4::setMenu(string menu)
{
	this->menu = menu;
}

string Dashcam_4::getMenu()
{
	return menu;
}

void Dashcam_4::setAutoShoot(bool autoShoot)
{
	this->autoShoot = autoShoot;
}

bool Dashcam_4::getAutoShoot()
{
	return autoShoot;
}

void Dashcam_4::setSpeed(float speed)
{
	this->speed = speed;
}

float Dashcam_4::getSpeed()
{
	return speed;
}

void Dashcam_4::capture()
{
	cout << "-----------------------------------------" << endl;
	cout << "Dashcam capturing with following settings:" << endl;
	cout << "Resolution: " << camera.getResolution() << endl;
	cout << "Algorithm: " << camera.getAlgorithm() << endl;
	cout << "EV: " << camera.getEV() << endl;
	cout << "Menu: " << menu << endl;
	cout << "AutoShoot: " << autoShoot << endl;
	cout << "Speed: " << speed << endl;
	cout << "-----------------------------------------" << endl;
}