#include <stdio.h>
#include <stdlib.h>

int	count_words(char *str)
{
	int	words;

	if (!str)
		return (0);
	words = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && (*str == ' ' || *str == '\t'))
			str++;
		if (*str != '\0')
			words++;
		while (*str != '\0' && (*str != ' ' && *str != '\t'))
			str++;
	}
	return (words);
}

void	copystr(char **s, char *str)
{
	int	i;

	i = 0;
	if (!s || !str)
		return ;
	while (*str != ' ' && *str != '\0')
	{
		(*s)[i] = *str;
		str++;
		i++;
	}
	(*s)[i] = '\0';
}

void	free_split(char ***s, int i)
{
	while (i >= 0)
	{
		free((*s)[i]);
		i--;		
	}
	free(*s);
	*s = NULL;
}

char	**ft_split(char *str)
{
	char 	**s;
	int	len_word;
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	s = malloc((count_words(str) + 1) * (sizeof (char *)));
	if (!s)
		return (NULL);
	while (*str != '\0')
	{
		while (*str != '\0' && (*str == ' ' || *str == '\t'))
			str++;
		if (*str == '\0')
			break;
		len_word = 0;
		while (*str != ' ' && *str != '\0')
		{
			len_word++;
			str++;
		}
		s[i] = malloc((len_word + 1) * (sizeof(char)));
		if (!s[i])
		{
			free_split(&s, i);
			return (NULL);
		}
		copystr(&s[i], str - len_word);
		while (*str == '\t' || *str == ' ')	
			str++;
		i++;
	}
	s[i] = NULL;
	return (s);
}

int	main(int argc, char **argv)
{
	char	**str;
	int	i;
	
	i = 0;
	str = NULL;
	if (argc == 2)
		str = ft_split(argv[1]);
	while (str[i] != NULL)
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (0);	
}
