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
		printf("����1~100֮�䣬�뿪ʼ��ı��ݣ�\n");
		scanf("%d", &guess);
		
		if (num < guess)
		{
			system("CLS");
			printf("�ô�~\n");
		}
		else if (num > guess)
		{
			system("CLS");
			printf("�в��а�~ϸ��~\n");
		}
		else
		{
			system("CLS");
			printf("���~\n");
			break;
		}

		cnt++;
	}

	if (1 == cnt)
		printf("Ohhhhhhhhhhh\nһ�β��е�ŷ�ʣ�\n");
	else if (cnt <= 5)
		printf("666\n����%d�ξͲ����ˣ�\n", cnt);
	else if (cnt <= 10)
		printf("���⣿���⣿��\n������%d�βŲ���\n", cnt);
	else
		printf("�úúã���ô���ǰɣ�\n%d�β��У�̫����\n", cnt);


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
		default: system("CLS"); printf("����Ϲ��ʲô����?\n");
		}
	} while (cs);

	return 0;
}