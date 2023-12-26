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
	char *tok, bin[] = "/bin/", *temp = bin;
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
	if (i == 0)
	  {
		free(arr);
	  }
	if (buf[0] == '\n')
		return (NULL);
	temp = (char *)malloc(strlen(arr[0]) + strlen(bin) + 1);
	strcpy(temp, bin);
	strcat(temp, arr[0]);
	if (buf != NULL && stat(arr[0], &st) != 0 && stat(temp, &st) == 0)
	{
		free(arr[0]);
		arr[0] = temp;
	}
	else
		free(temp);
	arr[i] = NULL;
	return (arr);
}
