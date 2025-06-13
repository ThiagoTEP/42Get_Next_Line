/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thevaris <thevaris@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:35:06 by thevaris          #+#    #+#             */
/*   Updated: 2025/06/11 11:36:48 by thevaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_residual(char *buf)
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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (NULL);
	while (s1 && s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (joined);
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
