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
//    int c;  // ע�⣺int����char��Ҫ����EOF
//    while ((c = fgetc(fp)) != EOF)  // ��׼C I/O��ȡ�ļ�ѭ��
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

    /* �����Ƿ�ִ� EOF */
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