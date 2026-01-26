/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:32:34 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/26 13:48:07 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	long	num;
	int		sign;

	sign = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		if (num > 2147483648) // max int value without sign.
			return (2147483649);  //return a very big num to force the error when i check de result returned.
		i++;
	}
	return (num * sign);
}
