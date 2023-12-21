#ifndef HEADER_FILE
#define HEADER_FILE
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
extern char **environ;
char **cut_string(char *hay, char **arr);
void free_arr(char **arr);
#endif
