/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:50:47 by mjabalqu         #+#    #+#              */
/*   Updated: 2025/11/16 10:37:34 by mjabalqu        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_count_words(char const *s, char const *init_pos, char c)
{
	int	cont;
	
	cont = 0;
	while (*s == c)
		s++;
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

void	ft_separate_words(char const *init_pos, char const *s, char **words, char c)
{	
	char	*start_word;
	char	*end_word;
	
	while (*s == c)
		s++;
	while (*s != '\0')
	{		
		if (*s != c && s == init_pos)
		{
			end_word = ft_strchr(s, (int)c) - 1;
			if (end_word)
			{	
				start_word = (char *)s;
				*words = ft_substr(s, (unsigned int)(start_word - init_pos), (size_t)(end_word - start_word));
				words++;
			}
		}
		else if (*s == c && *(s + 1) != c && *s != '\0')
			if (end_word)
			{	
				start_word = (char *)s;
				*words = ft_substr(s, (unsigned int)(start_word - init_pos), (size_t)(end_word - start_word));
				words++;
			}
		s++;
	}
	*words = NULL;
}

char	**ft_split(char const *s, char c)
{
	char const	*init_pos;
	char		**words;
	int		cont;

	init_pos = s;
	cont = ft_count_words(s, init_pos, c);	
	words = malloc((cont + 1) * sizeof(char *));
	s = init_pos;
	ft_separate_words(init_pos, s, words, c);
	return (words);
}

int	main(void)
{
	char **p;

	p = ft_split(",,Hola,que,tal", ',');
	while(*p != NULL)
	{
		printf("%s\n", *p);
		p++;
	}
	return (0);
}
