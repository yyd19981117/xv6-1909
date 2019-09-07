#include "types.h"

#include "user.h"

#include "stat.h"





#define MAX_TRSIZE 300

#define NUM_THREADS 2

#define SEMAPHORE_NUM 0



char p[4000];



void test1(){



		int i, flag;

		int st=uptime();

		for(flag=0;flag<1000;flag++)

		{

		for(i=0;i<2000;i++){

			*(p+i)=i&0x0f;

		}

		for(i=0;i<=2000;i++){

			*(p+i+2000)=(*(p+i))&0x0f;

		}

		for(i=0;i<=4000;i++){

		    *(p+i)=i&0x0f;

		}

		}

		int ed=uptime();

		printf(1, "pid:%d usetime=%d\n", getpid(),ed-st);

	//printf(1, "pid:%d  result = %d usetime:%d \n", getpid(), sum, time);

	exit();

	

}



int main(int argc, char *argv[])

{

	int a;

	if(argc > 2)

	{

		printf(1, "enter \"CPUtest (seed)\" to run this test program!\n");

		exit();

	}

	a=uptime();

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

	a=uptime()-a;

	printf(1,"total time:%d\n",a);

	exit();

}
