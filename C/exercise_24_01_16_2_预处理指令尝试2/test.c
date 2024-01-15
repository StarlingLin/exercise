#include <stdio.h>
#define DEBUG_PRINT printf("file:%s\nline:%d\ndate:%s\ntime:%s\n",\
                            __FILE__, __LINE__,\
                            __DATE__, __TIME__ \
                        )

int main()
{
    DEBUG_PRINT;
    return 0;
}