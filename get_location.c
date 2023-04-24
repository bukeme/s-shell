#include "main.h"

char *get_location(char *cmd)
{
	char *file_path, *path, *path_token;
	int path_length;
	struct stat buffer;

	path = getenv("PATH");
	path_token = strtok(path, ":");

	while (path_token)
	{
		path_length = strlen(path_token) + strlen(cmd) + 2;

		file_path = malloc(path_length * sizeof(char));

		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, cmd);
		strcat(file_path, "\0");

		if (stat(file_path, &buffer) == 0)
		{
			return (file_path);
		}
		else
		{
			path_token = strtok(NULL, ":");
			free(file_path);
		}
	}

	if (stat(cmd, &buffer) == 0)
	{
		return (cmd);
	}

	return (cmd);
}
