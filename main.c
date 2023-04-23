#include "main.h"

int main(void)
{
	char *lineptr = NULL, *lineptr_copy, *token, **cmd_memory;
	size_t n;
	ssize_t nchar_read;
	int cmd_len, i = 0;
	const char *delim = " \n";

	while (1)
	{
		cmd_len = 0;
		printf("($) ");
		nchar_read = getline(&lineptr, &n, stdin);
		if (nchar_read == -1)
		{
			printf("Error from input");
			return (-1);
		}

		lineptr_copy = malloc(sizeof(char) * nchar_read);
		strcpy(lineptr_copy, lineptr);
		token = strtok(lineptr, delim);
		while (token)
		{
			token = strtok(NULL, delim);
			cmd_len++;
		}
		cmd_len++;

		cmd_memory = malloc(sizeof(char *) * cmd_len);
		if (cmd_memory == NULL)
		{
			perror("Malloc failed!");
			return (-1);
		}

		token = strtok(lineptr_copy, delim);
		i = 0;
		while (token)
		{
			cmd_memory[i] = malloc(sizeof(char) * sizeof(token));
			if (cmd_memory[i] == NULL)
			{
				perror("Malloc failed!");
				free(cmd_memory);
				return (-1);
			}
			strcpy(cmd_memory[i], token);
			i++;
			token = strtok(NULL, delim);
		}
		cmd_memory[i] = NULL;

		i = 0;
		execmd(cmd_memory);
		free(cmd_memory);
		free(lineptr_copy);
		free(lineptr);
	}
	return (0);
}
