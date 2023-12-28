#include "main.h"
/**
 * cut_string - Create new array with strtok
 * @buf: user input.
 *
 * Return: 2d array.
 */

char **cut_string(char *buf)
{
	char *tok, **arr;
	int i = 0;
	int k;

	tok = strtok(buf, " \n\t");
	if (tok == NULL)
	{
		return (NULL);
	}
	arr = (char **)malloc(sizeof(char *) * 250);
	for (k = 0; k < 250; k++)
		arr[k] = NULL;
	while (tok != NULL)
	{
		arr[i] = (char *)malloc(strlen(tok) + 1);
		strcpy(arr[i], tok);
		arr[i][strlen(tok)] = '\0';
		i++;
		tok = strtok(NULL, " \n\t");
	}
	arr[i] = NULL;
	free(buf);
	return (arr);
}
