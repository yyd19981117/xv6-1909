#include "types.h"
#include "user.h"
#include "stat.h"

#define MAX_TRSIZE 300

int a[MAX_TRSIZE][MAX_TRSIZE];
int b[MAX_TRSIZE][MAX_TRSIZE];
int c[MAX_TRSIZE][MAX_TRSIZE];

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
	}else
	{
		sed = uptime();
	}	
	
	printf(1, "seed = %d\n", sed);
	seed(sed);
	
	int i,j,k;
	
	int sum = 0;
	
	//随机生成数据
	for(i = 0; i < MAX_TRSIZE; i++)
	{
		for(j = 0; j < MAX_TRSIZE; j++)
		{
			a[i][j]=  (urand() * 100.0 / RAND_MAX) - 50;
			b[i][j]=  (urand() * 100.0 / RAND_MAX) - 50;
			c[i][j]= 0;
		}
	}

	
	//计算
	fork();
	fork();

	int time = uptime();
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
	
	//输出防止计算被编译器优化
	for(i = 0; i < MAX_TRSIZE; i++)
	{
		for(j = 0; j < MAX_TRSIZE; j++)
		{
			sum += c[i][j];
		}
	}
	time = uptime() - time;
	printf(1, "pid:%d  result = %d usetime:%d \n", getpid(), sum, time);
	getstride();
	while(wait()!=-1)
	;
	exit();
}
