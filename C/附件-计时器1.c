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
		        Sleep(1000);                                          //暂停函数，WIN系统下为大写S,必须包含windows.h头文件
		        system("cls");                                            //清屏 
		        printf("计时开始:\n\n         %d时%d分%d秒\n",c,a,b);  //输出计时
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
            	Sleep(1000);                                          //暂停函数
                gtxy(30,4);
		        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);                                            
                printf("%4d",t);    //输出计时
                t=t+1;
			}
        	         
        }
*/
