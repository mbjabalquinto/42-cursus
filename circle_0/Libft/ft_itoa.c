/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:42:40 by mjabalqu         #+#    #+#              */
/*   Updated: 2025/11/21 15:25:34 by mjabalqu        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

void	ft_insert_char(char num, char **str)
{
	int	len;

	len = ft_strlen(*str);
	(*str)[len - 1] = num;
}

void	ft_insert_number(char **str, long num, int is_negative)
{
	if (is_negative)
		(*str)[0] = '-';
	if (num >= 10)
		ft_insert_number(str, num / 10, is_negative);
	ft_insert_char((num % 10) + 48, str);
}

char 	*ft_get_memory(int len)
{
	char	*str;

	str = malloc(len + 1 * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

int	ft_intlen(long n)
{
	int	i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}
char	*ft_itoa(int n)
{
	long	num;
	int	is_negative;
	char	*str;
	int	len;

	is_negative = 0;
	num = n;
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	len = ft_intlen(n);
	str = ft_get_memory(len + is_negative);
	if (str)
	{
		ft_insert_number(&str, num, is_negative);
		str[len - 1] = '\0';
		return (str);
	}
	return (NULL); 
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		printf("%s", "Param error.");
	printf("%s\n", ft_itoa(ft_atoi(argv[1])));	
}
