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

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*check_base(char c)
{
	if (c == 'x' || c == 'p')
		return ("0123456789abcdef");
	else if (c == 'X')
		return ("0123456789ABCDEF");
	else if (c == 'u')
		return ("0123456789");
	return (NULL);
}

int	ft_putnbr_base(unsigned long long num, char c)
{
	char				*sbase;
	int					cont;
	int					check;
	unsigned long long	len;

	sbase = check_base(c);
	len = (unsigned long long)ft_strlen(sbase);
	check = 0;
	cont = 0;
	if (num >= len)
	{
		check = ft_putnbr_base(num / len, c);
		if (check == -1)
			return (-1);
		cont += check;
	}
	if (write(1, &sbase[num % len], 1) == -1)
		return (-1);
	return (++cont);
}
