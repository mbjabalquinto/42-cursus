#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c== '\t');
}

void	str_capitalizer(char *str)
{
	int	i;
	int	first_word;

	first_word = 1;
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
		while (is_space(str[i]))
			i++;
		if (!str[i])
			break;
		if (first_word == 0)
			write(1, " ", 1);
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		while (str[i] && !is_space(str[i]))
		{
			write(1, &str[i], 1);
			i++;
		}
		first_word = 0;
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
