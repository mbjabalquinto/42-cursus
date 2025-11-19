/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:50:47 by mjabalqu         #+#    #+#              */
/*   Updated: 2025/11/19 19:26:41 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
int	ft_count_words(char const *s, char c);

char	*ft_get_word(char const *s, char c, int i)
{
	size_t		len;
	char		*word;
	char		*end_word;
	char const	*p;

	p = &s[i];
	end_word = ft_strchr(p, (int)c);
	if (end_word)
	{
		
		word = ft_substr(p, 0, (size_t)(end_word - p));
		if (word != NULL)
			return (word);
	}
	else
	{
		len = ft_strlen(s);
		word = ft_substr(s, 0, len);
		if (word != NULL)
			return (word);
		
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

int	ft_separate_words(char const *s , char **words, char c)
{
	char	*str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && i == 0)
		{
			str = ft_get_word(s, c, i);
			if (str != NULL)
			{
				words[j] = str;
				j++;
			}
			else
			{
				ft_free_matrix(&words, j);
				return (0);
			}
		}
		else if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			i++;
			str = ft_get_word(s, c, i);
			if (str != NULL)
			{
				words[j] = str;
				j++;
			}
			else
			{
				ft_free_matrix(&words, j);
				return (0);
			}
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

	if (s == NULL)
		return (NULL);
	while (*s == c)
		s++;
	num_words = ft_count_words(s, c);
	words = malloc((num_words + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	if (!(num_words > 0 && ft_separate_words(s, words, c)))
	{
		words[0] = NULL;
		return (words);
	}
	return (words);
}

int	main(int argc, char *argv[])
{
	char	**p;

	if (argc != 3)
	{
		printf("%s\n", "Error: not the right amount of arguments.");
		return (1);
	}
	p = ft_split((char const *)argv[1], *argv[2]);
	while (*p != NULL)
	{
		printf("%s\n", *p);
		p++;
	}
	return (0);
}
