#include <stdio.h>

#define SYSCALL_NUM	256

void *sys_call_table[SYSCALL_NUM] = {0};
	
int my_open(char *str)
{
	printf("my_open \n "); 
	printf("str = %s\n", str);
}

int my_read(int fd, char *buf, int size)
{
	printf("my_read \n "); 
	printf("fd = %d, buf = %s, size = %d \n", fd, buf, size);
}

int my_write(int fd, char *buf , int size)
{

	printf("my_write \n "); 
}

void my_close(int fd)
{
	printf("my_close \n "); 
}

void (* my_signal(int signum, void (* handler)(int)))(int)
{
	//void (*) 


	printf("my_signal \n "); 
}

/*
	만약 NTFS 파일 시스템이면 ntfs_open;
	만약 NTFS 파일 시스템이면 ntfs_open;
	만약 NTFS 파일 시스템이면 ntfs_open;
	만약 NTFS 파일 시스템이면 ntfs_open;
	만약 NTFS 파일 시스템이면 ntfs_open;






*/

void init_sys_call_table(void)
{
	sys_call_table[0] = my_open;
	sys_call_table[1] = my_read;
	sys_call_table[2] = my_write;
	sys_call_table[3] = my_close;
	sys_call_table[4] = my_signal;
}

void syscall(int syscall_num)
{
	//fd = 파일디스크립터 함수포인터가 어떤 상황에서 사용되는지
	char filenale[32] = "test.txt"
	switch(syscall_num)
	{
		case 0:
		((int (*)(char *))sys_call_table[0])(3);
		brake;
	}	



}


int main(void)
{
	int i;
	
	init_sys_cal_table(sys_call_table);
	
	for(i = 0; i < 5; i++)
	{
		syscall(i);
	}

	return 0;
}
