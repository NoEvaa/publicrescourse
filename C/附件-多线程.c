#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
//ִ���̵߳�һ������
void *do_thread(void *arg);
 
int main(void)
{
	//�����̵߳�id�� 
	pthread_t    tid ; 
	int ret ; 
	//����һ���߳� 
	ret = pthread_create(&tid , NULL , 	do_thread , NULL);
	if(ret != 0)
	{
		fprintf(stderr , "�����߳�ʧ��!\n");
		return -1 ; 
	}
	//���߳̽���ʱ�Զ��ͷ�id�� 
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
