/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:17:06 by mjabalqu          #+#    #+#             */
/*   Updated: 2025/11/13 16:42:56 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	index;
	size_t	len;

	i = 0;
	index = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, (int)*s1) && index < len)
	{
		s1++;
		index++;
	}
	len = ft_strlen(s1);
	i = len - 1;
	while (ft_strchr(set, (int)s1[i]))
		i--;
	if (i < 0)
		return (ft_strdup(""));
	return (ft_substr(s1, 0, i + 1));
}
/*
int	main(void)
{
	printf("%s", ft_strtrim("abcdddabc", "abc"));
	return (0);
}*/
