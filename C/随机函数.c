#include<stdio.h>
#include <time.h>

int main(){
	srand(time(NULL));//ʱ������ 
	int i=0;
	for(;i<10;i++){
		int random_int = rand()%100;//[0,99] 
		printf("%d\n",random_int);
	}
} 
/*
���С��
(rand()%10)/10
�������
-(rand()%10)
���������
rand()%10+1 
*/
