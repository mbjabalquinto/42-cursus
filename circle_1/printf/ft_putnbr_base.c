/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:17:14 by mjabalqu          #+#    #+#             */
/*   Updated: 2025/12/04 14:55:48 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"


int	ft_putnbr_base(unsigned long num)
{
	int	cont;
	int	result;
	char sbase[] = "0123456789abcdef";

	cont = 1;
	result = 0;
	if (!num)
		return (-1);
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		cont++;
	}
	if (num >= 16)
	{
		cont += ft_putnbr_base(num / 16);
	}
	write(1, &sbase[num % 16], 1);
	return (cont);
}

