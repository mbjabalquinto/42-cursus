#include <stdio.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	get_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	return (- 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int 	is_negative;
	int	num;

	i = 0;
	is_negative = 1;
	num = 0;
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_negative = -1;
		i++;
	}
	while (str[i] && !is_space(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * is_negative);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	num;
	int	value;
	int	is_negative;
	
	i = 0;
	num = 0;
	is_negative = 1;
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_negative = -1;
		i++;
	}
	while (str[i] && !is_space(str[i]))
	{
		value = get_value(str[i]);
		if (value == -1 || value >= str_base)
			break;
		num = (num * str_base) + value;
		i++;
	}
	return (num * is_negative);
}

int	main(int argc, char **argv)
{
	int	num;
	int	str_base;

	str_base = 0;
	num = 0;
	if (argc == 3)
	{
		str_base = ft_atoi(argv[2]);
		num = ft_atoi_base(argv[1], str_base);
		printf("%d\n", num);
	}
	return (0);
}
