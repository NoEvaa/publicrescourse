#include<stdio.h>
#include <windows.h>
#include<stdlib.h>

HANDLE hInput; /* 获取标准输入设备句柄 */
INPUT_RECORD inRec;/* 返回数据记录 */
DWORD numRead; /* 返回已读取的记录数 */
int Y,X;/* X和Y的坐标 */

void startface();
void gtxy(int x,int y);     //光标移动
void HideCursor();           //隐藏光标
int mouseput();

int main()
{
	HideCursor();
	startface();
	printf("hello");
	
	return 0;
}
void gtxy(int x,int y)  //光标移动函数，X表示横坐标，Y表示纵坐标。
{
	COORD  coord;         //使用头文件自带的坐标结构
	coord.X=x;            //这里将int类型值传给short,不过程序中涉及的坐标值均不会超过short范围
	coord.Y=y;
	HANDLE a=GetStdHandle(STD_OUTPUT_HANDLE);  //获得标准输出句柄
	SetConsoleCursorPosition(a,coord);         //以标准输出的句柄为参数设置控制台光标坐标
}

void HideCursor()  //隐藏光标
{                  
	CONSOLE_CURSOR_INFO cursor_info={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info); 
}
void startface()
{
	int v;
	gtxy(14,3);
	printf("title");
	gtxy(10,6);
	printf("加载中... "); 
	//gtxy(10,5);
	for(v=0;v<10;v++)
	{
		gtxy(10+v*2,5);
		printf("▊");
		gtxy(20,6);
		printf("%3d%%",(v+1)*10);
		Sleep(500);
	}
	gtxy(10,6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	printf("加载完成           "); 
	gtxy(10,8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
	printf("单击鼠标以继续...................");
	HWND hwnd=FindWindow("ConsoleWindowClass",NULL);  //控制台窗口句柄 
	hInput = GetStdHandle(STD_INPUT_HANDLE);   //输入设备句柄 
	int rt;
	int k=1;
	while(k)
	{
	    ReadConsoleInput(hInput, &inRec, 1, &numRead);         //读取1个输入事件 
		switch(inRec.EventType)
		{ 
		case MOUSE_EVENT:
		  { 
		  rt=mouseput(); 
		  switch(rt)
		   {  
          case 2: {
          	           k=0;
		          }
		  
		   break;        //左键 
		  }
		} 		 
		 break; 
		}
	}
	//return;
    
}
int mouseput()
{
  while(1)
  {
    COORD pos = {0,0};
    ReadConsoleInput(hInput, &inRec, 1, &numRead);
    pos = inRec.Event.MouseEvent.dwMousePosition;
    Y=(int)pos.Y;
    X=(int)pos.X;
    if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) //鼠标右键单击 
      return 1;
    if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //鼠标左键单击 
      return 2;
  }
} 

