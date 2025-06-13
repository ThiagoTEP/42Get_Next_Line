#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main (int argc, char **argv)
{
	int fd;
	char *line;
	int i;
	
	if (argc < 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return 1;
	}

	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			perror(argv[i]);
			i++;
			return 1;
		}

		i = 1;
		while((line = get_next_line(fd)) != NULL)
		{
			printf("Line %d: %s", i++, line);
			free(line);
		}

		close(fd);
		i++;
	}

	return 0;
}