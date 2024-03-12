#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
};

//�ڵ���
struct Node* copyRandomList1(struct Node* head) 
{
    if (head == NULL) 
    {
        return NULL;
    }
    for (struct Node* node = head; node != NULL; node = node->next->next)
    {
        struct Node* nodeNew = malloc(sizeof(struct Node));
        nodeNew->val = node->val;
        nodeNew->next = node->next;
        node->next = nodeNew;
    }
    for (struct Node* node = head; node != NULL; node = node->next->next)
    {
        struct Node* nodeNew = node->next;
        nodeNew->random = (node->random != NULL) ? node->random->next : NULL;
    }
    struct Node* headNew = head->next;
    for (struct Node* node = head; node != NULL; node = node->next) 
    {
        struct Node* nodeNew = node->next;
        node->next = node->next->next;
        nodeNew->next = (nodeNew->next != NULL) ? nodeNew->next->next : NULL;
    }
    return headNew;
}

//����
struct Node* copyRandomList2(struct Node* head) 
{

}