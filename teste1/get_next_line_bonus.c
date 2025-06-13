/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thevaris <thevaris@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:29:19 by thevaris          #+#    #+#             */
/*   Updated: 2025/06/11 12:12:32 by thevaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		free(line);
		if (!temp_line)
			return (NULL);
		line = temp_line;
		if (ft_strchr(buf, '\n') || bytes_read == 0)
			break ;
	}
	return (line);
}

static char	*ft_extract_line(char *joined)
{
	int		i;
	int		j;
	char	*final_line;

	i = 0;
	j = 0;
	while (joined[i] && joined[i] != '\n')
		i++;
	if (joined[i] == '\n')
		i++;
	final_line = (char *)malloc(i + 1);
	if (!final_line)
		return (NULL);
	while (j < i)
	{
		final_line[j] = joined[j];
		j++;
	}
	final_line[j] = '\0';
	return (final_line);
}

static char	*ft_loadline(char *buf, char *line)
{
	char	*joined;
	char	*final_line;

	joined = ft_strjoin(line, buf);
	free(line);
	if (!joined)
		return (NULL);
	final_line = ft_extract_line(joined);
	if (!final_line)
	{
		free(joined);
		return (NULL);
	}
	free(joined);
	ft_residual(buf);
	return (final_line);
}

char	*ft_process_buffer(char *buf, char *line, char **out)
{
	char	*tmp;

	*out = NULL;
	if (buf[0] && ft_strchr(buf, '\n'))
	{
		tmp = ft_loadline(buf, line);
		*out = tmp;
		return (NULL);
	}
	else if (buf[0])
	{
		tmp = ft_strjoin(line, buf);
		free(line);
		if (!tmp)
			return (NULL);
		buf[0] = '\0';
		return (tmp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[MAX_FD_SIZE][BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	tmp = ft_process_buffer(buf[fd], line, &ret);
	if (ret)
		return (ret);
	if (!tmp)
		return (NULL);
	line = tmp;
	line = ft_readloop(fd, line, buf[fd]);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (ft_loadline(buf[fd], line));
}
