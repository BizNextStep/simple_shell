#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

int main(void)
{
	char input[MAX_INPUT_SIZE];

	while (1)
	{
		printf("#cisfun$ ");
		fgets(input, sizeof(input), stdin);

		if (strcmp(input, "exit\n") == 0)
		{
			printf("Exiting shell...\n");
			break;
		}

		input[strlen(input) - 1] = '\0';

		char *token = strtok(input, " ");
		char *args[MAX_ARGS];

		int i = 0;

		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}

		args[i] = NULL;

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror("./hsh");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}
