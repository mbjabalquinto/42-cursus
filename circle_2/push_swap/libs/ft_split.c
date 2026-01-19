/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:46:15 by mjabalqu         #+#    #+#              */
/*   Updated: 2025/11/26 17:13:58 by mjabalqu        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(const char *s, const char c)
{
	size_t	i;
	size_t	cont;

	i = 0;
	cont = 0;
	while (s[i] != '\0')
	{
		if (s[i++] != c && (s[i] == c || s[i] == '\0'))
			cont++;
	}
	return (cont);
}

static char	**free_all(char **str, int n)
{
	while (n > 0)
		free(str[--n]);
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	len;
	size_t	n;

	str = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	n = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && (int)len++ > -1)
				s++;
			str[n] = ft_substr(s - len, 0, len);
			if (!str[n])
				return (free_all(str, n));
			n++;
		}
		else
			s++;
	}
	str[n] = NULL;
	return (str);
}
