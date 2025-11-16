/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:43:17 by mjabalqu          #+#    #+#             */
/*   Updated: 2025/11/14 11:43:28 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_index;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	i = 0;
	dst_index = dst_len;
	while (dst_index < dstsize - 1 && src[i] != '\0')
	{
		dst[dst_index] = src[i];
		i++;
		dst_index++;
	}
	if (dstsize > 0)
		dst[dst_index] = '\0';
	return (src_len + dst_len);
}
/*
int	main(void)
{
	printf("%zu", ft_strlcat("pqrs", "abcdefghi", 10));
	return (0);
}*/
