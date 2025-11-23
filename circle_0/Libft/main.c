/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:30:03 by mjabalqu         #+#    #+#              */
/*   Updated: 2025/11/23 13:22:45 by mjabalqu        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_test_striteri(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

int	main(void)
{
	char	str[4] = "hola";
	ft_striteri(str, ft_test_striteri);
	printf("%s\n", str);
	return (0);
}
