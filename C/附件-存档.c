#include<stdio.h>

void save(int i);       //±£´æ 


int main()
{
	int level;
	FILE *fp;
    fp = fopen("file.txt", "r");
    if(fp == NULL)
     {
     	printf("fail to read the data! \n");
     	fclose(fp);
     	save(1);
	 }
    else
    {
      fscanf(fp, "%d", &level);
      
      switch(level)
      {
      	case 1:printf("hello");     save(2);break;
      	case 2:printf("mr xu");      save(3);
      	case 3:printf("goodbye");break;
      	
	  }
    }
	
	return 0;
}

void save(int i)
{
	FILE *fp;
    fp = fopen("file.txt", "w");
    fprintf(fp,"%d",i);
} 
