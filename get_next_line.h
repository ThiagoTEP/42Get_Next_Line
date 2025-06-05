
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

int			ft_strlen(char *str);
char		*ft_strchr(char *s, char c);
char		*ft_strjoin(char *line, char *vault);
char		*get_next_line(int fd);

#endif