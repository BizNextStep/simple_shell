#include "shell.h"

/**
 * main - Entry point.
 *
 * Return: Success.
 */

int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *args[MAX_ARGS];
	char *token = strtok(input, " ");
	int status;
	int i = 0;
	pid_t pid;
	while (1)
	{
		printf(":) ");
		fgets(input, sizeof(input), stdin);
		input[strlen(input) - 1] = '\0';

		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, "");
			i++;
		}
		args[i] = NULL;

		pid = fork();

		if (pid == -1)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror("Error executing command");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
