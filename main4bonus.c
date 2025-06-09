#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
	int fd1  = open("file1.txt", O_RDONLY);
	int fd2  = open("file2.txt", O_RDONLY);

	char *line1;
	char *line2;
	

	if (fd1 < 0 || fd2 < 0)
		return 1;

	while(1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);

		if (!line1 && !line2)
			break;

		if (line1)
		{
			printf("File: %s", line1);
			free(line1);
		}
		if (line2)
		{
			prinft("File2: %s", line2);
			free(line2);
		}
	}

	close(fd1);
	close(fd2);

	return 0;
}