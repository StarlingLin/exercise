#define _CRT_SECURE_NO_WARNINGS

// �̳з�ʽ 3 : �г���¼�ǵ�оƬ����ʹ������������㡢ͼ�������趨���ܡ��г���¼���û��������Բ����г���¼�ǵĲ����˵���ͬʱ������˾�����г���¼�ǣ���ù�˾Ҳ�������ۣ�����й¶��ȫ�����ݡ�

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
	cout << "Resolution: " << resolution << endl;	//�ͼ̳з�ʽ 2 ��ͬ���ǣ�������Է��ʵ� resolution������� algorithm �� EV Ҳ��һ����
	cout << "Algorithm: " << algorithm << endl;
	cout << "EV: " << EV << endl;
	cout << "Menu: " << menu << endl;
	cout << "AutoShoot: " << autoShoot << endl;
	cout << "Speed: " << speed << endl;
	cout << "-----------------------------------------" << endl;
}