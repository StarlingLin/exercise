#define _CRT_SECURE_NO_WARNINGS

//����һ��ʱ����Time�����ṩ��������ʱ���֡�����ɵ�ʱ�䣬Ҫ���������ʱ���������ʱ�䡢����ö����ṩ��ʱ�䡣���뽫�ඨ����Ϊ���档
//��������ʱ��ļӼ������ո��ָ�ʽ���ʱ�䡢�����ǰʱ��Ȳ�����

#include "Time.h"

enum State
{
	SET = 1,
	PRINT,
	ADD,
	SUB,
	PRINT_FORMAT,
	PRINT_CURRENT,
	EXIT = 0
};

void PrintMenu(void)
{
	std::cout << "1. Set time" << std::endl;
	std::cout << "2. Print time" << std::endl;
	std::cout << "3. Add time" << std::endl;
	std::cout << "4. Sub time" << std::endl;
	std::cout << "5. Print time with format" << std::endl;
	std::cout << "6. Print current time" << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cout << "Please input your choice: ";
}

int main()
{
	Time t;
	int operate;
	int hour, minute, second;
	int format;

	do
	{
		PrintMenu();
		std::cin >> operate;

		switch (operate)
		{
		case 1:
			std::cout << "Please input hour, minute and second: ";
			std::cin >> hour >> minute >> second;
			t.SetTime(hour, minute, second);
			system("pause");
			break;
		case 2:
			t.PrintTime();
			system("pause");
			break;
		case 3:
			std::cout << "Please input hour, minute and second: ";
			std::cin >> hour >> minute >> second;
			t.AddTime(hour, minute, second);
			system("pause");
			break;
		case 4:
			std::cout << "Please input hour, minute and second: ";
			std::cin >> hour >> minute >> second;
			t.SubTime(hour, minute, second);
			system("pause");
			break;
		case 5:
			std::cout << "Please input format(1 for 24-hour format, 2 for 12-hour format): ";
			std::cin >> format;
			t.PrintTime(format);
			system("pause");
			break;
		case 6:
			t.PrintCurrentTime();
			system("pause");
			break;
		case 0:
			operate = EXIT;
			break;
		default:
			std::cout << "Invalid choice!" << std::endl;
			system("pause");
			break;
		}
		system("cls");
	} while (operate);

	return EXIT_SUCCESS;
}