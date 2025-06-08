#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static char *init_s1(char *s1)
{
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			free(s1);
			return NULL;
		s1[0] = '\0';
	}
	return s1;
}

char *ft_strjoin(char *s1, const char *s2)
{
	size_t	i = 0, j = 0;
	char	*joined;

	s1 = init_s1(s1);
	if (!s1)
		return NULL;
	joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
	{
		free(s1);
		return NULL;
	}
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	free(s1);
	return joined;
}



/*
void print_str_or_null(char *str) {
    if (str)
        printf("%s\n", str);
    else
        printf("(null)\n");
}


#include <stdio.h>
int main(void)
{
	printf("%zu\n",ft_strlen("teste"));
	printf("%zu\n",ft_strlen("ola"));
	printf("%zu\n",ft_strlen(""));

    puts("\nFT_STRCHR\n");

    char *x = "teste de string";
	char *result = ft_strchr(x, 'i');
	
	printf("%c\n", *result);
	printf("%s\n", result);

    puts("\nFT_STRJOIN\n")

    print_str_or_null(ft_strjoin("lib", "ft"));
	
	return 0;
	
	return(0);
}*/
