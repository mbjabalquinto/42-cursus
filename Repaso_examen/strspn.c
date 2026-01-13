/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strspn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:10:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/08 18:27:24 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	found = 0;
	while (s[i])
	{
		j = 0;
		while (accept[j])
		{	
			if (accept[j] == s[i])
			{
				found = 1;
				break;
			}
			j++;
		}
		if (found == 0)
			return (i);
		i++;
	}
	return (i);
}

int	main(void)
{
	size_t	cont;

	cont = ft_strspn("oaaaola", "aeiu");
	printf("%zu\n", cont);
	return (0);
}