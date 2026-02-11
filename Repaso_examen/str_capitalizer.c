#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c== '\t');
}

void	str_capitalizer(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	while(str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && i == 0)
			str[i] -= 32;
		else if ((str[i] >= 'a' && str[i] <= 'z') && is_space(str[i - 1]))
			str[i] -= 32;
		write (1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
		while(i < argc)
		{
			str_capitalizer(argv[i]);
			i++;
		}
	else
		write (1, "\n", 1);
	return (0);
}
