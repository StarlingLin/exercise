#define _CRT_SECURE_NO_WARNINGS

/*
* 设计摄像机类Camera，该类包含摄像、图像质量设定、编码算法等属性。
* 摄像机增加相应芯片（具有操作菜单、自动拍摄、车速传感器、源代码等功能）后，形成一个行车记录仪。
* -----------------------------------------------------------------------------------
* 采用不同的继承方式设计行车记录仪类并添加测试代码，体验不同继承方式下的成员访问属性：
* 1. 行车记录仪的芯片可以使用摄像机的摄像、图像质量设定功能。行车记录仪用户可以操作行车记录仪的操作菜单和摄像机的摄像功能。
* 2. 行车记录仪的芯片可以使用摄像机的拍摄、图像质量设定功能。行车记录仪用户仅仅可以操作行车记录仪的操作菜单。
* 3. 行车记录仪的芯片可以使用摄像机的拍摄、图像质量设定功能。行车记录仪用户仅仅可以操作行车记录仪的操作菜单。同时其他公司购买行车记录仪，因该公司也用于销售，不得泄露其全部内容。
* -----------------------------------------------------------------------------------
* 采用组合方式设计行车记录仪类，体验继承和组合的关系。
* -----------------------------------------------------------------------------------
* 1. 分别为继承和组合方式下为各类添加构造函数、析构函数，增加相应测试代码，体验对象的初始化和构造顺序。
* 2. 将摄像机类和行车记录仪类功能相近的函数（如拍摄、编码等功能函数）设为同名函数，增加相应测试代码，体验同名函数覆盖。
* 3. 建立一个多态的产品类层次结构，测试时，创建一个基类指针的容器，通过基类指针调用虚函数，体验多态。
*/

#include <iostream>
#include <vector>
#include "Camera_1.h"	// 继承方式 1
#include "Camera_2.h"	// 继承方式 2

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
	Test1();	// 继承方式 1 : 行车记录仪的芯片可以使用摄像机的摄像、图像质量设定功能。行车记录仪用户可以操作行车记录仪的操作菜单和摄像机的摄像功能。

	return 0;
}