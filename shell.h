#ifndef SHELL_H
#define Shell_h

#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void exec_c(char **args, char **envp);
char *look_for(char *command, char **envp);
char *createpath(char *dir, char *command);





#endif
