/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:42:37 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/29 09:47:51 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack_node **stack_a, char *arg)
{
	int		i;
	char	**num;
	long	nbr;

	i = 0;
	num = ft_split(arg, ' ');
	while (num[i])
	{
		if (!check_errors(num[i]))
			return (free_split(num), free_stack(stack_a), false); 
		nbr = ft_atol(num[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (free_split(num), free_stack(stack_a), false);
		if (!check_nbr(*stack_a, nbr))
			return (free_split(num), free_stack(stack_a), false);
		if (!add_node(stack_a, nbr))
			return (free_split(num), free_stack(stack_a), false);
		i++;
	}
	free_split(num);
	return (true);
}
int	push_swap(t_stack_node **stack_a, t_stack_node **stack_b, char *arg)
{
	if (!init_stack(stack_a, arg))
		return (false);
	if (!sort_stacks(stack_a, stack_b))
		return (false);
	return (true);
}
