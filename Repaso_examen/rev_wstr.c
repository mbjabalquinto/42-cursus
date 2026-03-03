/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:13:48 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/02/10 17:25:41 by mjabalqu         ###   ########.fr       */
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

void	rev_wstr(char *str)
{
	int	str_len;
	int	word_len;

	str_len = ft_strlen(str) - 1;
	str = str + str_len;
	while (str_len > 0)
	{
		word_len = 0;
		while (*str && *str != ' ')
		{
			word_len++;
			str--;
		}
		str++;
		while (*str && *str != ' ')
		{
			write (1, &*str, 1);
			str++;
		}
		if (word_len > 0 && str_len > 0)
		{
			str = str - word_len - 2;
			str_len = word_len;
			if (str_len > 0)
				write (1, " ", 1);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}

