#include "shell.h"

/**
 * displayPrompt - displays prompt to input command.
 */
void displayPrompt(void)
{
	printf("#cisfun$ ");
}

/**
 * tokenizeInput - Breaks string into small input using delimeters
 * @input: parameter.
 * @args: parameter..
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
 * executeCommand - executes command passed into the shell
 * @args: parameter
 */
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

/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *args[MAX_ARGS];

	while (1)
	{
		displayPrompt();
		fgets(input, sizeof(input), stdin);
		if (strcmp(input, "exit\n") == 0)
		{
			printf("Exiting shell...\n");
			break;
		}
		input[strlen(input) - 1] = '\0';
		/*char *args[MAX_ARGS];*/

		tokenizeInput(input, args);
		executeCommand(args);
	}
	return (0);
}
