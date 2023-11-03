#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//1

//int main()
//{
//	char word1[1000] = { 0 };
//	char word2[1000] = { 0 };
//	gets(word1), gets(word2);
//	for (int i = 0; word1[i] != 0 || word2[i] != 0; i++)
//	{
//		printf("%c%c", word1[i], word2[i]);
//	}
//	return 0;
//}


//2
//char* mergeAlternately(char* word1, char* word2) {
//    int temp = 0;
//    char* ret = (char*)malloc((strlen(word1) + strlen(word2) + 1) * sizeof(char));
//    int flag1 = 0, flag2 = 0;
//    while (flag1 < strlen(word1) && flag2 < strlen(word2)) {
//        ret[temp++] = word1[flag1++];
//        ret[temp++] = word2[flag2++];
//    }
//    while (flag1 < strlen(word1)) {
//        ret[temp++] = word1[flag1++];
//    }
//    while (flag2 < strlen(word2)) {
//        ret[temp++] = word2[flag2++];
//    }
//    ret[temp] = '\0';
//    return ret;
//}
