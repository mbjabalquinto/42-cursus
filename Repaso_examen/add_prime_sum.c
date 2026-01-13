/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:10:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/13 18:47:36 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_prime(int num)
{
	int	i;
	
	i = num - 1;
	while (i > 1)
	{
		if (num % i == 0)
			return (0);
		i--;
	}
	return (1);
}

int	add_prime_sum(unsigned int num)
{
	unsigned int	n;

	n = 0;
	while(num > 1)
	{
		if (check_prime(num))
			n += num;
		num--;
	}
	return (n);
}
int	main(void)
{
	unsigned int	num;

	num = 7;
	num = add_prime_sum(num);
	printf("%d\n", num);
	return (0);
}