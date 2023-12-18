#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE A + B	//注意外面没有括号

int main()
{
	int A = 2, B = 3;
	struct _Record_Struct
	{
		unsigned char Env_Alarm_ID : 4;
		unsigned char Para1 : 2;
		unsigned char state;
		unsigned char avail : 1;
	}*Env_Alarm_Record;
	struct _Record_Struct* pointer = (struct _Record_Struct*)malloc(sizeof(struct _Record_Struct) * MAX_SIZE);
	printf("%zd", _msize(pointer));

	return 0;
}