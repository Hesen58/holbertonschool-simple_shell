#include "main.h"
/**
 * cut_string - Create new array with strtok
 * @buf: user input.
 * @arr: array.
 *
 * Return: 2d array.
 */

char **cut_string(char *buf, char **arr)
{
	char *tok;
	int i = 0;
	int k;

	/*arr = NULL;*/
	tok = strtok(buf, " \n");
	if (tok == NULL)
	{
		return (NULL);
	}
	/*if(arr != NULL)
		free_arr(arr);*/
	arr = (char **)malloc(sizeof(char *) * 250);
	for (k = 0; k < 250; k++)
		arr[k] = NULL;
	while (tok != NULL)
	{
		if (strcmp(tok, "") != 0)
		{
			arr[i] = (char *)malloc(strlen(tok) + 1);
			strcpy(arr[i], tok);
			i++;
		}
		tok = strtok(NULL, " \n");
	}
	/*if (buf[0] == '\n')
		return (NULL);*/
	/*temp = env_path(buf);
	if (access(arr[0], X_OK) == 0)
	{
		return (arr);
	}
	else if (temp != NULL)
	{
		free(arr[0]);
		arr[0] = temp;
	}
	arr[i] = NULL;*/
	return (arr);
}
