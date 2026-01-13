/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fist_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:42:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/07 18:10:50 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	first_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 &&  str[i] <= 13))
		i++;
	while (str[i] != '\0' && str[i] != 32 && !((str[i] >= 9 &&  str[i] <= 13)))
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		write(1, "\n", 1);
		return (1);
	}
	first_word(argv[1]);
	return (0);
}