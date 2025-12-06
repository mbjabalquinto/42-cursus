/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:39:00 by mjabalqu          #+#    #+#             */
/*   Updated: 2025/09/25 09:55:51 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long	num;
	int		cont;
	char	result;

	num = nb;
	cont = 1;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		cont++;
	}
	if (num >= 10)
		cont += ft_putnbr(num / 10);
	result = ((num % 10) + '0');
	write(1, &result, 1);
	return (cont);
}
