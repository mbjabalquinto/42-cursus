/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:09:17 by mjabalqu          #+#    #+#             */
/*   Updated: 2025/12/11 12:54:34 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	buffer_len;
	char	*src;
	size_t	len_s1;

	if (!s2)
		return (NULL);
	if (!s1)
		len_s1 = 0;
	else
		len_s1 = ft_strlen(s1);
	buffer_len = len_s1 + ft_strlen(s2) + 1;
	src = malloc((buffer_len) * sizeof(char));
	if (!src)
		return (NULL);
	if (s1)
		ft_strlcpy(src, s1, buffer_len);
	else
		src[0] = '\0';
	ft_strlcat(src, s2, buffer_len);
	if (s1)
		free(s1);
	return (src);
}