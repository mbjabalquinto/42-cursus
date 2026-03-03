#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	num;
	int	is_negative;
	
	i = 0;
	is_negative = 0;
	num = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (!str[i])
			break;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				is_negative = 1;
			i++;
		}
		while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		{
			num = (num * 10) + str[i] - '0';
			i++;
		}
	}	
	if (is_negative)
		num = -num;
	return (num);
}

int	numlen(long number)
{
	int	i;

	i = 0;
	if (number < 0)
	{
		i++;
		number = -number;
	}
	while (number >= 10)
	{
		number = number / 10;
		i++;
	}
	return (i + 1);
}

char	*putnbr(long number, char *str, int num_len)
{
	int	i;
	int	j;

	i = 0;
	if (number < 0)
	{
		str[i] = '-';
		number = -number;
		i++;
	}
	j = num_len - 1;
	while (j >= i)
	{
		str[j] = (number % 10) + '0';
		number = number / 10; 
		j--;
	}
	str[num_len] = '\0';
	return (str);
}

char	*ft_itoa(int num)
{
	long	number;
	int	num_len;
	char	*str;
	
	number = num;
	num_len = numlen(number);
	str = malloc((num_len + 1) * sizeof(char));
	if (!str)
		return (NULL);	
	str = putnbr(number, str, num_len);
	return (str);
}

int	main(int argc, char **argv)
{
	int	num;
	char 	*str;
	
	num = 0;
	str = NULL;
	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		str = ft_itoa(num);	
	}
	printf("%s\n", str);
	free(str);
	return (0);
}
