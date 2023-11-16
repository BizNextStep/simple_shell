#include "shell.h"

/**
 * runShell - makes the input command executable.
 */
void runShell(void)
{
	while (1)
	{
		char input[MAX_INPUT_SIZE];
		char *token;
		char *args[MAX_ARGS];
		int i = 0;

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

			token = strtok(input, " ");
			i = 0;

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
}
