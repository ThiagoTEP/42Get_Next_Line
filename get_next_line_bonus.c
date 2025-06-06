#include "get_next_line_bonus.h"

static void	ft_residual(char *buf)
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
	while (j <= BUFFER_SIZE)
		buf[j++] = '\0';
}

static char	*ft_readloop(int fd, char *line, char *buf)
{
	int		bytes_read;

	while (1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (line)
				free(line);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		line = ft_strjoin(line, buf);
		if (!line)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (line);
}

static char	*ft_loadline(char *buf, char *line)
{
	int	i;

	i = 0;
	line = ft_strjoin(line, buf);
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
    	i++;
	line[i] = '\0',
	ft_residual(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[MAX_FD_SIZE][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	if (buf[fd][0] && ft_strchr(buf[fd], '\n'))
		return (ft_loadline(buf[fd], line));
	else if (buf[fd][0])
	{
		line = ft_strjoin_gnl(line, buf[fd]);
		if (!line)
			return (NULL);
	}
	line = ft_readloop(fd, line, buf[fd]);
	if (!line)
		return (NULL);
	return (ft_loadline(buf[fd], line));
}
