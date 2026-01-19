/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:35:36 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/14 16:53:53 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_char(char c, int n)
{
	char	base[16] = "0123456789abcdef";
	int	i;

	i = 0;
	if (c >= 'A' && c <= 'F')
		c = c + 32;
	while (i < n)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	is_negative;
	int	num;
	int	value;

	i = 0;
	num = 0;
	is_negative = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negative = 1;
		i++;
	}
	value = check_char(str[i], str_base);
	while ( value >= 0)
	{
		num = (num * str_base) + value;
		i++;
		value = check_char(str[i], str_base);
	}
	if (is_negative)
		num = -num;
	return (num);
}

int	main(void)
{
	int	num;

	num = ft_atoi_base("1234ab", 12);
	printf("%d\n", num);
	return (0);
}
