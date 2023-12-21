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
		char *buf = NULL, *str, **arr;
		size_t bufsize;
		int i = 0, symb;
		pid_t chid;

		symb = getline(&buf, &bufsize, stdin);
		if (symb == EOF)
		{
			break;
		}
		arr = malloc(sizeof(char *) * 10);
		while ((str = strtok_r(buf, " \n", &buf)))
		{
			arr[i] = malloc(sizeof(char) * strlen(str));
			arr[i] = str;
			i++;
		}
		arr[i] = NULL;
		chid = fork();
		if (chid == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		if (chid == 0)
		{
			if (execve(arr[0], arr, environ) == -1)
			{
				perror("Error");
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
