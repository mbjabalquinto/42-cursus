/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:07:32 by mjabalqu          #+#    #+#             */
/*   Updated: 2025/11/12 12:41:56 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	size_t	len_s;
	size_t	len_to_cpy;

	i = 0;
	len_s = ft_strlen(s);
	if (start >= len_s)
	{
		sub_s = malloc(1);
		sub_s[0] = '\0';
		return (sub_s);
	}
	len_to_cpy = len_s - start;
	if (len_to_cpy > len)
		sub_s = malloc((len + 1) * sizeof(char));
	else
		sub_s = malloc((len_to_cpy + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		sub_s[i] = s[start];
		start++;
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
