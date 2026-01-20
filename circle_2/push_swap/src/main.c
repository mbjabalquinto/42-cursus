/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:27:00 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/19 14:06:16 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(int nbr)
{
	
}

int	check_limits(char *num)
{
	long number;

	number = ft_atol(num);
	if (number > 2147483647 || number < -2147483648)
		return (0);
	return (1);
}

int	check_errors(char *num)
{
	int	i;
	
	i = 0;
	while (num[i])
	{
		if (num[i] == '+' || num[i] == '-')
		{
			if (i != 0)
				return (0);
		}
		else if (!(num[i] >= '0' && num[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	init_stack(char *arg)
{
	int		i;
	char	**num;
	int		nbr;

	i = 0;
	num = ft_split(arg);
	while (num[i])
	{
		if (!check_errors(num));
			return (0);
		if (!check_limits(num))
			return (0);
		nbr = ft_atoi(num);
		add_node(nbr);
		num++;
	}
	return (1);
}

int	main	(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		return (1);
	while (argc > 1)
	{
		if (!init_stack(argv[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
		argc--;
	}
	return (0);
}