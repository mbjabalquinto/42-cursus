/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:41:47 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/14 12:48:04 by mjabalqu         ###   ########.fr       */
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

void	epur_str(char *str)
{
	int	i;
	int	len;
	int	space_found;

	i = 0;
	space_found = 0;
	len = ft_strlen(str) - 1;
	if (len < 0)
		return ;
	while (str[len] == 32 || (str[len] >= 9 && str[len] <= 13))
		len--;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (i <= len)
	{
		if (str[i] != 32 && !(str[i] >= 9 && str[i] <= 13))
		{
			write(1, &str[i], 1);
			space_found = 0;
		}
		else if ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) && space_found == 0)
		{
			write(1, " ", 1);
			space_found = 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
