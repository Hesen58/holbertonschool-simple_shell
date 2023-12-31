#include "main.h"

/**
 * check_env - checks if environment is not NULL
 * @arr: array of command.
 *
 * Return: 1 or 0.
 */

int check_env(char **arr)
{
	if (getenv("PATH") == NULL && arr[0][0] != '.' && arr[0][0] != '/'
			&& strcmp(arr[0], "env") != 0)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", arr[0]);
		free_arr(arr);
		return (1);
	}
	return (0);
}

/**
 * main - Simple shell.
 *
 * Return: Success.
 */

int main(void)
{
	int status = 0;
	int exit_flag = 0;

	while (!exit_flag)
	{
		char *input = NULL;
		size_t n = 0;
		char **arr;

		if (isatty(STDIN_FILENO))
		{
			printf("#cisfun$ ");
		}

		if (getline(&input, &n, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(input);
			break;
		}
		arr = split_command(input);
		if (arr == NULL)
			continue;
		handle_exit_command(arr, &exit_flag);
		if (!exit_flag)
		{
			if (check_env(arr))
				exit(127);
			status = execute_command(arr);
			free_arr(arr);
		}
	}
	return (status);
}
