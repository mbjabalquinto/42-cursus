#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	rev_wstr(char *str)
{
	int	start;
	int end;
	int len;
	int first_word;

	first_word = 1;
	len = ft_strlen(str) - 1;
	while (len >= 0)
	{
		end = len;
		while (len >= 0 && !is_space(str[len]))
			len--;
		start = len + 1;
		if (first_word == 0)
			printf(" ");
		first_word = 0;
		while (start <= end)
		{
			printf("%c", str[start]);
			start++;
		}
		len--;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	printf("\n");
	return (0);
}
