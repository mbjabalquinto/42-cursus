/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:07:32 by mjabalqu          #+#    #+#             */
/*   Updated: 2025/11/12 15:41:13 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	sub_s = malloc((len + 1) * sizeof(char));
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
