/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:10:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/08 12:47:33 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int num)
{
	char	digit;

	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	digit = (num % 10) + '0';
	write(1, &digit, 1);
}

int	ft_atoi(char *str)
{
	int	number;
	int	i;

	number = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '-')
			number = (number * 10) + str[i] - '0';
		i++;
	}
	if (str[0] == '-')
		number = -number;
	return (number);
}

void	do_op(int n1, char op, int n2)
{
	int	result;

	result = 0;
	if (op == '+')
		result = n1 + n2;
	else if (op == '-')
		result = n1 - n2;
	else if (op == '*')
		result = n1 * n2;
	else if (op == '/' && n2 != 0)
		result = n1 / n2;
	else if (op == '%' && n2 != 0)
		result = n1 % n2;
	ft_putnbr(result);
}

int	main	(int argc, char **argv)
{
	if (argc == 4)
		do_op(ft_atoi(argv[1]), argv[2][0], ft_atoi(argv[3]));
	write(1, "\n", 1);
	return (0);
}