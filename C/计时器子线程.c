#include<stdio.h>
#include<time.h>
#include<pthread.h>

void *timer(void *arg){
	int t;
	while(1)
        {
            t = 1;
            while(1)
            {
            	Sleep(1000);
            	printf("%d\n",t);
                t += 1;
			}       
        }
}
int main(){
	pthread_t tid; 
	int re;
	re = pthread_create(&tid,NULL,timer,NULL);//计时器线程 
	if(re!=0)
	{
		return; 
	}
	re = pthread_detach(tid);
	for(;;){
		printf("t");
		Sleep(1000);
		//主线程
	}
}
