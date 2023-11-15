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
	int status;

	while (1)
	{
		printf(":) ");
		fgets(input, sizeof(input), stdin);
		input[strlen(input) - 1] = '\0';
		char *token = strto(input " ");
		int i = 0;

		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, "");
			i++;
		}
		args[i] = NULL;
		pid_t pid = fork();

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
