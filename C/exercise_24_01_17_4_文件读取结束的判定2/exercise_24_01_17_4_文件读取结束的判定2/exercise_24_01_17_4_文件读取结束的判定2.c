#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

enum { SIZE = 5 };
double a[SIZE] = { 1.,2.,3.,4.,5. };
double b[SIZE];

int main()
{
    FILE* fp = fopen("test.bin", "wb"); // �����ö�����ģʽ
    if (!fp)
    {
        perror("fopen-wb");
        return EXIT_FAILURE;
    }


    fwrite(a, sizeof * a, SIZE, fp); // д double ������
    fclose(fp);

    fp = fopen("test.bin", "rb");
    if (!fp)
    {
        perror("fopen-rb");
        return EXIT_FAILURE;
    }

    size_t ret_code = fread(b, sizeof * b, SIZE, fp); // �� double ������
    if (ret_code == SIZE)
    {
        puts("Array read successfully, contents: ");
        for (int n = 0; n < SIZE; ++n) printf("%f ", b[n]);
        putchar('\n');
    }
    else
    {
        if (feof(fp))
            printf("Error reading test.bin: unexpected end of file\n");
        else if (ferror(fp))
            perror("Error reading test.bin");
    } // error handling

    fclose(fp);
    fp = NULL;
    return EXIT_SUCCESS;
}