#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
//执行线程的一个函数
void *do_thread(void *arg);
 
int main(void)
{
	//创建线程的id号 
	pthread_t    tid ; 
	int ret ; 
	//创建一条线程 
	ret = pthread_create(&tid , NULL , 	do_thread , NULL);
	if(ret != 0)
	{
		fprintf(stderr , "创建线程失败!\n");
		return -1 ; 
	}
	//当线程结束时自动释放id号 
	ret = pthread_detach(tid);	
	while(1)
	{
		printf("Hello world1!\n\n");
		sleep(1);
	}
	return 0 ; 
}
void *do_thread(void *arg)
{
	while(1)
	{
		printf("Hello world2!\n\n");
		sleep(1);
	}
}
