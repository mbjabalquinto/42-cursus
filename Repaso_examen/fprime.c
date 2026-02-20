#include <stdio.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_atoi(char *str)
{
	int	i;
	int is_negative;
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
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * is_negative);
}

void	fprime(int num)
{
	int	i;
	int	first_number;

	i = 2;
	first_number = 1;
	if (num < 1)
		return ;
	if (num == 1)
	{
		printf("1");
		return ;
	}
	while (i <= num)
	{
		if (num % i == 0)
		{
			num = num / i;
			if (first_number == 0)
				printf("*");
			printf("%d", i);
			first_number = 0;
		}
		else 
			i++;
	}
}

int main(int argc, char **argv)
{
	int num;

	num = 0;
	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		fprime(num);
	}
	printf("\n");
	return (0);
}
