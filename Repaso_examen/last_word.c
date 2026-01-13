/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:10:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/09 14:24:55 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}
void	last_word(char *str)
{
	int	cont;
	int	len;

	cont = 0;
	len = ft_strlen(str);
	if (len == 0)
		return ;
	len--;
	while(len >= 0 && (str[len] == 32 || (str[len] >= 9 && str[len] <= 13)))
		len--;
	while (len >= 0 && str[len] != 32 && !(str[len] >= 9 && str[len] <= 13 ))
	{
		cont++;
		len--;
	}
	len++;
	while (cont > 0)
	{
		write(1, &str[len], 1);
		len++;
		cont --;
	}

}
int	main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}