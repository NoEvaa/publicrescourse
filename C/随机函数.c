#include<stdio.h>
#include <time.h>

int main(){
	srand(time(NULL));//时间种子 
	int i=0;
	for(;i<10;i++){
		int random_int = rand()%100;//[0,99] 
		printf("%d\n",random_int);
	}
} 
/*
随机小数
(rand()%10)/10
随机负数
-(rand()%10)
随机正整数
rand()%10+1 
*/
