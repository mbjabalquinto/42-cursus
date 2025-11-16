/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:43:18 by mjabalqu          #+#    #+#             */
/*   Updated: 2025/11/14 13:18:18 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*source;

	dst = (unsigned char *) dest;
	source = (unsigned char *) src;
	if (!dest && !src)
		return (dest);
	while (n--)
		*dst++ = *source++;
	return (dest);
}
