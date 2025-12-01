/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:30:03 by mjabalqu         #+#    #+#              */
/*   Updated: 2025/12/01 19:15:30 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	toupper_wrapper(unsigned int i, char *c)
{
	(void)i;
	*c = ft_toupper(*c);
}

int	main(int argc, char **argv)
{	
	if (argc != 2)
	{
		printf("%s\n", "Argument error.");
		return (1);
	}
	ft_striteri(argv[1], toupper_wrapper);
	printf("%s\n", argv[1]);
	return (0);
}
