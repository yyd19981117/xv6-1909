#include "types.h"
#include "user.h"
#include "stat.h"

#define MAX_TRSIZE 300
#define NUM_THREADS 2
#define SEMAPHORE_NUM 0

int a[MAX_TRSIZE][MAX_TRSIZE];
int b[MAX_TRSIZE][MAX_TRSIZE];
int c[MAX_TRSIZE][MAX_TRSIZE];

void test1(){
	int time = uptime();
	int i,j,k;
	int sum = 0;
	for(i = 0; i < MAX_TRSIZE; i++)
	{
		for(j = 0; j < MAX_TRSIZE; j++)
		{
			for(k = 0; k < MAX_TRSIZE; k ++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(i = 0; i < MAX_TRSIZE; i++)
	{
		for(j = 0; j < MAX_TRSIZE; j++)
		{
			sum += c[i][j];
		}
	}
	time = uptime() - time;
	printf(1, "pid:%d  result = %d usetime:%d \n", getpid(), sum, time);
	exit();
}

int main(int argc, char *argv[])
{
	uint sed = 0;
	if(argc > 2)
	{
		printf(1, "enter \"CPUtest (seed)\" to run this test program!\n");
		exit();
	}
	if(argc == 2)
	{
		sed = atoi(argv[1]);
	}else{
		sed = uptime();
	}	
	printf(1, "seed = %d\n", sed);
	seed(sed);
	int i,j;
	for(i = 0; i < MAX_TRSIZE; i++)
	{
		for(j = 0; j < MAX_TRSIZE; j++)
		{
			a[i][j]=(urand() * 100.0 / RAND_MAX) - 50;
			b[i][j]=(urand() * 100.0 / RAND_MAX) - 50;
			c[i][j]=0;
		}
	}
	fork();
	fork();
	thread_create(test1,0);
	thread_create(test1,0);
	thread_create(test1,0);
	thread_join();
	thread_join();
	thread_join();
	while(wait()!=-1)
		;
	exit();
}
