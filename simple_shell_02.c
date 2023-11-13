#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

void displayPrompt(void)
{
	printf("#cisfun$ ");
}

void tokenizeInput(char *input, char *args[])
{
	char *token = strtok(input, " ");
	int i = 0;

	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
}
void executeCommand(char *args[])
{
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
		else
		{
			wait(NULL);
		}
	}
}
int main(void)
{
	char input[MAX_INPUT_SIZE];

	while (1)
	{
		displayPrompt();
		fgets(input, sizeof(input), stdin);
		if (strcmp(input, "exit\n") == 0)
		{
			printf("Exiting shell...\n");
			break;
		}
		input[strlent(input) - 1] = '\0';
		char *args[MAX_ARGS];

		tokenizeInput(input, args);
		executeCommand(args);
	}
	return (0);
}
