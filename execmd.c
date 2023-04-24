#include "main.h"

void execmd(char **cmd, char **argv)
{
	if (cmd)
	{
		if (execve(get_location(cmd[0]), cmd, NULL) == -1)
		{
			perror(argv[0]);
		}
	}
}
