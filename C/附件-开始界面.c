#include<stdio.h>
#include <windows.h>
#include<stdlib.h>

HANDLE hInput; /* ��ȡ��׼�����豸��� */
INPUT_RECORD inRec;/* �������ݼ�¼ */
DWORD numRead; /* �����Ѷ�ȡ�ļ�¼�� */
int Y,X;/* X��Y������ */

void startface();
void gtxy(int x,int y);     //����ƶ�
void HideCursor();           //���ع��
int mouseput();

int main()
{
	HideCursor();
	startface();
	printf("hello");
	
	return 0;
}
void gtxy(int x,int y)  //����ƶ�������X��ʾ�����꣬Y��ʾ�����ꡣ
{
	COORD  coord;         //ʹ��ͷ�ļ��Դ�������ṹ
	coord.X=x;            //���ｫint����ֵ����short,�����������漰������ֵ�����ᳬ��short��Χ
	coord.Y=y;
	HANDLE a=GetStdHandle(STD_OUTPUT_HANDLE);  //��ñ�׼������
	SetConsoleCursorPosition(a,coord);         //�Ա�׼����ľ��Ϊ�������ÿ���̨�������
}

void HideCursor()  //���ع��
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
	printf("������... "); 
	//gtxy(10,5);
	for(v=0;v<10;v++)
	{
		gtxy(10+v*2,5);
		printf("��");
		gtxy(20,6);
		printf("%3d%%",(v+1)*10);
		Sleep(500);
	}
	gtxy(10,6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	printf("�������           "); 
	gtxy(10,8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
	printf("��������Լ���...................");
	HWND hwnd=FindWindow("ConsoleWindowClass",NULL);  //����̨���ھ�� 
	hInput = GetStdHandle(STD_INPUT_HANDLE);   //�����豸��� 
	int rt;
	int k=1;
	while(k)
	{
	    ReadConsoleInput(hInput, &inRec, 1, &numRead);         //��ȡ1�������¼� 
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
		  
		   break;        //��� 
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
    if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) //����Ҽ����� 
      return 1;
    if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //���������� 
      return 2;
  }
} 

