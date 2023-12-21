#include "main.h"
/**
 * main - Simple shell.
 *
 * Return: Success.
 */

int main(void)
{
  while (1)
	{
		char *hay;
		size_t n;
		char **arr;
		pid_t id;
		size_t symb;

		symb = getline(&hay, &n, stdin) - 1;
		hay[symb] = '\0';	
		arr = cut_string(hay, arr);
		id = fork();

		if (id == 0)
		{
			if (execve(arr[0], arr, environ) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
