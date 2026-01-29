/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return _to_stack_A.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:16:21 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/29 19:17:37 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_on_top(t_stack_node **stack_a)
{
	t_stack_node *node_min;

	set_current_position(*stack_a);
	node_min = find_node_min(*stack_a);
	prep_for_push(stack_a, node_min, 'a');
}

t_stack_node	*find_node_min(t_stack_node *stack_a)
{
	long	min;
	t_stack_node	*node_min;

	node_min = NULL;
	min = LONG_MAX;
	while (stack_a)
	{
		if (stack_a -> nbr < min)
		{	
			node_min = stack_a;
			min = stack_a -> nbr;
		}
		stack_a = stack_a -> next;
	}
	return (node_min);
}

void	set_target_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	long			best_match_index;
	t_stack_node	*current_a;
	t_stack_node	*current_b;
	
	current_b = *stack_b;
	while (current_b)
	{
		best_match_index = LONG_MAX;
		current_a = *stack_a;
		while (current_a)
		{
			if (current_a -> nbr < best_match_index && current_a -> nbr > current_b -> nbr)
			{	
				best_match_index = current_a -> nbr;
				current_b -> target_node = current_a;
			}
			current_a = current_a -> next;
		}
		if (best_match_index == LONG_MAX)
			current_b -> target_node = find_node_min(*stack_a);
		current_b = current_b -> next;
	}
}

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