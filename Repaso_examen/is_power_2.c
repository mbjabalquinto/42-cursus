/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:10:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/10 18:46:49 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n > 1)
	{
		if (n % 2 != 0)
			return (0);
		n = n / 2;
	}
	return (1);
}

int	main(void)
{
	int	num;
	int	result;

	num = 1;
	result = is_power_of_2(num);
	printf("%d", result);
	return (0);
}