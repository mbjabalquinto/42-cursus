/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:25:08 by mjabalqu         #+#    #+#              */
/*   Updated: 2025/11/21 11:04:29 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

int	ft_count_words(char const *s,  char c)
{
	int	cont;
	int	i;

	cont = 0;
	i = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c && i != 0 && s[i - 1] != c)
			cont++;
		i++;
	}
	if (s[i - 1] != c)
		cont++;
	return (cont);
}

char	**ft_get_complete_str(char const *s)
{
	char	**words;

	words = malloc(2 * sizeof(char *));
	if (!words)
		return (NULL);
	words[0] = ft_strdup(s);
	if (!words[0])
	{
		free(words);	
		return (NULL);
	}
	words[1] = NULL;
	return (words);
}

char	**ft_invalid_input()
{
	char	**words;

	words = malloc(1 * sizeof(char *));
	if (!words)
		return (NULL);
	words[0] = NULL;
	return (words);
}
/*
int	ft_first_word(char *str, char **words, int *j)
{
	if (str != NULL)
	{
		words[*j] = str;
		(*j)++;
	}
	else
	{
		ft_free_matrix(&words, *j);
		return (0);
	}
	return (1);
}

int	ft_other_words(char *str, char **words, int *j)
{
	if (str != NULL && str[0] != '\0')
	{
		words[*j] = str;
		(*j)++;
	}
	else if (str[0] != '\0')
	{
		ft_free_matrix(&words, *j);
		return (0);
	}	
}*/
