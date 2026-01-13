/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strpbrk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:10:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/09 11:37:58 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	const char	*s2temp;
	
	while (*s1)
	{
		s2temp = s2;
		while (*s2temp)
		{
			if (*s1 == *s2temp)
				return ((char *)s1);
			s2temp++;
		}
		s1++;
	}
	return (NULL);
}
int	main(void)
{
	char	*str;

	str = ft_strpbrk("oaaaola", "eiu");
	printf("%s\n", str);
	return (0);
}