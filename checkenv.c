#include "main.h"

char *env_path(char *buf)
{
	char *path;
	char *token;
	char full_path[100];
	char *command;

	path = getenv("PATH");
	if (path == NULL)
	{
		return (NULL);
	}
	command = strdup(buf);
	token = strtok(path, ":");
	while (token != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);

		if (access(full_path, X_OK) == 0)
		{
			free(command);
			return (strdup(full_path));
		}
		token = strtok(NULL, ":");
	}
	free(command);
	return (NULL);
}
