#include "get_next_line.h"

static void	ft_residual(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	while (buf[i])
		buf[j++] = buf[i++];
	while (j < BUFFER_SIZE + 1)
		buf[j++] = '\0';
}

static char	*ft_readloop(int fd, char *line, char *buf)
{
	int		bytes_read;
	char	*temp_line;

	while (1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(line);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		temp_line = ft_strjoin(line, buf);
		free(line); // ✅ sempre liberar a antiga
		if (!temp_line)
			return (NULL);
		line = temp_line;
		if (ft_strchr(buf, '\n') || bytes_read == 0)
			break ;
	}
	return (line);
}

static char	*ft_loadline(char *buf, char *line)
{
	int		i = 0;
	int		j = 0;
	char	*joined;
	char	*final_line;

	joined = ft_strjoin(line, buf);
	free(line); // ✅ libera o line original
	if (!joined)
		return (NULL);
	while (joined[i] && joined[i] != '\n')
		i++;
	if (joined[i] == '\n')
		i++;
	final_line = (char *)malloc(i + 1);
	if (!final_line)
	{
		free(joined);
		return (NULL);
	}
	while (j < i)
	{
		final_line[j] = joined[j];
		j++;
	}
	final_line[j] = '\0';
	free(joined); // ✅ libera a string concatenada
	ft_residual(buf);
	return (final_line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (buf[0] && ft_strchr(buf, '\n'))
	{
		tmp = ft_loadline(buf, line);
		return (tmp); // line já foi free() em ft_loadline
	}
	else if (buf[0])
	{
		tmp = ft_strjoin(line, buf);
		free(line);
		if (!tmp)
			return (NULL);
		line = tmp;
		buf[0] = '\0';
	}
	line = ft_readloop(fd, line, buf);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (ft_loadline(buf, line));
}

