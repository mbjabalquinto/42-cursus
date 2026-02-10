/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:53:40 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/02/10 14:50:44 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rostring(char *str)
{
	int	i;
	int	cont;
	int	more_words;
	int	space;
	int	start;

	cont = 0;
	space = 0;
	more_words = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	start = i;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		cont++;
		i++;
	}
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ')
		{
			write(1, &str[i], 1);
			more_words = 1;
		}
		else if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] != '\0' && str[i + 1] != ' ' && str[i + 1] != '\t')
		{
			write(1, " ", 1);
		}
		i++;
	}
	if (more_words == 1)
		write(1, " ", 1);
	while (cont > 0)
	{
		write(1, &str[start], 1);
		cont--;
		start++;
	}
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
			rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}
