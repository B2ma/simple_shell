#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stddef.h>


int _execute_cmd(char *args, struct stat *statbuffer, char **envp);
bool file_exists(char *pathname, struct stat *statbuffer);
void errorHandler(pid_t pid);

#endif /*SHELL_H*/
