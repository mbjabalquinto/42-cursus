/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizz_buzz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:10:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/07 18:36:56 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int	i)
{
	char	num;

	if (i >= 10)
		putnbr(i / 10);
	num = (i % 10) + '0';
	write (1, &num, 1);
}

void	fizz_buzz(void)
{
	int		i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz\n", 9);
		else if (i % 3 == 0)
			write (1, "fizz\n", 5);
		else if (i % 5 == 0)
			write (1, "buzz\n", 5);
		else
		{
			putnbr(i);
			write (1, "\n", 1);
		}
		i++;
	}
}

int	main(void)
{
	fizz_buzz();
	return (0);
}