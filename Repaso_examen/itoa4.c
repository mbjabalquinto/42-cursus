#include <stdlib.h>
#include <stdio.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_atoi(char *str)
{
	int	i;
	int	is_negative;
	int num;

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
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * is_negative);
}

int	get_len(long number)
{
	int	i;

	i = 0;
	if (number < 0)
	{
		number = -number;
		i++;
	}
	if (number == 0)
		i++;
	while (number > 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	long	number;
	int		len;
	char	*num;
	int		j;

	number = nbr;
	len = get_len(number);
	num = malloc((len + 1) * sizeof(char));
	if (!num)
		return (NULL);
	else if (number == 0)
		num[0] = '0';
	else if (number < 0)
	{
		num[0] = '-';
		number = -number;
	}
	j = len - 1;
	while (number > 0)
	{
		num[j] = (number % 10) + '0';
		number = number / 10;
		j--;
	}
	num[len] = '\0';
	return (num);
}

int main(int argc, char **argv)
{
	char	*str;
	int		number;

	str = 0;
	if (argc == 2)
	{	
		number = ft_atoi(argv[1]);
		str = ft_itoa(number);
		printf("%s\n", str);
	}
	return (0);
}
