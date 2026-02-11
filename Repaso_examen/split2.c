#include <stdlib.h>
#include <stdio.h>

int	count_words(char *str)
{
	int	words;

	words = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && (*str == ' ' || *str == '\t'))
			str++;
		if (*str != '\0')
			words++;
		while (*str != '\0' && *str != ' ' && *str != '\t')
			str++;
	}
	return (words);
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

char	*copystr(char *dest, char *source, int	end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str)
{
	char	**s;
	int	word_count;
	int	word_len;
	int 	i;

	word_count = count_words(str);
	s = malloc((word_count + 1) * sizeof(char *));
	if (!s)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && (*str == ' ' || *str == '\t'))
			str++;
		if (*str == '\0')
			break;
		word_len = 0;
		while (*str != '\0' && *str != ' ' && *str != '\t')
		{
			word_len++;
			str++;
		}
		s[i] = malloc((word_len + 1) * sizeof(char));
		if (!s[i])
		{
			free_split(&s, i - 1);
			return (NULL);
		}	
		s[i] = copystr(s[i], str - word_len, word_len);
		i++;
	}
	s[i] = NULL;
	return (s);
}

int	main(int argc, char **argv)
{
	char	**s;
	int	i;
	
	s = NULL;
	i = 0;
	if (argc == 2)
		s = ft_split(argv[1]);
	while (s[i])
	{
		printf("%s\n", s[i]);
		i++;
	}
	return (0);
}
