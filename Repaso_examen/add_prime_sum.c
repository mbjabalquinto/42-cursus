/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:10:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/13 18:07:19 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	add_prime_sum(unsigned int num)
{
	unsigned int	n;
	unsigned int i;

	n = 0;
	while(num > 1)
	{
		i = num;
		while (i >= 1)
		{
			if (num % i == 0)
				n += i;
			i--;
		}
		num--;
	}
	return (n);
}
int	main(void)
{
	unsigned int	num;

	num = 5;
	num = add_prime_sum(num);
	printf("%d\n", num);
	return (0);
}