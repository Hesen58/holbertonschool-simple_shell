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

	tok = strtok(buf, " \n\t");
	if (tok == NULL)
	{
		return (NULL);
	}
	arr = (char **)malloc(sizeof(char *) * 2048);
	for (k = 0; k < 250; k++)
		arr[k] = NULL;
	while (tok != NULL)
	{
		arr[i] = (char *)malloc(strlen(tok) + 1);
		strcpy(arr[i], tok);
		i++;
		tok = strtok(NULL, " \n\t");
	}
	arr[i] = NULL;
	return (arr);
}
