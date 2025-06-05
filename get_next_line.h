
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(const char *s1, const char *s2);
char        *ft_substr(const char *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);

#endif