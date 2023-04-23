#include "main.h"

void execmd(char **cmd)
{
	if (cmd)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
