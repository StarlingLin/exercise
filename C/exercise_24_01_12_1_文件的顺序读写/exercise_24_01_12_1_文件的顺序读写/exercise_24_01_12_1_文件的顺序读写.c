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

//#include <stdio.h>
//#include <stdlib.h>
//
//int main(void)
//{
//    int ret_code = 0;
//    for (char c = 'a'; (ret_code != EOF) && (c != 'z'); c++)
//        ret_code = putc(c, stdout);
//
//    /* 测试是否抵达 EOF */
//    if (ret_code == EOF)
//        if (ferror(stdout))
//        {
//            perror("putc()");
//            fprintf(stderr, "putc() failed in file %s at line # %d\n", __FILE__, __LINE__ - 7);
//            exit(EXIT_FAILURE);
//        }
//    putc('\n', stdout);
//
//    return EXIT_SUCCESS;
//}

//#include <stdio.h>
//
//int main(void)
//{
//    int rc = fputs("Hello world!", stdout);
//
//    if (rc == EOF)
//        perror("fputs()"); // POSIX 要求设置 errno
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//
//int main()
//{
//	struct Stu s = { "zhangsan", 20, 99.9 };
//	struct Stu d = { 0 };
//
//	FILE* pf = fopen("dat.txt", "w+b");
//	if (!pf)
//	{
//		perror("fopen");
//		return EXIT_FAILURE;
//	}
//
//	fwrite(&s, sizeof(s), 1, pf);
//	fseek(pf, 0, SEEK_SET);
//	fread(&d, sizeof(s), 1, pf);
//	printf("%s %d %.1f", d.name, d.age, d.score);
//	
//	fclose(pf);
//	pf = NULL;
//	return EXIT_SUCCESS;
//}