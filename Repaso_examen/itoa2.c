#include <stdlib.h>
#include <stdio.h>

int	numlen(long number)
{
	int	i;

	i = 0;
	if (number < 0)
	{
		number = -number;
		i++;
	}
	while (number >= 10)
	{
		number = number / 10;
		i++;
	}
	return (i + 1);
}

char 	*ft_putnbr(char *s, long number, int len)
{
	int	i;

	if (number < 0)
	{
		s[0] = '-';
		number = -number;
	}
	i = len - 1;
	while (number >= 10)
	{
		s[i] = (number % 10) + '0';
		number = number / 10;
		i--;
	}
	s[i] = (number % 10) + '0';
	s[len + 1] = '\0';
	return (s);
}

char	*ft_itoa(int num)
{
	long 	number;
	int 	len;
	char 	*s;
	
	number = num;
	len = numlen(number);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s = ft_putnbr(s, number, len);
	return (s);
}

int	ft_atoi(char *str)
{
	int	i;
	int	is_negative;
	int	num;

	i = 0;
	is_negative = 0;
	if (!str)
		return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_negative = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (is_negative)
		num = -num;
	return (num);
}

int	main(int argc, char **argv)
{
	char	*s;
	int	num;
	
	if (argc != 2)
		return (1);
	num = ft_atoi(argv[1]);
	s = ft_itoa(num);
	printf("%s", s);
	free(s);
	s = NULL;
	return (0);
}
