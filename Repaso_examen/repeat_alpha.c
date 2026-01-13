/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:10:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/07 19:47:31 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_alpha(char *str)
{
	int	i;
	int	cont;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			cont = str[i] - 96;
			while (cont--)
				write(1, &str[i], 1);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			cont = str[i] - 64;
			while (cont--)
				write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
int	main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}