#include "shell.h"

int main(void)
{
	char *input;
	char **args;

	while (1)
	{
		print_prompt();
		input = read_input();
		args = tokenize_input(input);
		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit) ==0)
			{
				free(input);
				free_tokens(args);
				break;
			}
			else
			{
				if (execute_command(args) == -1)
				{
					fprintf(stderr, "Error executing
			command\n");
			}
		}
	}

	return 0;
}
