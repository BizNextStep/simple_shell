#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

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

void handleEnvCommand()
{
    char **env = environ;
    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
}

int main(void)
{
    char input[MAX_INPUT_SIZE];

    while (1)
    {
        printf("$ ");
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

    return (0);
}
