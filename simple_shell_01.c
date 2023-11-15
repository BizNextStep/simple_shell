#include "shell.h"

/**
 * main - Entry point.
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	char *args[] = {"/bin/ls", NULL};
	pid_t child_pid;
	int status;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);

		child_pid = fork();


		if (child_pid < 0)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("./hsh");
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}

	return (0);
}
