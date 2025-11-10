/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:43:18 by mjabalqu          #+#    #+#             */
/*   Updated: 2025/11/10 14:11:06 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destiny;
	const unsigned char	*source;

	destiny = (unsigned char *) dest;
	source = (unsigned char *) src;
	i = 0;
	while (n--)
	{
		destiny[i] = source[i];
		i++;
	}
	return (dest);
}
