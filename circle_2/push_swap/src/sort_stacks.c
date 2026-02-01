/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:52:30 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/02/01 15:20:53 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_stacks(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a, TRUE);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a, TRUE);
	while (len_a > 3 && !stack_sorted(*stack_a))
	{
		set_nodes(stack_a, stack_b);
		move_cheapest(stack_a, stack_b);
		len_a--;
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		set_current_position(*stack_a);
		set_current_position(*stack_b);
		set_target_b(stack_a, stack_b);
		prep_for_push(stack_a, (*stack_b)-> target_node, 'a');
		pa(stack_a, stack_b, TRUE);
	}
	min_on_top(stack_a);
	return (TRUE);
}

void	sort_three(t_stack_node **stack_a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_node_max(*stack_a);
	if (biggest_node == *stack_a)
		ra(stack_a, TRUE);
	else if ((*stack_a)-> next == biggest_node)
		rra(stack_a, TRUE);
	if ((*stack_a)-> nbr > (*stack_a)->next->nbr)
		sa(stack_a, TRUE);
}
