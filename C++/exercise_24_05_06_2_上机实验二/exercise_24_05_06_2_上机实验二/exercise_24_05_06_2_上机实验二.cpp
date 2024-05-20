#define _CRT_SECURE_NO_WARNINGS

/*
* ����������Camera�������������ͼ�������趨�������㷨�����ԡ�
* �����������ӦоƬ�����в����˵����Զ����㡢���ٴ�������Դ����ȹ��ܣ����γ�һ���г���¼�ǡ�
* -----------------------------------------------------------------------------------
* ���ò�ͬ�ļ̳з�ʽ����г���¼���ಢ��Ӳ��Դ��룬���鲻ͬ�̳з�ʽ�µĳ�Ա�������ԣ�
* 1. �г���¼�ǵ�оƬ����ʹ�������������ͼ�������趨���ܡ��г���¼���û����Բ����г���¼�ǵĲ����˵���������������ܡ�
* 2. �г���¼�ǵ�оƬ����ʹ������������㡢ͼ�������趨���ܡ��г���¼���û��������Բ����г���¼�ǵĲ����˵���
* 3. �г���¼�ǵ�оƬ����ʹ������������㡢ͼ�������趨���ܡ��г���¼���û��������Բ����г���¼�ǵĲ����˵���ͬʱ������˾�����г���¼�ǣ���ù�˾Ҳ�������ۣ�����й¶��ȫ�����ݡ�
* -----------------------------------------------------------------------------------
* ������Ϸ�ʽ����г���¼���࣬����̳к���ϵĹ�ϵ��
* -----------------------------------------------------------------------------------
* 1. �ֱ�Ϊ�̳к���Ϸ�ʽ��Ϊ������ӹ��캯��������������������Ӧ���Դ��룬�������ĳ�ʼ���͹���˳��
* 2. �����������г���¼���๦������ĺ����������㡢����ȹ��ܺ�������Ϊͬ��������������Ӧ���Դ��룬����ͬ���������ǡ�
* 3. ����һ����̬�Ĳ�Ʒ���νṹ������ʱ������һ������ָ���������ͨ������ָ������麯���������̬��
*/

#include <iostream>
#include <vector>
#include "Camera_1.h"	// �̳з�ʽ 1
#include "Camera_2.h"	// �̳з�ʽ 2

using namespace std;

void Test1()
{
	//Camera_1 camera("2560*1440", "H.265", 5.0);
	//cout << "Resolution: " << camera.getResolution() << endl;
	//cout << "Algorithm: " << camera.getAlgorithm() << endl;
	//cout << "EV: " << camera.getEV() << endl;
	//camera.setAlgorithm("H.264");
	//cout << "New Algorithm: " << camera.getAlgorithm() << endl;
	//camera.capture();

	//Dashcam_1 dashcam("2560*1440", "H.265", 5.0, "Custom", true, 60.0);
	//cout << "Resolution: " << dashcam.getResolution() << endl;
	//cout << "Algorithm: " << dashcam.getAlgorithm() << endl;
	//cout << "EV: " << dashcam.getEV() << endl;
	//cout << "Menu: " << dashcam.getMenu() << endl;
	//cout << "AutoShoot: " << dashcam.getAutoShoot() << endl;
	//cout << "Speed: " << dashcam.getSpeed() << endl;
	//dashcam.setAlgorithm("H.264");
	//cout << "New Algorithm: " << dashcam.getAlgorithm() << endl;
	//dashcam.capture();

	vector<Product_1*> products_1;
	products_1.push_back(new Camera_1("2560*1440", "H.265", 5.0));
	products_1.push_back(new Dashcam_1("2560*1440", "H.265", 5.0, "Custom", true, 60.0));
	for (const auto& product : products_1)
	{
		product->capture();
	}
	for (const auto& product : products_1)
	{
		delete product;
	}
}

int main()
{
	Test1();	// �̳з�ʽ 1 : �г���¼�ǵ�оƬ����ʹ�������������ͼ�������趨���ܡ��г���¼���û����Բ����г���¼�ǵĲ����˵���������������ܡ�

	return 0;
}