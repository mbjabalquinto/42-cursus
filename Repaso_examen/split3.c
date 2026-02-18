#include <stdlib.h>
#include <stdio.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	count_words(char *str)
{
	int	i;
	int	words;
	
	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (!str[i])
			break;
		while (str[i] && !is_space(str[i]))
			i++;
		words++;
	}
	return (words);
}

void	free_split(char **s, int i)
{
	while (i >= 0)
	{
		i--;
		free(s[i]);
	}
	free(s);
}

char	**ft_split(char *str)
{
	int	i;
	int	words;
	char 	**s;
	int	start_word;
	int	end_word;
	int	j;

	i = 0;
	words = count_words(str);
	s = malloc((words + 1) * sizeof(char *));
	if (!s)
		return (NULL);
	words = 0;
	while(str[i])
	{
		j = 0;
		while (str[i] && is_space(str[i]))
			i++;
		if (!str[i])
			break;
		start_word = i;
		while (str[i] && !is_space(str[i]))
			i++;
		end_word = i - 1;
		s[words] = malloc((end_word - start_word + 2) * sizeof(char));
		if (!s[words])
		{
			free_split(s, words);
			return (NULL);
		}
		while (start_word <= end_word)
		{
			s[words][j] = str[start_word];
			start_word++;
			j++;
		}
		s[words][j] = '\0';
		words++;
	}
	s[words] = NULL;
	return (s);
}

int	main(int argc, char **argv)
{
	char	**s;

	s = NULL;
	if (argc == 2)
		s = ft_split(argv[1]);
	if (!s)
		return (1);
	while (*s)
	{
		printf("%s\n", *s);
		s++;
	}
	return (0);
}
