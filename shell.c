#include "shell.h"

/**
 * runShell - makes the input command executable.
 */
void runShell(void)
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

	else if (strcmp(input, "env\n") == 0)
	{
		handleEnvCommand();
	}
	else
	{
		input[strlen(input) - 1] = '\0'; /* Removing the newline character */
	}
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
	executeCommand(args);
	}
}
/**
 * displayPrompt - displays "$" to accept input
 */
void displayPrompt(void)
{
	printf("$ ");
}
/**
 * tokenizeInput - breaks the strings into smaller parts using delimeters
 * @input: parameter
 * @args: Second parameter
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
 * executeCommand - executes the input command
 * @args: pointer
 */
void executeCommand(char *args[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("./simple_shell");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execvp(args[0], args) == -1)
		{
			perror("./simple_shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		wait(NULL);
	}
}
/**
 * handleEnvCommand - handles environment to execute command
 */
void handleEnvCommand(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
