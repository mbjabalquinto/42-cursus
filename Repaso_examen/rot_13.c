/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:10:04 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/07 20:24:22 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rot_13(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{	
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i]<= 109)
				str[i] += 13;
			else
				str[i] -= 13;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (str[i]<= 77)
				str[i] += 13;
			else
				str[i] -= 13;
		}
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
int	main(int argc, char **argv)
{
	if (argc == 2)
		rot_13(argv[1]);
	else
		write(1, "\n", 1);
	return(0);
}