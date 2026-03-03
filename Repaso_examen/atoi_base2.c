int	get_value(char c)
{
	int	value;
	
	value = 0;
	if (c >= '0' && c <= '9')
		return (value = c - '0');
	else if (c >= 'a' && c <= 'f')
		return (value = (c - 'a') + 10);
	else if (c >= 'A' && c <= 'F')
		return (value = (c - 'A') + 10);
	return (-1);
}

int	atoi_base(char *str, int str_base)
{
	int	i;
	int	is_negative;
	int	value;
	int	number;
	
	i = 0;
	is_negative = 0;
	number = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negative = 1;

		i++;
	}
	while (str[i])
	{
		value = get_value(str[i]);
		if (value == -1 ||  value >= str_base)
			break;
		number = (number * str_base) + value;
		i++;
	}
	if (is_negative)
		number = -number;
	return (number);
}

int	main(int argc, char **argv)
{
	int	num;

	num = 0;	
	if (argc == 3)
		num = atoi_base(argv[1], argv[2]);
	printf("%d\n", num);
	return (0);
}
