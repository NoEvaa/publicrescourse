#include <stdio.h>
#include <windows.h>
int main()
{

    int a=0,b=0,c=0;
    while(a>=0)
    {
    	while(a<=59)
    	{ 
	        while(b<=59)
	        {
		        Sleep(1000);                                          //��ͣ������WINϵͳ��Ϊ��дS,�������windows.hͷ�ļ�
		        system("cls");                                            //���� 
		        printf("��ʱ��ʼ:\n\n         %dʱ%d��%d��\n",c,a,b);  //�����ʱ
		        b=b+1;
	        }
    		a=a+1;
    		b=0;
    	}
    	c=c+1;
    	a=0;
    }
	return 0;
}

/* 
        while(1)
        {
            t=0;
            while(cc)
            {
            	Sleep(1000);                                          //��ͣ����
                gtxy(30,4);
		        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);                                            
                printf("%4d",t);    //�����ʱ
                t=t+1;
			}
        	         
        }
*/
