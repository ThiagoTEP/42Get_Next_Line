#include "get_next_line_bonus.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *vault, char c)
{
	int	i;

	i = 0;
	while (vault[i])
	{
		if (vault[i] == c)
			return (&vault[i]);
		i++;
	}
	if (c == '\0')
		return (&vault[i]);
	return (NULL);
}

char	*ft_strjoin_gnl(char *line, char *vault)
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
	joined_str = malloc(ft_strlen_gnl(line) + ft_strlen_gnl(vault) + 1);
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