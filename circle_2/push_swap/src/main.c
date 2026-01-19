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

int	main	(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (1);
	while (argc > 1)
	{
		i = 0;
		while (argv[argc - 1][i])
		{
			if ((argv[argc - 1][i] == '+' || argv[argc - 1][i] == '-') && i != 0)
			{
				write(2, "Error\n", 6);
				return (1);
			}
			else if (!(argv[argc - 1][i] >= '0' && argv[argc - 1][i] <= '9'))
			{
				write(2, "Error\n", 6);
				return (1);
			}
			i++;
		}
		argc--;
	}
	return (0);
}