#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("arquivo.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erro ao abrir o arquivo");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

