#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	rotstring(char *str)
{
	int	first_word;
	int	i;
	int	start_word;
	int	end_word;

	i = 0;
	first_word = 1;
	while (str[i] && is_space(str[i]))
		i++;
	start_word = i;
	while (str[i] && !is_space(str[i]))
		i++;
	end_word = i - 1;
	while(str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (!str[i])
			break;
		if (first_word == 0)
			write (1, " ", 1);
		while (str[i] && !is_space(str[i]))
		{
			write (1, &str[i], 1);
			i++;
		}
		first_word = 0;
	}
	if (first_word == 0)
		write (1, " ", 1);
	while (start_word <= end_word)
	{
		write(1, &str[start_word], 1);
		start_word++;	
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		rotstring(argv[1]);
	write(1, "\n", 1);
	return (0);
}
