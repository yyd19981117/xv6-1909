#include "types.h"

#include "user.h"

#include "stat.h"

#include"fcntl.h"



#define MAX_TRSIZE 300

#define NUM_THREADS 2

#define SEMAPHORE_NUM 0









void itoa(int i, char *s)

{

	int j, x, k;

	char tmp[100];

	tmp[0] = '0';

	for(j = 0; i!=0 ; j++)

	{

		x = i % 10;

		i /= 10;

		tmp[j] = x + '0';

	}

	for(k = 0; k < j; k++)

	{

		s[k] = tmp[j-1-k];

	}

	return;

}



void test1(){
	char fname[100];
	char buf[512] = "1236463457fhfgjgfjftgjgfrfh";//缓冲区 

	int n=strlen(buf);//存取读取的字节数

	int i;

	int time = uptime();

	int pid=getpid();
//	printf(1, "%d will be make\n", pid);

	itoa(pid, fname);

	int fd=open(fname,O_RDWR | O_CREATE);//获取文件描述符 
//	printf(1, "%d is make\n", pid);//
//	printf(1, buf);
//	printf(1, "\n%d %d\n",fd, n);

	write(fd,buf,n);//写入
//	printf(1, "%d will be close\n", pid);

	close(fd);//关闭文件 
//	printf(1, "%d is close\n", pid);

	fd=open(fname,O_RDWR);
//	printf(1, "%d is open\n", pid);

	n=read(fd,buf,sizeof(buf));//读取字节 

	for(i = 0; i < 100; i++)

		write(fd,buf,n);//再写回进去

	close(fd);//关闭文件 
//	printf(1, "%d is close\n", pid);

	printf(1, "pid:%d usetime:%d\n", getpid(), uptime()-time);

	exit();



}



int main(int argc, char *argv[])

{

	int a;
	int flag;
 	flag=fork();
	flag=fork()&&flag;

	a=uptime();

	thread_create(test1,0);

	thread_create(test1,0);

	thread_create(test1,0);

	thread_join();

	thread_join();

	thread_join();

	while(wait()!=-1)

		;

	a=uptime()-a;
	if(flag)
	printf(1,"total time:%d\n",a);

	exit();

} 
