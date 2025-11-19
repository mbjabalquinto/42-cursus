/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:50:47 by mjabalqu         #+#    #+#              */
/*   Updated: 2025/11/18 17:43:27 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
int	ft_count_words(char const *s, char const *init_pos, char c);

void	ft_first_word(char **end_word, char c, char const *s, char ***cursor)
{
	size_t	len;
	char	*word;

	*end_word = ft_strchr(s, (int)c);
	if (*end_word)
	{
		
		word = ft_substr(s, 0, (size_t)(*end_word - (char *)s));
		if (word != NULL)
		{
			**cursor = word;
			(*cursor)++;
		}
		else
			return /* Tal vez esta función solo tendría que devolver el string o NULL y que separate_words se encarge del resto*/
	}
	else
	{
		len = ft_strlen(s);
		**cursor = ft_substr(s, 0, len);
		(*cursor)++;
		/* tal vez aquí pueda llamar a last_word ya que si no hay separadores es que es la primera y única palabra que es lo mismo que si fuera la última. */
	}
}

void	ft_last_word(char *last_pos, char ***cursor, char c)
{
	size_t	len;

	while (*last_pos == c)
		last_pos++;
	len = ft_strlen(last_pos);
	**cursor = ft_substr(last_pos, 0, len);
	(*cursor)++;
}

void	ft_separate_words(char const *init_pos, char const *s
		, char ***cursor, char c)
{
	char	*end_word;
	char	*last_pos;

	while (*s != '\0')
	{
		if (*s != c && s == init_pos)
		{
			ft_first_word(&end_word, c, s, &*cursor);
			last_pos = end_word;
		}
		else if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
		{
			s++;
			end_word = ft_strchr(s, (int)c);
			if (end_word)
			{
				**cursor = ft_substr(s, 0, (size_t)(end_word - (char *)s));
				(*cursor)++;
				last_pos = end_word;
			}
			else
				ft_last_word(last_pos, &*cursor, c);
		}
		s++;
	}
}

char	**ft_split(char const *s, char c)
{
	char const	*init_pos;
	char		**words;
	char		**cursor;
	int			cont;

	if (s == NULL)
		return (NULL);
	while (*s == c)
		s++;
	init_pos = s;
	cont = ft_count_words(s, init_pos, c);
	words = malloc((cont + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	if (cont > 0)
	{
		cursor = words;
		s = init_pos;
		ft_separate_words(init_pos, s, &cursor, c);
		*cursor = NULL;
	}
	return (words);
}
/*
int	main(void)
{
	char	**p;

	p = ft_split("      split       this for   me  !       ", ' ');
	while (*p != NULL)
	{
		printf("%s\n", *p);
		p++;
	}
	return (0);
}*/
