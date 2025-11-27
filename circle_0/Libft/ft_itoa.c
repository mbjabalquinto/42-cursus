/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:42:40 by mjabalqu         #+#    #+#              */
/*   Updated: 2025/11/21 19:10:47 by mjabalqu        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_check_negative(long *num)
{
	if (*num < 0)
	{
		*num = -*num;
		return (1);
	}
	return (0);
}

static void	ft_insert_number(char **str, long num, int *index)
{
	if (num >= 10)
		ft_insert_number(str, num / 10, index);
	(*str)[*index] = (num % 10) + 48;
	(*index)++;
}

static char	*ft_get_memory(int len)
{
	char	*str;

	str = malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

static int	ft_intlen(long num)
{
	int	i;

	i = 0;
	while (num >= 10)
	{
		num = num / 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	long	num;
	int		is_negative;
	char	*str;
	int		len;
	int		index;

	num = n;
	index = 0;
	is_negative = ft_check_negative(&num);
	len = ft_intlen(num) + 1 + is_negative;
	str = ft_get_memory(len);
	if (str)
	{
		if (is_negative)
		{
			str[0] = '-';
			index = 1;
		}
		ft_insert_number(&str, num, &index);
		str[index] = '\0';
		return (str);
	}
	return (NULL);
}
