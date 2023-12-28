#include "main.h"
/**
 * main - Simple shell.
 *
 * Return: Success.
 */

int main(void)
{
	int status = 0;

	while (1)
	{
		char *buf = NULL;
		size_t n = 0;
		int i;
		char **arr;

		if (isatty(STDIN_FILENO))
		{
			printf("#cisfun$ ");
		}

		if (getline(&buf, &n, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(buf);
			break;
		}
		arr = cut_string(buf);
		if (arr == NULL)
			continue;
		/*handle_exit_command(arr);*/
        for (i = 0; arr[i] != NULL; i++)
        {
                if (strcmp(arr[i], "exit") == 0)
                {
                        if (arr[1] == NULL)
                        {
                                free_arr(arr);
                                exit(0);
                        }
                        else if(access(arr[0], X_OK) == -1)
                        {
                                free_arr(arr);
                                exit(2);
                        }
                }

        }
		if (getenv("PATH") == NULL && arr[0][0] != '.' && arr[0][0] != '/')
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", arr[0]);
			free_arr(arr);
			exit(127);
		}
		status = execute_command(arr);
		free_arr(arr);
	}
	return (status);
}
