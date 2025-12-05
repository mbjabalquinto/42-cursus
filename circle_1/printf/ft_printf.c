/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:42:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2025/12/04 19:28:11 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_printf(const char *param, ...)
{
	va_list	args;
	int	i;
	int	cont;
	int	result;

	va_start(args, param);
	i = 0;
	result = 0;
	if (!param)
		return (-1);
	while (param[i] != '\0')
	{
		cont = 0;
		if (param[i] != '%')
		{
			write(1, &param[i], 1);
			cont++;
		}
		else if (param[i] == '%' && param[i + 1] == '%')
		{
			write(1, &param[i], 1);
			cont++;
			i++;
		}
		else
		{
			i++;
			if (param[i] == 's')
				cont += ft_putstr(va_arg(args, char *));
			else if (param[i] == 'c')
				cont += ft_putchar((char)va_arg(args, int));
			else if (param[i] == 'd' || param [i] == 'i' || param [i] == 'u')
				cont += ft_putnbr(va_arg(args, unsigned int));
			else if (param[i] == 'p' || param[i] == 'x' || param[i] == 'X')
			{
				if (param[i] == 'p')
					cont += ft_putstr("0x");
				cont += ft_putnbr_base(va_arg(args, unsigned long), param[i]);
			}
		}	
		if (cont != -1)
			result += cont;
		else
			return (result);
		i++;
	}
	va_end(args);
	return (result);
}

