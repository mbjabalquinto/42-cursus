/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:25:08 by mjabalqu         #+#    #+#              */
/*   Updated: 2025/11/18 17:43:34 by mjabalqu        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

void	ft_free_array()
{
	
}
int	ft_count_words(char const *s, char const *init_pos, char c)
{
	int	cont;

	cont = 0;
	if (s[0] == '\0')
		return (0);
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
