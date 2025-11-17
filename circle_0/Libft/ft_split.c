/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:50:47 by mjabalqu         #+#    #+#              */
/*   Updated: 2025/11/17 14:19:39 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_count_words(char const *s, char const *init_pos, char c)
{
	int	cont;

	cont = 0;
	while (*s != '\0')
	{
		if (*s != c && s == init_pos)
			cont++;
		else if (*s == c && *(s + 1) != c && *s != '\0')
			cont++;
		s++;
	}
	return (cont);
}

void	ft_first_word(char **end_word, char c, char const *s, char ***words)
{
	*end_word = ft_strchr(s, (int)c);
	if (*end_word)
	{
		**words = ft_substr(s, 0, (size_t)(*end_word - (char *)s));
		(*words)++;
	}
}

void	ft_last_word(char *last_pos, char ***words, char c)
{
	size_t	len;

	while (*last_pos == c)
		last_pos++;
	len = ft_strlen(last_pos);
	**words = ft_substr(last_pos, 0, len);
	(*words)++;
}

void	ft_separate_words(char const *init_pos, char const *s
		, char **words, char c)
{
	char	*start_word;
	char	*end_word;
	char	*last_pos;

	while (*s != '\0')
	{
		if (*s != c && s == init_pos)
			ft_first_word(&end_word, c, s, &words);
		else if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
		{
			s++;
			end_word = ft_strchr(s, (int)c);
			if (end_word)
			{
				start_word = (char *)s;
				*words = ft_substr(s, 0, (size_t)(end_word - start_word));
				words++;
				last_pos = end_word;
			}
		}
		s++;
	}
	if (s != last_pos + 1)
		ft_last_word(last_pos, &words, c);
	words = NULL;
}

char	**ft_split(char const *s, char c)
{
	char const	*init_pos;
	char		**words;
	int			cont;

	while (*s == c)
		s++;
	init_pos = s;
	cont = ft_count_words(s, init_pos, c);
	words = malloc((cont + 1) * sizeof(char *));
	s = init_pos;
	ft_separate_words(init_pos, s, words, c);
	return (words);
}
/*
int	main(void)
{
	char **p;

	p = ft_split(",,Hola,que,tal,,,esto,parece,que,,,ya,,,funciona", ',');
	while(*p != NULL)
	{
		printf("%s\n", *p);
		p++;
	}
	return (0);
}*/
