/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:10:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/13 16:31:31 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_union(char *s1, char *s2)
{
	int		i;
	char	used[256];

	i = 0;
	while (i <= 255)
	{
		used[i] = 0;
		i++;
	}
	i = 0;
	while (s1[i])
	{
		if (used[(unsigned char)s1[i]] == 0)
		{
			write (1, &s1[i], 1);
			used[(unsigned char)s1[i]] = 1;
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (used[(unsigned char)s2[i]] == 0)
		{
			write (1, &s2[i], 1);
			used[(unsigned char)s2[i]] = 1;
		}
		i++;
	}
}
int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}