/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:46:36 by mjabalqu          #+#    #+#             */
/*   Updated: 2025/11/12 17:25:42 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	buffer_len;
	char	*src;

	if (!s1 || !s2)
		return (NULL);
	buffer_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	src = malloc((buffer_len) * sizeof(char));
	if (!src)
		return (NULL);
	ft_strlcpy(src, s1, buffer_len);
	ft_strlcat(src, s2, buffer_len);
	return (src);
}
