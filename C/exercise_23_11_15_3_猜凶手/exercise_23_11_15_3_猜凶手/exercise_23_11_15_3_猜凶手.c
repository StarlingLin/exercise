#define _CRT_SECURE_NO_WARNINGS 1

//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ���:
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�

#include <stdio.h>

int main()
{
	char murder = 'A';
	for (; murder <= 'D'; murder++)
		if (3 == (murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D'))
			printf("Murderer is %c!", murder);
	return 0;
}