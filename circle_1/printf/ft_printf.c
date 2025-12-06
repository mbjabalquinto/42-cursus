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

static int	check_errors(int check, va_list *args)
{
	if (check == -1)
		{
			va_end(*args);
			return (-1);
		}
	return (check);
}

static int	p_param(void *ptr, char param)
{
	int	check;

	check = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	check += ft_putstr("0x");
	check += ft_putnbr_base((unsigned long long)ptr, param);
	return (check);
}

static int	eval_format(char param, va_list args)
{
	int	check;

	check = 0;
	if (param == 0)
		return (-1);
	if (param == 's')
		check = ft_putstr(va_arg(args, char *));
	else if (param == 'c')
		check = ft_putchar((char)va_arg(args, int));
	else if (param == 'd' || param == 'i')
		check = ft_putnbr(va_arg(args, int));
	else if (param == 'u')
		check = ft_putnbr_base(
				(unsigned long long)va_arg(args, unsigned int), param);
	else if (param == 'p')
		check = p_param(va_arg(args, void *), param);
	else if (param == 'x' || param == 'X')
		check = ft_putnbr_base(
				(unsigned long long)va_arg(args, unsigned int), param);
	return (check);
}

int	ft_printf(const char *param, ...)
{
	va_list	args;
	int		i;
	int		check;
	int		result;

	if (!param)
		return (-1);
	va_start(args, param);
	i = 0;
	result = 0;
	while (param[i] != '\0')
	{
		if (param[i] != '%')
			check = write(1, &param[i], 1);
		else if (param[i] == '%' && param[i + 1] == '%')
			check = write(1, &param[i++], 1);
		else
			check = eval_format(param[++i], args);
		if (check_errors(check, &args) == -1)
			return (-1);
		result += check;
		i++;
	}
	va_end(args);
	return (result);
}
