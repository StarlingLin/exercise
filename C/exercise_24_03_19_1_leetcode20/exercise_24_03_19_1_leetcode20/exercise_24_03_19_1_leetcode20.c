#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
    char* data;
    int top;
    int capacity;
} Stack;

void StackInit(Stack* st)
{
    st->data = NULL;
    st->top = st->capacity = 0;
}

void StackPush(Stack* st, char data)
{
    if (st->top == st->capacity)
    {
        int newcapacity = (st->capacity == 0 ? 4 : 2 * st->capacity);
        char* tmp = (char*)realloc(st->data, newcapacity);
        if (tmp == NULL)
        {
            exit(1);
        }
        st->data = tmp;
        st->capacity = newcapacity;
    }
    st->data[st->top] = data;
    st->top++;
}

char StackPop(Stack* st)
{
    if (st->top == 0)
	{
		return '\0';
	}
    char ret = st->data[st->top - 1];
    st->top--;
    return ret;
}

bool isValid(char* s) {
    Stack st;
    StackInit(&st);
    char* temp = s;

    while (*temp != '\0')
    {
        if (*temp == '(' || *temp == '[' || *temp == '{')
        {
            StackPush(&st, *temp);
        }
        else if (*temp == ')' || *temp == ']' || *temp == '}')
        {
            char get = StackPop(&st);
            if (!(get == '(' && *temp == ')') &&
                !(get == '[' && *temp == ']') && 
                !(get == '{' && *temp == '}') ||
                get == '\0')
            {
                return false;
            }
        }
        temp++;
    }
    if (st.top != 0)
	{
		return false;
	}
    return true;
}

int main()
{
	char* s = "([[][]])[][][][[{}]]";
	printf("%s\n", isValid(s) ? "true" : "false");
	return 0;
}