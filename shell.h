#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

extern char **environ;

/*Funciton prototypes */
void runShell(void);
void displayPrompt(void);
void tokenizeInput(char *input, char *args[]);
void executeCommand(char *args[]);
void handleEnvCommand(void);

#endif /* SHELL_H */
