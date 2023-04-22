#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char *lineptr;
	size_t n;
	ssize_t nchar_read;

	printf("($) ");
	nchar_read = getline(&lineptr, &n, stdin);
	if (nchar_read == -1)
	{
		perror("Error from input");
		return (-1);
	}
	printf("%s", lineptr);
	return (0);
}
