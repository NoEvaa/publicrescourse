#include <stdio.h>
#include <windows.h>

void screensize()
{
	HANDLE hOut; /*��׼������*/
    COORD size = {45, 12}; /*���ڴ�С*/
    SMALL_RECT rc = {0, 0, 45-1, 12-1}; //Ҫ���õĴ�����ʾ�Ĵ�С��λ��
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(hOut, TRUE, &rc);
    SetConsoleScreenBufferSize(hOut, size);
} 
