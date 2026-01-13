/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:10:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/08 11:27:20 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	alpha_mirror(char *str)
{
	int	pos;
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			pos = str[i] - 97;  // calculo la posición de la letra. las minus van del 97 al 122.
			str[i] = 97 + 25 - pos; // la letra opuesta se encuentra sumando a la posicion inicial el total de posiciones y restando la posicion del original.
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			pos = str[i] - 65;
			str[i] = 65 + 25 - pos;
		}
		write(1, &str[i], 1);
		i++;
	}
}

int	main	(int argc, char **argv)
{
	if (argc == 2)
		alpha_mirror(argv[1]);
	write(1, "\n", 1);
	return (0);
}