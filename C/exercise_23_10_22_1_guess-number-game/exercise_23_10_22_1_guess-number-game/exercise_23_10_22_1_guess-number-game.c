#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void menu()
{
	printf("******************\n");
	printf("**1.guess-number**\n");
	printf("**0.exit-game   **\n");
	printf("******************\n");
}

void game()
{
	system("CLS");
	int num = rand() % 100 + 1;
	int guess = 0;
	int cnt = 1;

	while(1)
	{
		printf("答案在1~100之间，请开始你的表演：\n");
		scanf("%d", &guess);
		
		if (num < guess)
		{
			system("CLS");
			printf("好大~\n");
		}
		else if (num > guess)
		{
			system("CLS");
			printf("行不行啊~细狗~\n");
		}
		else
		{
			system("CLS");
			printf("对喽~\n");
			break;
		}

		cnt++;
	}

	if (1 == cnt)
		printf("Ohhhhhhhhhhh\n一次猜中的欧皇！\n");
	else if (cnt <= 5)
		printf("666\n你用%d次就猜中了！\n", cnt);
	else if (cnt <= 10)
		printf("就这？就这？！\n你用了%d次才猜中\n", cnt);
	else
		printf("好好好，这么玩是吧？\n%d次猜中，太菜了\n", cnt);


}

int main()
{
	int cs = 0;

	srand((unsigned)time(NULL));

	do
	{
		menu();
		scanf("%d", &cs);

		switch (cs)
		{
		case 1: game(); break;
		case 0: break;
		default: system("CLS"); printf("你在瞎输什么？啊?\n");
		}
	} while (cs);

	return 0;
}