#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int main()
{
	initgraph(640, 480);
	setbkcolor(RGB(255, 255, 255));
	cleardevice();
	setlinecolor(RGB(255, 0, 0));
	setfillcolor(RGB(0, 255, 0));
	fillcircle(320, 240, 100);
	system("pause");
	closegraph();
	return 0;
}