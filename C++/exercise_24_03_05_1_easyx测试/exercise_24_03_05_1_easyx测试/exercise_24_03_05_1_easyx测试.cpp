#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include "HiEasyX.h"

//int main()
//{
//	initgraph(640, 480);
//	setbkcolor(RGB(255, 255, 255));
//	cleardevice();
//	setlinecolor(RGB(255, 0, 0));
//	setfillcolor(RGB(0, 255, 0));
//	fillcircle(320, 240, 100);
//	system("pause");
//	closegraph();
//	return 0;
//}

int main()
{
	hiex::Window wnd(300, 180);

	//±à¼­¿ò
	hiex::SysEdit edit;
	edit.Create(wnd.GetHandle(), 10, 10, 200, 30, L"edit here");
	edit.SetFont(20, 0, L"ËÎÌå");

	//°´Å¥
	hiex::SysButton btn;
	btn.Create(wnd.GetHandle(), 10, 50, 100, 30, L"click me");

	while (wnd.IsAlive())
	{
		if (btn.IsClicked())
		{
			MessageBox(wnd.GetHandle(), edit.GetText().c_str(), L"Submit", MB_OK);
			REDRAW_WINDOW(wnd.GetHandle());
			Sleep(50);
		}
	}

	system("pause");
	return EXIT_SUCCESS;
}