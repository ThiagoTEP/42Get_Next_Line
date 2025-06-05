#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char *line, char *vault)
{
	int		i;
	int		j;
	char	*joined_str;

	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	i = -1;
	j = -1;
	joined_str = malloc(ft_strlen(line) + ft_strlen(vault) + 1);
	if (!joined_str)
		return (NULL);
	while (line[++i])
		joined_str[i] = line[i];
	while (vault[++j])
		joined_str[i + j] = vault[j];
	joined_str[i + j] = '\0';
	free(line);
	return (joined_str);
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