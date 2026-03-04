#include <stdio.h>
#include <stdlib.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	word_count(char *str)
{
	int	i;
	int cont;

	i = 0;
	cont = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (!str[i])
			break;
		cont ++;
		while (str[i] && !is_space(str[i]))
			i++;
	}
	return (cont);
}

void	free_split(char **s, int j)
{
	while (j > 0)
	{
		j--;
		free(s[j]);
	}
	free(s);
}

char **ft_split(char *str)
{
	char **s;
	int i;
	int j;
	int start;
	int	end;
	int	words;
	int index;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	s = NULL;
	words = word_count(str);
	s = malloc((words + 1) * sizeof(char *));
	if (!s)
		return (NULL);
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
			index++;
			start++;
		}
		s[j][index] = '\0';
		j++;
	}
	s[j] = NULL;
	return (s);
}

int	main(int argc, char **argv)
{
	char **str;
	int	i;
	
	str = NULL;
	i = 0;
	if (argc == 2)
	{
		str = ft_split(argv[1]);
		while (str[i])
		{
			printf("%s\n", str[i]);
			i++;
		}
	}
	else
		printf(" ");
	return (0);
}
