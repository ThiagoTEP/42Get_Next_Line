#include "get_next_line.h"

static char *read_into_buffer(int fd, char *buffer_r)
{
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read <= 0)
        return buffer_r;
    buffer[bytes_read] = '\0';
    return ft_strjoin(buffer_r, buffer);
}

static char *extract_line(char *buffer_r)
{
    int i = 0;
    char *line;

    if (!buffer_r || buffer_r[0] == '\0')
        return NULL;
    while (buffer_r[i] && buffer_r[i] != '\n')
        i++;
    if (buffer_r[i] == '\n')
        i++;
    line = ft_substr(buffer_r, 0, i);
    return line;
}

static char *update_buffer(char *buffer_r)
{
    int i = 0;
    char *new_buffer;

    while (buffer_r[i] && buffer_r[i] != '\n')
        i++;
    if (!buffer_r[i])
    {
        free(buffer_r);
        return NULL;
    }
    i++; // Skip newline
    new_buffer = ft_substr(buffer_r, i, ft_strlen(buffer_r) - i);
    free(buffer_r);
    return new_buffer;
}

static char *read_loop(int fd, char *buffer_r)
{
    ssize_t bytes_read = 1;

    while (!ft_strchr(buffer_r, '\n') && bytes_read > 0)
    {
        buffer_r = read_into_buffer(fd, buffer_r);
        if (!buffer_r)
            return NULL;
        bytes_read = ft_strlen(buffer_r);
    }
    return buffer_r;
}

char *get_next_line(int fd)
{
    static char *buffer_r;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    buffer_r = read_loop(fd, buffer_r);
    if (!buffer_r)
        return NULL;
    line = extract_line(buffer_r);
    buffer_r = update_buffer(buffer_r);
    return line;
}
