#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	printf("\a\n");//����
	printf("\?\n");//�ʺ�
	printf("\'\n");//'
	printf("\"\n");//"
	printf("\\\n");/*  \  */
	printf("a\ba\n");//�˸�
	printf("a\fa\n");//��ҳ
	printf("a\na\n");//����
	printf("a\ra\n");//�س�
	printf("a\ta\n");//ˮƽ�Ʊ��
	printf("a\va\n");//��ֱ�Ʊ��
	printf("\130\n");//8����ASCII
	printf("\x90\n");//16����ASCII
	return 0;
}