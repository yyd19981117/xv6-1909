#include "types.h"
#include "stat.h"
#include "user.h"

char p[4000];

int main(int argc, char *argv[])
{
	if(argc!=1)
	printf(1, "Usage: test_IO\n");
	else
	{
		int i, flag;
		int st=uptime();
		for(flag=0;flag<10;flag++)
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
		printf(1, "usetime=%d\n", ed-st);
	}
	exit();
}
