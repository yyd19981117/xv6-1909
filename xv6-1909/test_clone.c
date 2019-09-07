#include "types.h"
#include "user.h"

int a[10]={1,2,3,4,5,6,7,8,9,10};

void run1(){
	int sum=0,i=0,j=0;
	for(i=0;i<1;i++)
	{
		for(j=0;j<10;j++)
		sum+=a[j];
	}
	//printf(1,"sum is %d!\n",sum);
	printf(1,"thread func run1 exited with %d.\n",sum);
	exit();
}

void run2(){
	int sum=0,i=0,j=0;
	for(i=0;i<20;i++)
	{
		for(j=0;j<10;j++)
		sum+=a[j];
	}
	//printf(1,"sum is %d!\n",sum);
	printf(1,"thread func run2 exited with %d.\n",sum);
	exit();
}

void run3(){
	int sum=0,i=0,j=0;
	for(i=0;i<300;i++)
	{
		for(j=0;j<10;j++)
		sum+=a[j];
	}
	//printf(1,"sum is %d!\n",sum);
	printf(1,"thread func run3 exited with %d.\n",sum);
	exit();
}

int main(int argc,char **argv){	
	thread_create(run1,0);
	thread_create(run2,0);
	thread_create(run3,0);
	thread_join();
	thread_join();
	thread_join();
	exit();
}
