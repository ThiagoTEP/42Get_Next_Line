
#include "get_next_line.h"

void	ft_residual(char *buf)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	while (buf[i])
		buf[j++] = buf[i++];
	while (j < BUFFER_SIZE)
		buf[j++] = '\0';
}

char	*ft_readloop(int fd, char *line, char *buf)
{
	char	*new_line;
	int		bytes_read;

	new_line = line;
	ft_residual(buf);
	while (1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (line)
				free(line);
			ft_residual(buf);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		new_line = ft_strjoin(new_line, buf);
		if (!new_line)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
		ft_residual(buf);
	}
	return (new_line);
}

char	*ft_loadline(char *buf, char *line)
{
	int	i;

	i = 0;
	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	line = ft_strjoin(line, buf);
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
    	line[i + 1] = '\0';
	ft_residual(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buf[0] && ft_strchr(buf, '\n'))
		return (ft_loadline(buf, line));
	if (buf[0])
	{
		line = ft_strjoin(line, buf);
		if (!line)
			return (NULL);
	}
	line = ft_readloop(fd, line, buf);
	if (!line)
		return (NULL);
	line = ft_loadline(buf, line);
	if (!line)
		return (NULL);
	return (line);
}

/*
#include <stdio.h>
#include <fcntl.h>
int	main()
{
	int	fd;
	char *line;

	fd = open("41_with_nl", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}

	close(fd);
}
*/

