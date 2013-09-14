// 68.把数组拍成最小的数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//完全抄袭
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
这题用到基数排序,也可以是字符串排序
对2个数，组成的可能是mn和mn,假如说是32,321,那么可能是32321和32132,此时32132是小的，同时字符串比较中32132<32321
*/

// Compare two numbers in strNumber1 and strNumber2
// if [strNumber1][strNumber2] > [strNumber2][strNumber1],
// return value > 0
// if [strNumber1][strNumber2] = [strNumber2][strNumber1],
// return value = 0
// if [strNumber1][strNumber2] < [strNumber2][strNumber1],
// return value < 0

// Maxinum int number has 10 digits in decimal system
const int g_MaxNumberLength = 10;
 
// String buffers to combine two numbers
char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];


int compare(const void* strNumber1, const void* strNumber2)
{
    // [strNumber1][strNumber2]
    strcpy(g_StrCombine1, *(const char**)strNumber1);
    strcat(g_StrCombine1, *(const char**)strNumber2);
 
    // [strNumber2][strNumber1]
    strcpy(g_StrCombine2, *(const char**)strNumber2);
    strcat(g_StrCombine2, *(const char**)strNumber1);
 
    return strcmp(g_StrCombine1, g_StrCombine2);
}


 
// Given an array, print  the minimum number
// by combining all numbers in the array
void PrintMinNumber(int* numbers, int length)
{
    if(numbers == NULL || length <= 0)
        return;
 
    // Convert all numbers as strings
    char** strNumbers = (char**)(new int[length]);
    for(int i = 0; i < length; ++i)
    {
        strNumbers[i] = new char[g_MaxNumberLength + 1];
        sprintf(strNumbers[i], "%d", numbers[i]);
    }
 
    // Sort all strings according to algorithm in function compare
    qsort(strNumbers, length, sizeof(char*), compare);
 
    for(int i = 0; i < length; ++i)
        printf("%s", strNumbers[i]);
    printf("\n");
 
    for(int i = 0; i < length; ++i)
        delete[] strNumbers[i];
    delete[] strNumbers;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={32,321,123,22};

	PrintMinNumber(a,4);

	system("pause");
	return 0;
}

