/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:10:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/09 11:04:04 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*strcopy;
	
	if (!src)
		return (NULL);
	i = 0;
	len = ft_strlen(src);
	strcopy = malloc((len + 1) * sizeof(char));
	if (!strcopy)
		return (NULL);
	while (src[i])
	{
		strcopy[i] = src[i];
		i++;
	}
	strcopy[i] = '\0';
	return (strcopy);
}

int	main(void)
{
	char *str;

	str = ft_strdup("Hello my friend Gemini! This is a copy of a given string.");
	printf("%s", str);
	free(str);
	return (0);
}