#include <stdio.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	rotstring(char *str)
{
	int	i;
	int start;
	int	end;

	i = 0;
	while (str[i] && is_space(str[i]))
		i++;
	if (!str[i])
		return ;
	start = i;
	while (str[i] && !is_space(str[i]))
		i++;
	end = i - 1;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (!str[i])
			break;
		while (str[i] && !is_space(str[i]))
		{
			printf("%c", str[i]);
			i++;
		}
		printf(" ");
	}
	while (start <= end)
	{
		printf("%c", str[start]);
		start++;
	}
}

int main(int argc, char **argv)
{
	if (argc > 1)
		rotstring(argv[1]);
	printf("\n");
	return (0);
}
