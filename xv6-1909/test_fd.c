#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char fname[100];

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

int main(){
	char buf[512] = "1234567aisdlffioajsdfiulnweuifnsilugndsjkfanudakshfdsakjfhuasdfuidsjk89120481234uisduiehdfouiwefoiwejfoisdfadkslfewfsd";//缓冲区 
	int n=strlen(buf);//存取读取的字节数
	int i;
	
	fork();
	fork();
	int time = uptime();
	int pid=getpid();
	itoa(pid, fname);
	int fd=open(fname,O_RDWR | O_CREATE);//获取文件描述符 
	write(fd,buf,n);//再写回进去
	close(fd);//关闭文件 
	fd=open(fname,O_RDWR);
	n=read(fd,buf,sizeof buf);//读取字节 
	for(i = 0; i < 100; i++)
		write(fd,buf,n);//再写回进去
	close(fd);//关闭文件 
	printf(1, "pid:%d usetime:%d\n", getpid(), uptime()-time);
	while(wait() != -1)
		;
	exit();
}
