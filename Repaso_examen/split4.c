#include <stdio.h>
#include <stdlib.h>

int     is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	words_count(char *str)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while(str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (!str[i])
			break;
		words++;
		while (str[i] && !is_space(str[i]))
			i++;
	}
	return (words);
}

void	free_split(char **s, int j)
{
	while (j < 0)
	{
		j--;
		free(s[j]);
	}
	free(s);
	s = NULL;
}

char	**ft_split(char *str)
{
	int	i;
	int	j;
	int	start;
	int	end;
	int	words;
	int	index;
	char	**s;

	s = NULL;
	if (!str)
		return (NULL);
	words = words_count(str);
	s = malloc((words + 1) *sizeof(char *));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		index = 0;
		while (str[i] && is_space(str[i]))
			i++;
		if (!str[i])
			break;
		start = i;
		while (str[i] && !is_space(str[i]))
			i++;
		end = i - 1;
		s[j] = malloc((end - start + 2) * sizeof(char));
		if (!s[j])
		{
			free_split(s, j);
			return (NULL);
		}
		while (start <= end)
		{
			s[j][index] = str[start];
			start++;
			index++;
		}
		s[j][index] = '\0';
		j++;
	}
	s[j] = NULL;
	return (s);
}

int	main(int argc, char **argv)
{
	char	**s;
	int	i;
	
	s = NULL;
	i = 0;
	if (argc == 2)
	{
		s = ft_split(argv[1]);
		if (!*s)
			return (1);
		while(s[i])
		{
			printf("%s\n", s[i]);
			free(s[i]);
			i++;
		}
		free(s);
	}
	return (0);
}
