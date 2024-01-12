#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    FILE* fp = fopen("test.txt", "r");
//    if (!fp)
//    {
//        perror("File opening failed");
//        return EXIT_FAILURE;
//    }
//
//    int c;  // 注意：int，非char，要求处理EOF
//    while ((c = fgetc(fp)) != EOF)  // 标准C I/O读取文件循环
//    { 
//        putchar(c);
//    }
//
//    if (ferror(fp))
//        puts("I/O error when reading");
//    else if (feof(fp))
//        puts("End of file reached successfully");
//
//    fclose(fp);
//    fp = NULL;
//    return EXIT_SUCCESS;
//}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ret_code = 0;
    for (char c = 'a'; (ret_code != EOF) && (c != 'z'); c++)
        ret_code = putc(c, stdout);

    /* 测试是否抵达 EOF */
    if (ret_code == EOF)
        if (ferror(stdout))
        {
            perror("putc()");
            fprintf(stderr, "putc() failed in file %s at line # %d\n", __FILE__, __LINE__ - 7);
            exit(EXIT_FAILURE);
        }
    putc('\n', stdout);

    return EXIT_SUCCESS;
}