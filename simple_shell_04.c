#include "shell.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *args[MAX_ARGS];
	int status;
	pid_t pid;

		while (1)
		{
			displayPrompt();
			fgets(input, sizeof(input), stdin);
			input[strlen(input) - 1] = '\0';
			if (strcmp(input, "exit") == 0)
			{
				printf("Exiting shell...\n");
				exit(EXIT_SUCCESS);
			}
			
			tokenizeInput(input, args);
			pid = fork();

			if (pid == -1)

			{
				perror("Fork failed");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				executeCommand(args);
			}
			else
			{
				wait(&status);
			}
		}
		return (0);
}

/**
 * displayPrompt - Displays the shell prompt
 */
void displayPrompt(void)
{
	printf(";) ");
}

/**
 * tokenizeInput - Tokenizes the input command
 * @input: The input command
 * @args: The array to store the tokenized command
 */
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

/**
 * executeCommand - Executes the input command
 * @args: The tokenized command
 */
void executeCommand(char *args[])
{
	if (execvp(args[0], args) == -1)
	{
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
}
