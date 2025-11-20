/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:50:47 by mjabalqu         #+#    #+#              */
/*   Updated: 2025/11/20 16:53:49 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
char    **ft_get_complete_str(char const *s);
int     ft_count_words(char const *s,  char c);

char	*ft_get_word(char const **s, char c)
{
	char	*word;
	char	*end_word;

	end_word = ft_strchr(*s, (int)c);
	if (end_word)
	{
		word = ft_substr(*s, 0, (size_t)(end_word - *s));
		if (word != NULL)
		{
			*s = end_word + 1;
			while (*s == c)
				(*s)++;
			return (word);
		}
	}
	return (NULL);
}

char	*ft_get_last_word(char const *s, char c)
{
	size_t	len;
	char	*word;
	char	*end_word;

	end_word = ft_strrchr(s, (int)c);
	if (end_word)
	{
		if (*(end_word + 1) != '\0')
		{
			end_word++;
			len = ft_strlen(end_word);
			word = ft_substr(end_word, 0, len);
			if (word == NULL)
				return (NULL);
			else
				return (word);
		}
		else
			return ("");
	}
	return ("");
}

int	ft_split_words(char const *s , char **words, char c, int num_words)
{
	char	*str;

	while (num_words > 0)
	{
		str = ft_get_word(&s, c, end_word);
		if (!str) //si no he podido obtener la palabra.



		
		if (s[i] != c && i == 0)
		{
			str = ft_get_word(s, c, i, first_word);
			if(!ft_first_word(str, words, &j))
				return (0);
		}
		else if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			first_word = 0;
			str = ft_get_word(s, c, i, first_word);
			if(!ft_other_words(s, words, &j))
				return (0);
		}
		i++;
	}
	str = ft_get_last_word(s, c);
	if (str != NULL && str[0] != '\0')
	{
		words[j] = str;
		j++;
	}
	else if (str == NULL)
	{
		ft_free_matrix(&words, j);
		return (0);
	}
	words[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**words;
	int			num_words;

	if (s == NULL || s[0] == '\0')
		return (ft_invalid_input());
	if (c == '\0')
		return (ft_get_complete_str(s));
	while (*s == c)
		s++;
	num_words = ft_count_words(s, c);
	words = malloc((num_words + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	if (!(num_words > 0 && ft_split_words(s, words, c, num_words)))
	{
		words[0] = NULL;
		return (words);
	}
	return (words);
}
/*
int	main(int argc, char *argv[])
int	main(void)
{
	char	**p;

	if (argc != 3)
	{
		printf("%s\n", "Error: not the right amount of arguments.");
		return (1);
	}
	p = ft_split("aa,bbb", ',');
	p = ft_split((char const *)argv[1], *argv[2]);
	if (p == NULL)
		return (1);
	while (*p != NULL)
	{
		printf("%s\n", *p);
		p++;
	}
	return (0);
}*/
