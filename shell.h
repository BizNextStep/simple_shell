#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//Funciton prototypes
void print_prompt(void);
char *read_input(void);
char **tokenize_input(char *input);
int execute_command(char **args);
void free_tokens(char **tokens);

#endif /* SHELL_H */
