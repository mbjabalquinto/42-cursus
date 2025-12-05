/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:17:14 by mjabalqu          #+#    #+#             */
/*   Updated: 2025/12/04 18:25:02 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_base(unsigned long num, char c)
{
	char	*sbase;
	int		cont;

	if (c == 'x')
		sbase = "0123456789abcdef";
	else
		sbase = "0123456789ABCDEF";
	cont = 1;
	if (!num)
		return (-1);
	if (num >= 16)
	{
		cont += ft_putnbr_base(num / 16, c);
	}
	write(1, &sbase[num % 16], 1);
	return (cont);
}

