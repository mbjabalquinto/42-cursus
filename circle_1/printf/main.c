/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:00:25 by mjabalqu         #+#    #+#              */
/*   Updated: 2025/12/05 11:00:51 by mjabalqu        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	main(void)
{
	char *trampa = "hola %d mundo";

//	number = 5;
	printf("%s Original\n", trampa);
	printf("%i\n", ft_printf("%k Copia\n", "hola"));
	return (0);
}
