#include "sys/types.h"
#include "sys/wait.h"
#include "stdio.h"
#include "unistd.h"

#define N 5
#define READ_END 0
#define WRITE_END 1

int A = 0;
int B = 0;

int main(void)
{
	int fd[2];
	pid_t pid;

	if(pipe(fd) == -1)
	{
		printf("fail\n");
		return 1;
	}

	pid = fork();
	if(pid < 0)
	{
		return 1;
	}
	else if(pid > 0)
	{
		close(fd[READ_END]);

		for (int i = 0; i < N; ++i)
		{
			write(fd[WRITE_END], &A, sizeof(A));
			A = A + 1;
		}

		wait(NULL);
		printf("B: %d\n", B);

		close(fd[WRITE_END]);
	}
	else
	{
		close(fd[WRITE_END]);

		int temp_value;

		for (int i = 0; i < N; ++i)
		{
			read(fd[READ_END], &temp_value, sizeof(temp_value));
			B = B + 1;
			A = A + 1;
			printf("temp_value: %d\n", temp_value);
		}

		close(fd[READ_END]);
	}
	return 0;
}