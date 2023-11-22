#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//5 times faster than scanf
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch>'9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return x * f;
}

void write(int x)
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
    return;
}

////only positive
//#define read(a) {char c;while((c=getchar())>47) a=a*10+(c^48);}

int main()
{
    int a = read();
    printf("%d", a);
    write(a);

    return main();
}