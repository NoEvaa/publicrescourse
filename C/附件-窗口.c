#include <stdio.h>
#include <windows.h>

void screensize()
{
	HANDLE hOut; /*标准输出句柄*/
    COORD size = {45, 12}; /*窗口大小*/
    SMALL_RECT rc = {0, 0, 45-1, 12-1}; //要设置的窗口显示的大小和位置
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(hOut, TRUE, &rc);
    SetConsoleScreenBufferSize(hOut, size);
} 
