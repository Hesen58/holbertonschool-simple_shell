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
	char *tok, /*bin = strcat(env_path(), "/"),*/ *temp;
	int i = 0;
	int k;
	struct stat st;

	arr = NULL;

	tok = strtok(buf, " \n");
	if (tok == NULL)
	{
		return (NULL);
	}
	if(arr != NULL)
		free_arr(arr);
	arr = (char **)malloc(sizeof(char *) * 250);
	for (k = 0; k < 250; k++)
		arr[k] = NULL;
	while (tok != NULL)
	{
		arr[i] = (char *)malloc(strlen(tok) + 1);
		strcpy(arr[i], tok);

		tok = strtok(NULL, " \n");
		i++;
	}
	if (buf[0] == '\n')
		return (NULL);
	if (access(arr[0], X_OK) == 0)
	{
		return (arr);
	}
	else if ((temp = env_path(buf)) != NULL)
	{	
		free(arr[0]);
		arr[0] = temp;
	}
	arr[i] = NULL;
	return (arr);
}
