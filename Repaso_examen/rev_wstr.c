/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:13:48 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/03/03 13:30:28 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)
{
	return(c == ' ' || c == '\t');
}

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
	int	end_word;
	int	len_str;
	int	first_word;
	
	first_word = 1;
	len_str = ft_strlen(str);
	i = len_str - 1;
	while (i >= 0)
	{
		while (i >= 0 && str[i] && is_space(str[i]))
			i--;	
		if (i < 0)
			break;
		end_word = i;
		while (i >= 0 && str[i] && !is_space(str[i]))
			i--;
		start_word = i + 1;
		if (first_word == 0)
			write(1, " ", 1);
		while (start_word <= end_word)
		{
			write(1, &str[start_word], 1);
			start_word++;
		}
		first_word = 0;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
