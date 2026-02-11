#include <stdio.h>
#include <stdlib.h>

int	num_len(int num)
{
	int	i;
	long	number;
	
	i = 0;
	number = num;
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

int	ft_atoi(char *str)
{
	int	num;
	int	i;
	int	is_negative;

	num = 0;
	i = 0;
	is_negative = 0;
	while (str[i] == ' ' || str[i] == '\t')
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

char	*ft_putnbr(char *n, int num, int len)
{
	int	i;
	long	number;

	number = num;
	if (number < 0)
	{
		n[0] = '-';
		number = -number;
	}
	i = len - 1;
	while (number >= 10)
	{
		n[i] = number % 10 + '0';
		number = number / 10;
		i--;
	}
	n[i] = number + '0';
	n[len] = '\0';
	return (n);
}

char	*ft_itoa(int num)
{
	int	len;
	char 	*n;

	len = num_len(num);
	n = malloc((len + 1) * sizeof(char));
	if (!n)
		return (NULL);
	n = ft_putnbr(n, num, len);
	return (n);
}	

int	main(int argc, char **argv)
{
	int	num;
	char	*n;

	num = 0;
	n = NULL;
	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		n = ft_itoa(num);
		printf("%s\n", n);
		free(n);
	}
	return (0);
}
