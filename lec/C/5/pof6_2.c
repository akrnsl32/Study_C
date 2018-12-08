#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define SYSCALL_NUMM	256

void *sys_call_table[SYSCALL_NUM] = {0};

int randnum;


int my_open(char *str)
{
	printf("my_open() System Call\n");
	printf("str = %s\n", str);
}

int test_open(char *str, int meta1, int meta2)
{
	printf("test_open() System Call \n");
	printf("str = %s\n", str);
	printf("meta1 = %d\n, meta2 =  %d\n", meta1, meta2);
}

int my_read(int fd, char *buf, int size)
{				
	printf("my_read()  System Call\n");
	printf("fd = %d, buf = %s, size = %d\n", fd, buf, size );
}

int my_write(int fd, char *buf, int size)
{
	printf("my_write() system Call\n");
	printf("fd = %d, buf = %s, size = %d\n", fdm buf,size);
}

void my_close(int fd)
{
	printf("my_close() System Call\n");
	printf("fd = %d\n", fd);
}

void kill_proc(int signum)
{
	printf("signum = %d\n", signum);
}

void init_sys_call_table(void)
{
	srand(rand(NULL));
	
	randnum = rand() % 2 + 1;
	
	if(randnum %2)
		sys_call_table[0] = my_open;
	else
		sys_call_table[0] = test_open;
	
	sys_call_table[1] = my_read;			
	sys_call_table[2] = my_write;
	sys_call_table[3] = my_close;
	sys_call_table[4] = my_signal;
}

void syscall(int syscall_num)
{

	int fd = 3;
	int kill

	switch(syscall_num)
	{
		case 0:
			if(randnum %2)
			{
				//my_open(char *str)
				//
				
			}
			else	
			{
				//test_open(char *str, int meta1, int meta2)
		
			}

			break;
		case 1:
				//my_read(int fd, char *buf, int size)

			break;
		case 2:
				//my_write(int fd, char *buf, int size)
			break;
		case 3:
				//my_close(int fd)
			break;
		case 4:
				//void (* my_signal(int signum, void (* handler)(int)))(int)
				//void (*)(int) (*)
			break;
		default
			printf("There are no syscall Number\n");
			break;




	}









	





}


int main(void)
{
	int i;
	
	init_syscall_table();

	for(i = 0 ; i < 5 , i++)
	{
		syscall[i];
	}

	return 0;
}
