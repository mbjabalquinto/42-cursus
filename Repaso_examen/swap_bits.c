/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:10:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/13 12:34:43 by mjabalqu         ###   ########.fr       */
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
unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	swap;
	
	swap = (octet >> 4) | (octet << 4); // el operador OR compara cada valor. si comparas un valor x con 0, tomara x. Si lo comparas con 1 tomara 1.
	return (swap);						//sabiendo esto, desplazamos 4 posiciones en cada sentido y comparamos. Los 0 se macharan con los otros valores.
}

int	main(void)
{
	unsigned char num;
		
	num = 2;
	print_bits(num);
	write(1, "\n", 1);
	num = swap_bits(num);
	print_bits(num);	
	return (0);
}