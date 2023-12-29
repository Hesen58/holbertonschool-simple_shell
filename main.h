#ifndef HEADER_FILE
#define HEADER_FILE
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
extern char **environ;
char **split_command(char *input);
void free_arr(char **arr);
int execute_command(char **arr);
void handle_exit_command(char **arr, int *exit_flag);
#endif
