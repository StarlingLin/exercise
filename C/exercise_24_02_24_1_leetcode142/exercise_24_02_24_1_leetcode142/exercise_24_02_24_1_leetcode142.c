#define _CRT_SECURE_NO_WARNINGS

//����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��

//�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ������� pos �� - 1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head)
{
	struct ListNode *slow = head;
	struct ListNode *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			struct ListNode *slow2 = head;
			while (slow2 != slow)
			{
				slow = slow->next;
				slow2 = slow2->next;
			}
			return slow2;
		}
	}
	return NULL;
}

int main()
{
	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->val = 3;
	head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->val = 2;
	head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->next->val = 0;
	head->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->next->next->val = -4;
	head->next->next->next->next = head->next;

	struct ListNode *result = detectCycle(head);
	printf("%d\n", result->val);

	free(head->next->next->next);
	free(head->next->next);
	free(head->next);
	free(head);

	return 0;
}

