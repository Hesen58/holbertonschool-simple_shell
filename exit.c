#include "main.h"

/**
 * handle_exit_command - handle exit.
 * @arr: array of commands.
 *
 * Return: Status code.
 */
void handle_exit_command(char **arr)
{
	int i;

	for (i = 0; arr[i] != NULL; i++)
	{
		if (strcmp(arr[i], "exit") == 0)
		{
			if (arr[1] == NULL)
			{
				free_arr(arr);
				exit(0);
			}
			else
			{
				free_arr(arr);
				exit(2);
			}
		}

	}
}
