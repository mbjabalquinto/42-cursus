/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:10:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/08 10:18:23 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	search_and_replace(char *str, char *original, char *sustitute)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == original[0])
			str[i] = sustitute[0];
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1)
			search_and_replace(argv[1], argv[2], argv[3]);
	}
	write(1, "\n", 1);
	return (0);
}