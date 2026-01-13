/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:10:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/13 11:44:19 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char	binary;
	int				i;

	i = 7;
	while (i >= 0)
	{
		binary = (octet >> i) & 1; //traduce octal a binario y mueve al principio el bit que toca en cada ciclo del bucle.
		binary = binary + '0';		// Cambia todos los bits a 0 menos el primero (el que hemos movido) -> & 1.
		write(1, &binary, 1); // imprimimos el bit que hemos movido a la primera posicion. 
		i--;			// Solo podemos trabajar con el primer bit de la derecha asi que uno a uno lo vamos moviendo
	}					// al principio para volver a convertirlo a char e imprimirlo. Asi imprimimos los 0 y los 1.
}

int	main(void)
{
	unsigned char num;
	
	num = 2;
	print_bits(num);
	return (0);
}