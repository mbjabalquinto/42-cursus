/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:10:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/13 11:53:35 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char num)
{
	unsigned char	binary;
	int				i;

	i = 8;
	while (i--)
	{
		binary = (num >> i) & 1;
		binary = binary + '0';
		write(1, &binary, 1);
	}
}
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	reverse;
	int				i;

	reverse = 0;
	i = 8;
	while (i--)
	{
		reverse = reverse << 1;
		if(octet & 1)
			reverse = reverse | 1;
		octet = octet >> 1;
	}
	return (reverse);
}

int	main(void)
{
	unsigned char num;
		
	num = 5;
	print_bits(num);
	write(1, "\n", 1);
	num = reverse_bits(num);
	print_bits(num);	
	return (0);
}