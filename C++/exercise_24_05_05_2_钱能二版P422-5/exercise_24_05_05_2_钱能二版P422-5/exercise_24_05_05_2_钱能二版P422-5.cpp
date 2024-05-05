#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

/******************************************************************************************
* 定义一个具有多态性的基类 Shape，继承以下一些类 : 圆Circle 类(坐标点和半径构成)，长方形 Rectangle类(两个不重合的坐标点构成)，三角形Triangle 类(三个互不重合的坐标点构成)。定义一些操作，特别是定义求面积操作。
* 编制应用程序，按文件内容创建各类对象，放在 Shape 指针向量中。
* 循环处理向量中的每个元素，求其面积。若为圆，则还要输出其半径(输出半径不是求面积的职能，应另设 get 成员实现之，它不是虚函数)。
* 键盘输入内容如下 :
* C 123 5 5000
* T 1 3 1 50 60 3
* C 6 61 30
* R 6 8 8 1000
* C 2 3 12.3
* X
* 
* 若第一个字符为C，则后面为圆数据：x坐标、y坐标、圆半径
* 若第一字符为R，则后面为长方形数据：x1、y1、x2、y2 坐标
* 若第一字符为T，则后面为三角形数据：x1、y1、x2、y2、x3、y3 坐标
* 若第一字符为X，则结束输入
******************************************************************************************/

class Shape
{
public:
	virtual double getArea() = 0;
	virtual void print() = 0;
};

class Circle : public Shape
{
public:
	Circle(double x, double y, double r) : x(x), y(y), r(r) {}
	Circle(const Circle& c) : x(c.x), y(c.y), r(c.r) {}
	double getArea() { return 3.14159 * r * r; }
	void print() { cout << "Circle: x=" << x << ", y=" << y << ", r=" << r << endl; }

private:
	double x, y, r;
};

class Rectangle : public Shape
{
public:
	Rectangle(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
	Rectangle(const Rectangle& r) : x1(r.x1), y1(r.y1), x2(r.x2), y2(r.y2) {}
	double getArea() { return (x2 - x1) * (y2 - y1); }
	void print() { cout << "Rectangle: x1=" << x1 << ", y1=" << y1 << ", x2=" << x2 << ", y2=" << y2 << endl; }

private:
	double x1, y1, x2, y2;
};

class Triangle : public Shape
{
public:
	Triangle(double x1, double y1, double x2, double y2, double x3, double y3) : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}
	Triangle(const Triangle& t) : x1(t.x1), y1(t.y1), x2(t.x2), y2(t.y2), x3(t.x3), y3(t.y3) {}
	double getArea() { return 0.5 * abs((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)); }
	void print() { cout << "Triangle: x1=" << x1 << ", y1=" << y1 << ", x2=" << x2 << ", y2=" << y2 << ", x3=" << x3 << ", y3=" << y3 << endl; }

private:
	double x1, y1, x2, y2, x3, y3;
};

/******************************************************************************************
* 创建类Manage，包含“Shape* a[100]”，要求完成Manage类的拷贝构造函数，实现深度拷贝
******************************************************************************************/

class Manage
{
public:
	Shape* a[100] = { 0 };
	Manage() {}
	Manage(const Manage& m)
	{
		for (int i = 0; i < 100; i++)
		{
			if (m.a[i] != nullptr)
			{
				if (typeid(*m.a[i]) == typeid(Circle))
				{
					a[i] = new Circle(*(dynamic_cast<Circle*>(m.a[i])));
				}
				else if (typeid(*m.a[i]) == typeid(Rectangle))
				{
					a[i] = new Rectangle(*(dynamic_cast<Rectangle*>(m.a[i])));
				}
				else if (typeid(*m.a[i]) == typeid(Triangle))
				{
					a[i] = new Triangle(*(dynamic_cast<Triangle*>(m.a[i])));
				}
			}
		}
	}

	~Manage()
	{
		for (int i = 0; i < 100; i++)
		{
			if (a[i] != nullptr)
			{
				delete a[i];
				a[i] = nullptr;
			}
		}
	}

	void addShape(Shape* s)
	{
		for (int i = 0; i < 100; i++)
		{
			if (a[i] == nullptr)
			{
				a[i] = s;
				break;
			}
		}
	}
};

int main()
{
	Manage m;
	char ShapeType = 'X';
	double x1, y1, x2, y2, x3, y3, r;

	do
	{
		cin >> ShapeType;
		switch (ShapeType)
		{
		case 'C':
			cin >> x1 >> y1 >> r;
			m.addShape(new Circle(x1, y1, r));
			break;
		case 'R':
			cin >> x1 >> y1 >> x2 >> y2;
			m.addShape(new Rectangle(x1, y1, x2, y2));
			break;
		case 'T':
			cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
			m.addShape(new Triangle(x1, y1, x2, y2, x3, y3));
			break;
		case 'X':
			break;
		default:
			cout << "Invalid input!" << endl;
			return EXIT_FAILURE;
		}
	} while (ShapeType != 'X');

	//测试拷贝构造函数
	Manage m2(m);

	for (const auto& shape : m2.a)
	{
		if (shape != nullptr)
		{
			shape->print();
			cout << "Area: " << shape->getArea() << endl;
		}
	}

	return 0;
}