/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return _to_stack_A.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:16:21 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/29 16:12:24 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **stack_a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_node_max(*stack_a);
	if (biggest_node == *stack_a)
		ra(stack_a);
	else if ((*stack_a) -> next == biggest_node)
		rra(stack_a);
	if ((*stack_a) -> nbr > (*stack_a)->next->nbr)
		sa(stack_a);
}