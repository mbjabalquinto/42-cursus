/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:25:08 by mjabalqu         #+#    #+#              */
/*   Updated: 2025/11/19 16:05:16 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
